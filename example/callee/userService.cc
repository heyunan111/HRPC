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
  bool Register(uint32_t id, std::string name, std::string pwd) {
    std::cout << "================Register start================" << std::endl;
    std::cout << "id :" << id << std::endl;
    std::cout << "name :" << name << std::endl;
    std::cout << "pwd :" << pwd << std::endl;
    return true;
  }
  void Register(::google::protobuf::RpcController *controller,
                const ::example::RegisterRequest *request,
                ::example::RegisterResponse *response,
                ::google::protobuf::Closure *done) override {
    auto name = request->name();
    auto pwd = request->pwd();
    auto id = request->id();
    auto res = Register(id, name, pwd);

    response->set_sucess(res);
    auto errCode = response->mutable_result();
    errCode->set_errcode(0);
    errCode->set_errmsg("Register");
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