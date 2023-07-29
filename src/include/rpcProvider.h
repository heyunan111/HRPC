#pragma once

#include <functional>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include <google/protobuf/service.h>
#include <muduo/net/Buffer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include <muduo/net/TcpServer.h>
#include <string>
#include <unordered_map>

class rpcProvider {
public:
  void notifyService(google::protobuf::Service *service);

  void run(int thread_num = 5);

private:
  void onConnection(const muduo::net::TcpConnectionPtr &);
  void onMessage(const muduo::net::TcpConnectionPtr &, muduo::net::Buffer *,
                 muduo::Timestamp);
  void sendResp(const muduo::net::TcpConnectionPtr &,
                google::protobuf::Message *);

  struct serviceInfo {
    google::protobuf::Service *service_;
    std::unordered_map<std::string, const google::protobuf::MethodDescriptor *>
        methodMap_;
  };

private:
  muduo::net::EventLoop eventLoop_;

  std::unordered_map<std::string, serviceInfo> serviceMap_;
};
