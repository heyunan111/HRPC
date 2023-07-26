#include "rpcConfig.h"
#include "logger.h"

#include <iostream>

std::string rpcConfig::load(const std::string &key) {
  auto it = config_.find(key);
  if (it == config_.end()) {
    LOG_ERROR("not find key");
    return "";
  }
  return it->second;
}

void rpcConfig::loadConfigFile(const char *file) {}

void rpcConfigskipSpace(std::string) {}