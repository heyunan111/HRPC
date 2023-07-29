#include "rpcApplication.h"
#include "rpcChannel.h"
#include "user.pb.h"

#include <iostream>
#include <string>

int main() {
  std::vector<char *> args = {
      const_cast<char *>(
          "example_caller"), // argv[0] 通常是程序名，可以设置任意值
      const_cast<char *>("-i"), const_cast<char *>("test.conf")};
  int argc = args.size();
  char **argv = args.data();
  rpcApplication::init(argc, argv);
  example::UserServiceRpc_Stub stub(new rpcChannel());

  example::LoginRequest req;
  req.set_name("he yu nan");
  req.set_pwd("123456");

  example::LoginResponse resp;

  stub.Login(nullptr, &req, &resp, nullptr);

  int errCode = resp.result().errcode();
  std::string errMsg = resp.result().errmsg();
  bool success = resp.sucess();

  std::cout << "Login" << std::endl;
  std::cout << "errCode  " << errCode << std::endl;
  std::cout << "errMsg  " << errMsg << std::endl;
  std::cout << "success  " << success << std::endl;

  /////////////////////////////////////////////////////////////////////////////////////////////////
  example::RegisterRequest regReq;
  regReq.set_name("Register name");
  regReq.set_pwd("Register pwd");
  regReq.set_id(1);
  example::RegisterResponse regResp;
  stub.Register(nullptr, &regReq, &regResp, nullptr);
  errCode = regResp.result().errcode();
  errMsg = regResp.result().errmsg();
  success = regResp.sucess();
  std::cout << "Register" << std::endl;
  std::cout << "errCode  " << errCode << std::endl;
  std::cout << "errMsg  " << errMsg << std::endl;
  std::cout << "success  " << success << std::endl;
  return 0;
}