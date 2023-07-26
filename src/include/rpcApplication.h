#pragma once
#include "rpcConfig.h"

class rpcApplication {
public:
  static rpcApplication &instance();

  static void init(int argc, char **argv);

private:
  rpcApplication() = default;
  rpcApplication(const rpcApplication &) = delete;
  rpcApplication &operator=(const rpcApplication &) = delete;

private:
  static rpcConfig rpcconfig_;
};
