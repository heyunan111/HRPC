#include "zookeeperUtil.h"
#include "rpcApplication.h"
#include <glog/logging.h>
#include <semaphore.h>
#include <zookeeper/zookeeper.h>

zkClient::zkClient() : zhandle_(nullptr) {}

zkClient::~zkClient() {
  if (zhandle_ != nullptr) {
    zookeeper_close(zhandle_);
  }
}

// typedef void (*watcher_fn)(zhandle_t *zh, int type,int state, const char
// *path,void *watcherCtx);
void gloab_watcher(zhandle_t *zh, int type, int state, const char *path,
                   void *watcherCtx) {
  if (type == ZOO_SESSION_EVENT) {
    // is session
    if (state == ZOO_CONNECTED_STATE) {
      // client connected server
      sem_t *sem = (sem_t *)zoo_get_context(zh);
      sem_post(sem);
    }
  }
}

void zkClient::start() {
  std::string host = rpcApplication::instance().config().load("zookeeperip");
  std::string port = rpcApplication::instance().config().load("zookeeperport");
  std::string connstr = host + ":" + port;

  /*
  zookeeper has 3 threads
    1. API thread
    2. IO thread: pthread and poll
    3. watcher call back thread
  */

  // def session time out : 30s
  // zookeeper will auto send heart msg ervery 1/3 * timeout
  zhandle_ = zookeeper_init(connstr.c_str(), gloab_watcher, 30000, nullptr,
                            nullptr, 0);
  LOG_IF(FATAL, (zhandle_ == nullptr)) << "zookeeper_init error !";

  sem_t sem;
  sem_init(&sem, 0, 0);
  zoo_set_context(zhandle_, &sem);
  sem_wait(&sem);
}

void zkClient::create(const char *path, const char *data, int datalen,
                      int state) {
  int flage = zoo_exists(zhandle_, path, 0, nullptr);
  if (flage == ZNONODE) {
    // not hava , create new one

    // we don`t need return path buff
    flage = zoo_create(zhandle_, path, data, datalen, &ZOO_OPEN_ACL_UNSAFE,
                       state, nullptr, 0);
    LOG_IF(FATAL, (flage != ZOK))
        << "flage : " << flage << "zoo_create error !";
  }
}
std::string zkClient::get_data(const char *path) {
  char buffer[64];
  int bufferlen = sizeof(buffer);

  if (zoo_get(zhandle_, path, 0, buffer, &bufferlen, nullptr) == ZOK) {
    return buffer;
  } else {
    LOG(ERROR) << "zoo_get error path : " << path;
    return "";
  }
}