#include <iostream>
#include <string>

#include "../user.pb.h"
#include "rpcApplication.h"
#include "rpcProvider.h"

class UserService : public example::UserServiceRpc {
public:
  bool Login(std::string name, std::string pwd) {
    std::cout << "================Login start================" << std::endl;
    std::cout << "name :" << name << std::endl;
    std::cout << "pwd :" << pwd << std::endl;
    return true;
  }

  void Login(::google::protobuf::RpcController *controller,
             const ::example::LoginRequest *request,
             ::example::LoginResponse *response,
             ::google::protobuf::Closure *done) override {
    auto name = request->name();
    auto pwd = request->pwd();

    auto res = Login(name, pwd);

    auto *resCode = response->mutable_result();
    resCode->set_errmsg("no");
    resCode->set_errcode(0);
    response->set_sucess(res);
    done->Run();
  }
};

int main() {
  std::vector<char *> args = {
      const_cast<char *>(
          "example_callee"), // argv[0] 通常是程序名，可以设置任意值
      const_cast<char *>("-i"), const_cast<char *>("test.conf")};
  int argc = args.size();
  char **argv = args.data();
  rpcApplication::init(argc, argv);
  rpcProvider provider;
  provider.notifyService(new UserService());
  provider.run();
  return 0;
}