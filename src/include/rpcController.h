#pragma once

#include <google/protobuf/service.h>
#include <string>

namespace hrpc {
/**
 * @brief The rpcController class is an implementation based on
 * google::protobuf::RpcController.
 *
 * This class provides control functionalities for the RPC invocation process.
 */
class rpcController : public google::protobuf::RpcController {
public:
  /**
   * @brief Constructor, initializes the rpcController instance.
   */
  rpcController() : errorText_(""), is_failed_(false) {}

  /**
   * @brief Reset the rpcController instance, clearing the failure flag and
   * error message.
   */
  void Reset() override {
    is_failed_ = false;
    errorText_ = "";
  }

  /**
   * @brief Check if the rpcController instance has failed.
   *
   * @return bool Returns true if failed, false otherwise.
   */
  bool Failed() const override { return is_failed_; }

  /**
   * @brief Get the error message of the rpcController instance.
   *
   * @return std::string The error message string.
   */
  std::string ErrorText() const override { return errorText_; }

  /**
   * @brief Set the rpcController instance to a failed state with the given
   * reason as the error message.
   *
   * @param reason The reason for the failure, which will be set as the error
   * message.
   */
  void SetFailed(const std::string &reason) override {
    is_failed_ = true;
    errorText_ = reason;
  }

  /**
   * @brief Unused method, no action is taken.
   */
  void StartCancel() override {}

  /**
   * @brief Unused method, always returns false.
   *
   * @return bool Always returns false.
   */
  bool IsCanceled() const override { return false; }

  /**
   * @brief Unused method, no callback is set.
   *
   * @param callback A pointer to the google::protobuf::Closure callback
   * function.
   */
  void NotifyOnCancel(google::protobuf::Closure *callback) override {}

private:
  std::string errorText_; // Error message
  bool is_failed_;        // Failure flag
};

} // namespace hrpc
