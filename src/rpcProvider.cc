#include "rpcProvider.h"
#include "rpcApplication.h"
#include <functional>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpServer.h>

void rpcProvider::notifyService(google::protobuf::Service *service) {}

void rpcProvider::run() {
  std::string ip = rpcApplication::instance().config().load("rpcserverip");
  uint16_t port =
      atoi(rpcApplication::instance().config().load("rpcserverport").c_str());
  muduo::net::InetAddress addr(ip.c_str(), port);

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

void rpcProvider::onConnection(const muduo::net::TcpConnectionPtr &) {}
void rpcProvider::onMessage(const muduo::net::TcpConnectionPtr &,
                            muduo::net::Buffer *, muduo::Timestamp) {}