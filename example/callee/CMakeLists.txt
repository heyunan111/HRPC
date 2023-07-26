set(SRC_LIST userService.cc ../user.pb.cc)
#set(SRC_LIST friendservice.cc ../friend.pb.cc)

add_executable(example_callee ${SRC_LIST})
target_link_libraries(example_callee protobuf)