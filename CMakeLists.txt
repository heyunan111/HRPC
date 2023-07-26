# 设置cmake的最低版本和项目名称
cmake_minimum_required(VERSION 3.0)
project(RPC)

set(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_CXX_STANDARD 20)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${PROJECT_SOURCE_DIR}/example)
link_directories(${PROJECT_SOURCE_DIR}/lib)

#add_subdirectory(src)
add_subdirectory(example)