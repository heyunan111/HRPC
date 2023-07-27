#include <iostream>
#include <string>

#include "../user.pb.h"
#include "rpcApplication.h"
#include "rpcProvider.h"

class UserService : public example::UserServiceRpc {
public:
  bool Login(std::string name, std::string pwd) {
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

    response->set_sucess(res);
    auto *resCode = response->mutable_result();
    resCode->set_errmsg("null");
    resCode->set_errcode(0);

    done->Run();
  }
};

int main(int argc, char **argv) {
  rpcApplication::init(argc, argv);
  rpcProvider provider;
  provider.notifyService(new UserService());
  provider.run();
  return 0;
}