#pragma once

class rpcApplication {
public:
  static rpcApplication &instance();

  void init(int argc, char **argv);

private:
  rpcApplication() = default;
  rpcApplication(const rpcApplication &) = delete;
  rpcApplication &operator=(const rpcApplication &) = delete;
};