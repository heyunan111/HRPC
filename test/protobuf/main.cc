#include <iostream>
#include <string>

#include "test.pb.h"

int main() {
  fixbug::LoginRequest req;
  req.set_name("heyunan");
  req.set_pwd("123456");

  std::string s;

  if (req.SerializeToString(&s)) {
    std::cout << s.c_str() << std::endl;
  }

  return 0;
}