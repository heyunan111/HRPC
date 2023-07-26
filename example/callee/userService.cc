#include <iostream>
#include <string>

#include "../user.pb.h"

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
    int a = 1;
    int b = 23;
  }
};

int main() {
  UserService s;
  s.Login("hyn", "qqqq");
  return 0;
}