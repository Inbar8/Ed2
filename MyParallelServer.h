#ifndef ED2_MYPARALLELSERVER_H
#define ED2_MYPARALLELSERVER_H

#include "Server.h"

template<class Problem, class Solution>
 class MyParallelServer : public server_side::Server<Problem, Solution> {

  public:
   void open(int port, ClientHandler<Problem, Solution>) override {

 }

  void stop() override {

  }
};



#endif //ED2_MYPARALLELSERVER_H
