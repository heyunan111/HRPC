# hrpc - Distributed RPC Framework

hrpc is a simple distributed RPC framework based on muduo, protobuf, glog, and zookeeper. It aims to simplify the process of inter-service communication in distributed systems, providing high performance and ease of use. It uses protobuf as the data exchange format and utilizes zookeeper for service registration and discovery.

中文版链接：[中文README](./Chinese.md)

## Installation and Usage

Before using hrpc, make sure the following dependencies are installed on your system:

- muduo
- protobuf
- glog
- zookeeper

```bash
# Installation steps
$ git clone https://github.com/heyunan111/HRPC.git
$ cd HRPC
$ mkdir build && cd build
$ cmake ..
$ make
```

## Configuration

hrpc requires a configuration file with 4 parameters. Here's an example:

```conf
# rpc ip
rpcserverip=127.0.0.1
# rpc port
rpcserverport=8000
# zk ip
zookeeperip=127.0.0.1
# zk port
zookeeperport=2181
```

Please make sure the parameter names match in the configuration file.

## Examples

The following examples demonstrate how to define a simple RPC service and client in hrpc. The code can be found in the "example" directory.

### Protobuf

First, you need a proto file where you define the methods to be registered, input parameters, and return values. [Example](./example/user.proto)  
Generate C++ code using `protoc`: `protoc path/to/example.proto --cpp_out=you/want/path`.  
[protobuf on GitHub](https://github.com/protocolbuffers/protobuf.git).

### Server

```cpp
#include "hrpc.h"
#include "path/to/your_generated.pb.h"

class YourClass : public example::UserServiceRpc {
    // See the protobuf tutorial or examples in the "example" directory for details.
};

int main() {
  std::string file_path = "path/to/your/configuration_file";
  hrpc::rpcApplication::init(file_path);
  hrpc::rpcProvider provider;
  provider.notifyService(new YourClass());
  provider.run(number_of_threads_to_run, default is 5);
  return 0;
}
```

### Client

```cpp
#include "hrpc.h"
#include "path/to/your_generated.pb.h"

int main() {
  hrpc::rpcApplication::init("path/to/your/configuration_file");
  example::UserServiceRpc_Stub stub(new hrpc::rpcChannel());

  // Set input parameters
  example::LoginRequest req;
  req.set_name("bob");
  req.set_pwd("123456");

  // Define return value
  example::LoginResponse resp;

  hrpc::rpcController log_controller;
  stub.Login(&log_controller, &req, &resp, nullptr);

  // Receive return values
  int errCode = resp.result().errcode();
  std::string errMsg = resp.result().errmsg();
  bool success = resp.success();

  // Do something with the return values

  return 0;
}
```

## Contributing

If you find any bugs or have any suggestions for improvements, please feel free to submit an Issue or Pull Request. Contributions of additional example code and documentation are also welcome.

## License

hrpc is licensed under the [Apache License 2.0](LICENSE).

---

Thank you for choosing hrpc! If you have any questions or suggestions, please feel free to contact us at he_yu_nan@qq.com.