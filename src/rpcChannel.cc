#include "rpcChannel.h"
#include "rpcApplication.h"
#include "rpcHead.pb.h"

#include <arpa/inet.h>
#include <glog/logging.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include <netinet/in.h>
#include <sys/socket.h>

void rpcChannel::CallMethod(const google::protobuf::MethodDescriptor *method,
                            google::protobuf::RpcController *controller,
                            const google::protobuf::Message *request,
                            google::protobuf::Message *response,
                            google::protobuf::Closure *done) {
  auto serviceDes = method->service();
  std::string service_name = serviceDes->name();
  std::string method_name = method->name();
  std::string args_str;
  if (!request->SerializeToString(&args_str)) {
    LOG(ERROR) << "request "
               << "SerializeToString error";
    controller->SetFailed("request SerializeToString error");
    return;
  }
  RPC::rpcHead rpc_head;
  rpc_head.set_method_name_(method_name);
  rpc_head.set_service_name_(service_name);
  rpc_head.set_args_size_(args_str.size());
  std::string rpc_head_str;
  if (!rpc_head.SerializeToString(&rpc_head_str)) {
    LOG(ERROR) << "rpc_head "
               << "SerializeToString error";
    controller->SetFailed("rpc_head SerializeToString error");
    return;
  }

  /*
  date format:

  rpcHead : service_name method_name args_size
  head_size(4bytes) rpcHead(string) args(string)
  */
  uint32_t head_size = rpc_head_str.size();
  std::string req;
  req.insert(0, std::string((char *)&head_size, 4));
  req += rpc_head_str;
  req += args_str;

  // // debug:
  // std::cout << "service_name : " << service_name << std::endl;
  // std::cout << "method_name : " << method_name << std::endl;
  // std::cout << "args_str : " << args_str << std::endl;
  // std::cout << "req : " << req << std::endl;

  int client_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (client_fd == -1) {
    LOG(FATAL) << "client fd create error";
    controller->SetFailed("client fd create error");
  }

  uint16_t port =
      atoi(rpcApplication::instance().config().load("rpcserverport").c_str());
  std::string ip = rpcApplication::instance().config().load("rpcserverip");

  sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

  if (connect(client_fd, (sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    LOG(FATAL) << "connect error!";
    controller->SetFailed("connect error");
  }

  if (send(client_fd, req.c_str(), req.size(), 0) == -1) {
    LOG(ERROR) << "send error";
    controller->SetFailed("send error");
    return;
  }

  char resp_buf[1024];
  int resp_buf_size = recv(client_fd, resp_buf, 1024, 0);

  if (resp_buf_size == -1) {
    LOG(ERROR) << "recv error";
    controller->SetFailed("recv error");
    return;
  }

  std::string resp(resp_buf, 0, resp_buf_size);
  if (!response->ParseFromString(resp)) {
    LOG(ERROR) << "response ParseFromString : " << resp << " error";
    controller->SetFailed("response ParseFromString error");
    return;
  }
}