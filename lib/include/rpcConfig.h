#pragma once

#include <string>
#include <unordered_map>

namespace hrpc {
class rpcConfig {
public:
  std::string load(const std::string &key);

  void loadConfigFile(const char *file);

private:
  void skipSpace(std::string &str);

private:
  std::unordered_map<std::string, std::string> config_;
};
} // namespace hrpc
