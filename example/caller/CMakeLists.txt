set(SRC_LIST callUserService.cc ../user.pb.cc)

add_executable(example_caller ${SRC_LIST})
target_link_libraries(example_caller RPC protobuf)