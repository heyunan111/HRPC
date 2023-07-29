#include "rpcApplication.h"
#include "rpcConfig.h"

#include <cstdlib>
#include <iostream>
#include <unistd.h>

#include <glog/logging.h>

rpcConfig rpcApplication::rpcconfig_{};

rpcApplication &rpcApplication::instance() {
  static rpcApplication rpcApp;
  return rpcApp;
}

void rpcApplication::init(const std::string &file_path,
                          const std::string &log_path) {
  google::InitGoogleLogging("rpc server");
  FLAGS_log_dir = log_path;
  rpcconfig_.loadConfigFile(file_path.c_str());
}