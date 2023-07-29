# hrpc - 分布式RPC框架

hrpc是一个基于muduo、protobuf、glog和zookeeper的简单的分布式RPC框架，旨在简化分布式系统中服务间通信的过程，提供高性能和易用性。使用protobuf作为数据交换格式，并通过zookeeper实现服务的注册与发现。

## 安装与运行

在开始使用hrpc之前，确保系统中已经安装了以下依赖：

- muduo
- protobuf
- glog
- zookeeper

```bash
# 安装步骤
$ git clone https://github.com/heyunan111/HRPC.git
$ cd HRPC
$ mkdir build && cd build
$ cmake ..
$ make
```

## 配置

hrpc需要传入一个配置文件，配置文件中需要4个参数，以下是一个示例  

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
注意：名称必须保持一致  


## 示例

以下示例演示了如何在hrpc中定义一个简单的RPC服务和客户端，代码在example中：

### protobuf

首先我们需要一个proto文件，在其中定义需要注册的方法，传值，返回值。[示例](./example/user.proto)  
通过`protoc`生成c++代码：`protoc path/to/example.proto --cpp_out=you/want/path`。  
[protobuf的github](https://github.com/protocolbuffers/protobuf.git)。  

### 服务端

```cpp
#include "hrpc.h"
#include "刚刚生成的.pb.h"

class your_class : public example::UserServiceRpc {
    //见protobuf教学或者example中的示例
};

int main() {
  std::string file_path = "配置文件路径";
  hrpc::rpcApplication::init(file_path);
  hrpc::rpcProvider provider;
  provider.notifyService(new your_class());
  provider.run(开启的线程数，默认5);
  return 0;
}
```

### 客户端

```cpp
#include "hrpc.h"
#include "刚刚生成的.pb.h"

int main() {
  hrpc::rpcApplication::init("配置文件路径");
  example::UserServiceRpc_Stub stub(new hrpc::rpcChannel());

  //设置传入参数
  example::LoginRequest req;
  req.set_name("bob");
  req.set_pwd("123456");

  //定义返回值
  example::LoginResponse resp;

  hrpc::rpcController log_connteroller;
  stub.Login(&log_connteroller, &req, &resp, nullptr);

  //接收返回值
  int errCode = resp.result().errcode();
  std::string errMsg = resp.result().errmsg();
  bool success = resp.sucess();

  //do some thing

  return 0;
}
```

## 贡献

如果你发现了bug，或者有任何改进意见，欢迎提交Issue或者Pull Request。也欢迎贡献更多的示例代码和文档。

## 许可证

hrpc使用[阿帕奇许可证2.0](LICENSE)。

---

感谢你选择hrpc！如果有任何疑问或建议，请随时联系我们：he_yu_nan@qq.com。