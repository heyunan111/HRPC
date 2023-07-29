#pragma once

#include <semaphore.h>
#include <string>
#include <zookeeper/zookeeper.h>

class zkClient {
public:
  zkClient();
  ~zkClient();
  void start();
  void create(const char *path, const char *data, int datalen, int state = 0);
  std::string get_data(const char *path);

private:
  zhandle_t *zhandle_;

  sem_t sem_;
};