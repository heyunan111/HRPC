#pragma once

#include <string>

#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include <google/protobuf/service.h>

namespace hrpc {

class rpcChannel : public google::protobuf::RpcChannel {
public:
  void CallMethod(const google::protobuf::MethodDescriptor *method,
                  google::protobuf::RpcController *controller,
                  const google::protobuf::Message *request,
                  google::protobuf::Message *response,
                  google::protobuf::Closure *done) override;
};
} // namespace hrpc
