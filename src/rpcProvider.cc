#include "rpcProvider.h"
#include "rpcApplication.h"
#include "rpcHead.pb.h"

#include <glog/logging.h>
#include <google/protobuf/message.h>
#include <google/protobuf/stubs/callback.h>

void rpcProvider::notifyService(google::protobuf::Service *service) {
  serviceInfo service_info;
  auto desc = service->GetDescriptor();
  auto service_name = desc->name();
  auto method_count = desc->method_count();
  for (int i = 0; i < method_count; ++i) {
    auto method_desc = desc->method(i);
    auto method_name = method_desc->name();
    service_info.methodMap_.insert({method_name, method_desc});
  }
  service_info.service_ = service;
  serviceMap_.insert({service_name, service_info});
}

void rpcProvider::run() {
  std::string ip = rpcApplication::instance().config().load("rpcserverip");
  uint16_t port =
      atoi(rpcApplication::instance().config().load("rpcserverport").c_str());
  muduo::net::InetAddress addr(ip, port);

  muduo::net::TcpServer server(&eventLoop_, addr, "rpcProvider");

  server.setConnectionCallback(
      [this](const muduo::net::TcpConnectionPtr &conn) {
        this->onConnection(conn);
      });

  server.setMessageCallback([this](const muduo::net::TcpConnectionPtr &conn,
                                   muduo::net::Buffer *buffer,
                                   muduo::Timestamp timestamp) {
    this->onMessage(conn, buffer, timestamp);
  });

  server.setThreadNum(20);

  server.start();
  eventLoop_.loop();
}

void rpcProvider::onConnection(const muduo::net::TcpConnectionPtr &conn) {
  if (!conn->connected())
    conn->shutdown();
}

/*
date format:

rpcHead : service_name method_name args_size
head_size(4bytes) rpcHead(string) args(string)
*/
void rpcProvider::onMessage(const muduo::net::TcpConnectionPtr &TcpConn,
                            muduo::net::Buffer *buff, muduo::Timestamp time) {
  std::string buf = buff->retrieveAllAsString();
  uint32_t head_size;
  buf.copy((char *)&head_size, 4, 0);
  std::string rpc_head_str = buf.substr(4, head_size);
  RPC::rpcHead rpc_head;

  if (!rpc_head.ParseFromString(rpc_head_str)) {
    LOG(ERROR) << "rpc_head.ParseFromString error, rpc_head:" << rpc_head_str
               << " func return";
    return;
  }

  std::string service_name = rpc_head.service_name_();
  std::string method_name = rpc_head.method_name_();
  int args_size = rpc_head.args_size_();
  std::string args_str = buf.substr(4 + head_size, args_size);

  // debug:
  std::cout << "service_name : " << service_name << std::endl;
  std::cout << "method_name : " << method_name << std::endl;
  std::cout << "args_str : " << args_str << std::endl;

  auto it = serviceMap_.find(service_name);
  if (it == serviceMap_.end()) {
    LOG(ERROR) << "service_name : " << service_name << " not find";
    return;
  }
  serviceInfo info = it->second;
  google::protobuf::Service *service = info.service_;

  auto it2 = info.methodMap_.find(method_name);
  if (it2 == info.methodMap_.end()) {
    LOG(ERROR) << "method_name : " << method_name << " not find";
    return;
  }
  const google::protobuf::MethodDescriptor *methodDes = it2->second;

  auto req = service->GetRequestPrototype(methodDes).New();
  if (!req->ParseFromString(args_str)) {
    LOG(ERROR) << "args_str : " << args_str << " parse error";
    return;
  }

  auto resp = service->GetResponsePrototype(methodDes).New();

  auto done =
      google::protobuf::NewCallback<rpcProvider,
                                    const muduo::net::TcpConnectionPtr &,
                                    google::protobuf::Message *>(
          this, &rpcProvider::sendResp, TcpConn, resp);

  service->CallMethod(methodDes, nullptr, req, resp, done);
}

void rpcProvider::sendResp(const muduo::net::TcpConnectionPtr &conn,
                           google::protobuf::Message *Resp) {
  std::string res_str;
  if (!Resp->SerializeToString(&res_str)) {
    LOG(ERROR) << "SerializeToString : " << res_str << " error";
    return;
  }
  conn->send(res_str);
  conn->shutdown();
}