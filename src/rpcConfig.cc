#include "rpcConfig.h"
#include <glog/logging.h>

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <variant>
namespace hrpc {
std::string rpcConfig::load(const std::string &key) {
  auto it = config_.find(key);
  if (it == config_.end()) {
    LOG(ERROR) << "key not find";
    return "";
  }
  return it->second;
}

void rpcConfig::loadConfigFile(const char *file) {
  auto fp = fopen(file, "r");
  if (fp == nullptr) {
    LOG(FATAL) << "file not find";
    exit(EXIT_FAILURE);
  }
  while (!feof(fp)) {
    char buff[256]{0};
    fgets(buff, 256, fp);
    std::string read_buf{buff};
    skipSpace(read_buf);

    if (read_buf[0] == '#' || read_buf.empty()) {
      continue;
    }

    int index = read_buf.find('=');
    if (index == -1)
      continue;

    std::string key = read_buf.substr(0, index);
    skipSpace(key);

    int endIndex = read_buf.find('\n');
    std::string value = read_buf.substr(index + 1, endIndex - index - 1);
    skipSpace(value);
    config_.insert({key, value});
  }
  fclose(fp);
}

void rpcConfig::skipSpace(std::string &str) {
  int index = str.find_first_not_of(' ');
  if (index != -1) {
    str = str.substr(index, str.size() - index);
  }
  index = str.find_last_not_of(' ');
  if (index != -1) {
    str = str.substr(0, index + 1);
  }
}
} // namespace hrpc
