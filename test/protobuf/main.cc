#include <iomanip>
#include <iostream>
#include <string>

#include "test.pb.h"

// gcc *.cc -lprotobuf -labsl_log_internal_check_op -labsl_log_internal_message
// -lstdc++

int main() {

  fixbug::getFriendListRes res;
  auto *res_code = res.mutable_res();
  res_code->set_errcode_(2);
  res_code->set_errmsg_("NO");

  auto *user1 = res.add_friend_list();
  user1->set_age_(14);
  user1->set_name_("zhang san");
  user1->set_sex_(fixbug::user_sex_MAN);

  auto *user2 = res.add_friend_list();
  user2->set_age_(24);
  user2->set_name_("li si");
  user2->set_sex_(fixbug::user_sex::user_sex_WOMAN);

  std::cout << res.friend_list_size() << std::endl;

  std::string s;
  res.SerializeToString(&s);
  // 输出每个字节的十六进制值
  for (const unsigned char &byte : s) {
    std::cout << std::hex << std::setw(2) << std::setfill('0')
              << static_cast<int>(byte);
  }
  std::cout << std::endl;

  auto a = res.ParseFromString(s);

  std::cout << a << std::endl;
  std::cout << s << std::endl;

  // fixbug::loginRes res;
  // auto *rc = res.mutable_res_();
  // res.set_success_("true");
  // rc->set_errcode_(1);
  // rc->set_errmsg_("nnnn");

  // std::string s;
  // res.SerializeToString(&s);

  // // 输出每个字节的十六进制值
  // for (const unsigned char &byte : s) {
  //   std::cout << std::hex << std::setw(2) << std::setfill('0')
  //             << static_cast<int>(byte);
  // }
  // std::cout << std::endl;
  return 0;
}
