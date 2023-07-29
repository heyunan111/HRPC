#pragma once

#include <google/protobuf/service.h>
#include <string>

namespace hrpc {
class rpcController : public google::protobuf::RpcController {
public:
  rpcController() : errorText_(""), is_failed_(false) {}

  void Reset() override {
    is_failed_ = false;
    errorText_ = "";
  }

  bool Failed() const override { return is_failed_; }

  std::string ErrorText() const override { return errorText_; }

  void SetFailed(const std::string &reason) override {
    is_failed_ = true;
    errorText_ = reason;
  }

  // we do not use it
  void StartCancel() override {}
  bool IsCanceled() const override { return false; }
  void NotifyOnCancel(google::protobuf::Closure *callback) override {}

private:
  std::string errorText_;
  bool is_failed_;
};
} // namespace hrpc
