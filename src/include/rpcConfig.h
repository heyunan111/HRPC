#pragma once

#include <string>
#include <unordered_map>

class rpcConfig {
public:
  std::string load(const std::string &key);

  void loadConfigFile(const char *file);

private:
  void skipSpace(std::string);

private:
  std::unordered_map<std::string, std::string> config_;
};