find_package (glog 0.6.0 REQUIRED)
aux_source_directory(. DIR_LIB_SRCS)
add_library(RPC ${DIR_LIB_SRCS})
target_link_libraries (RPC glog::glog  muduo_net muduo_base pthread) 