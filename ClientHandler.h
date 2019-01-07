

#ifndef ED2_CLIENTHANDLER_H
#define ED2_CLIENTHANDLER_H
#include "Solver.h"
#include "FileCacheManager.h"
#include "CacheManager.h"

template <class Problem, class Solution>
class ClientHandler {

 private:

  Solver<Problem, Solution> currentSolver;
  CacheManager<Problem, Solution> currentManager;


 public:
  void handleClient(istream input, ostream output) = 0;


};

#endif //ED2_CLIENTHANDLER_H
