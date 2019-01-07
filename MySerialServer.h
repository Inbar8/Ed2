#ifndef ED2_MYSERIALSERVER_H
#define ED2_MYSERIALSERVER_H
#include "Server.h"

namespace server_side {

template<class Problem, class Solution>
class MySerialServer : public Server<Problem, Solution> {

 public:
  void open(int port, ClientHandler<Problem, Solution>) override {

  }

  void stop() override {

  }
};

}
#endif //ED2_MYSERIALSERVER_H
