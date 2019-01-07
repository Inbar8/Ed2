
#ifndef ED2_MYTESTHANDLER_H
#define ED2_MYTESTHANDLER_H
#include "ClientHandler.h"

template <class Problem, class Solution>
class MyClientHandler : public ClientHandler<Problem, Solution>{



  Solver<Problem, Solution>* currentSolver;
  CacheManager<Problem, Solution>* currentManager;

 public:


  MyClientHandler(Solver<Problem, Solution>* setTypeSolve,
      CacheManager<Problem, Solution>* setTypeCache) :
      currentManager(setTypeCache), currentSolver(setTypeSolve) {}


  void handleClient(istream input, ostream output) override {



  }
};

#endif //ED2_MYTESTHANDLER_H
