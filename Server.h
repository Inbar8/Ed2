#ifndef ED2_SERVER_H
#define ED2_SERVER_H
#include "ClientHandler.h"

template<class Problem, class Solution>
class Server {
 public:

  virtual void open(int port, ClientHandler<Problem, Solution> handleType) = 0;

  virtual void stop() = 0;
};


#endif //ED2_SERVER_H
