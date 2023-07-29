#include "rpcApplication.h"
#include "rpcChannel.h"
#include "rpcController.h"
#include "user.pb.h"

#include <iostream>
#include <string>

int main(int argc, char **argv) {
  rpcApplication::init(argc, argv);
  example::UserServiceRpc_Stub stub(new rpcChannel());

  example::LoginRequest req;
  req.set_name("he yu nan");
  req.set_pwd("123456");

  example::LoginResponse resp;
  rpcController log_connteroller;
  stub.Login(&log_connteroller, &req, &resp, nullptr);

  int errCode = resp.result().errcode();
  std::string errMsg = resp.result().errmsg();
  bool success = resp.sucess();

  if (log_connteroller.Failed()) {
    std::cout << log_connteroller.ErrorText() << std::endl;
  } else {
    std::cout << "Login" << std::endl;
    std::cout << "errCode  " << errCode << std::endl;
    std::cout << "errMsg  " << errMsg << std::endl;
    std::cout << "success  " << success << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////
  example::RegisterRequest regReq;
  regReq.set_name("Register name");
  regReq.set_pwd("Register pwd");
  regReq.set_id(1);
  example::RegisterResponse regResp;
  rpcController reg_connteroller;
  stub.Register(&reg_connteroller, &regReq, &regResp, nullptr);
  errCode = regResp.result().errcode();
  errMsg = regResp.result().errmsg();
  success = regResp.sucess();

  if (reg_connteroller.Failed()) {
    std::cout << reg_connteroller.ErrorText() << std::endl;
  } else {
    std::cout << "Register" << std::endl;
    std::cout << "errCode  " << errCode << std::endl;
    std::cout << "errMsg  " << errMsg << std::endl;
    std::cout << "success  " << success << std::endl;
  }

  return 0;
}