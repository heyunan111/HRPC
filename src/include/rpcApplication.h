#pragma once
#include "rpcConfig.h"
#include "rpcController.h"

class rpcApplication {
public:
  static rpcApplication &instance();

  static void init(const std::string &file_path,
                   const std::string &log_path = "/tmp");

  static rpcConfig &config() { return rpcconfig_; }

private:
  rpcApplication() = default;
  rpcApplication(const rpcApplication &) = delete;
  rpcApplication &operator=(const rpcApplication &) = delete;

private:
  static rpcConfig rpcconfig_;
};
