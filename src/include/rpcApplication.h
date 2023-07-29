#pragma once
#include "rpcConfig.h"
#include "rpcController.h"

namespace hrpc {

/// This class is implemented as a Singleton pattern.
class rpcApplication {
public:
  /**
   * @brief Get the instance of the rpcApplication class.
   *
   * @return rpcApplication& A reference to the instance of the rpcApplication
   * class.
   */
  static rpcApplication &instance();

  /**
   * @brief Initialize the rpcApplication instance with configuration settings.
   *
   * @param file_path The file path to the configuration file.
   * @param log_path The log file path (default: "/tmp").
   */
  static void init(const std::string &file_path,
                   const std::string &log_path = "/tmp");

  /**
   * @brief Get the reference to the rpcConfig instance.
   *
   * @return rpcConfig& A reference to the rpcConfig instance.
   */
  static rpcConfig &config() { return rpcconfig_; }

private:
  /**
   * @brief Private constructor to prevent direct instantiation.
   */
  rpcApplication() = default;

  // Disable copy constructor and assignment operator
  rpcApplication(const rpcApplication &) = delete;
  rpcApplication &operator=(const rpcApplication &) = delete;

private:
  // The instance of rpcConfig
  static rpcConfig rpcconfig_;
};

} // namespace hrpc
