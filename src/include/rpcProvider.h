#pragma once

#include <functional>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/service.h>
#include <memory.h>
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

  void run();

private:
  /*
std::function<void (const TcpConnectionPtr&)> ConnectionCallback;
std::function<void (const TcpConnectionPtr&,Buffer*,Timestamp)> MessageCallback;
*/

  void onConnection(const muduo::net::TcpConnectionPtr &);
  void onMessage(const muduo::net::TcpConnectionPtr &, muduo::net::Buffer *,
                 muduo::Timestamp);
  muduo::net::EventLoop eventLoop_;
};
