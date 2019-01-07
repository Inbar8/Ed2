
#ifndef ED2_MYTESTHANDLER_H
#define ED2_MYTESTHANDLER_H
#include "ClientHandler.h"

template <class Problem, class Solution>
class MyTestHandler : public ClientHandler{



  Solver<Problem, Solution> currentSolver;
  CacheManager<Problem, Solution> currentManager;

 public:

  void handleClient(istream input, ostream output) override;
};

#endif //ED2_MYTESTHANDLER_H
