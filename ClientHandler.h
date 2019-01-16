

#ifndef ED2_CLIENTHANDLER_H
#define ED2_CLIENTHANDLER_H
#include "Solver.h"
#include "FileCacheManager.h"
#include "CacheManager.h"

class ClientHandler {

 public:
  virtual void handleClient(StreamInput* input, StreamOutput* output) = 0;
//  void worker(TCP_server* queue) {
//    while (!queue->offline()) {
//      queue->wait();
//
//      Task* task = queue->pop();
//      if (task) {
//        task->execute();
//        delete task;
//      }
//    }
//  };
};

#endif //ED2_CLIENTHANDLER_H
