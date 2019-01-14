
#ifndef ED2_MYTESTHANDLER_H
#define ED2_MYTESTHANDLER_H
#include "ClientHandler.h"
#include "ProtocolMatrix.h"
#define NAME_FILE "solution.txt"
template <class Problem, class Solution>
class MyClientHandler : public ClientHandler {



  Solver<Problem, Solution>* currentSolver;
  CacheManager<Problem, Solution>* currentManager;
  Protocol<Problem>* problemP;
  Protocol<Solution>* solutionP;

 public:

  MyClientHandler(
      Solver<Problem, Solution>* setTypeSolve,
      CacheManager<Problem, Solution>* setTypeCache,
      Protocol<Problem>* setProblem, Protocol<Solution>* setSolution) :
       currentSolver(setTypeSolve), currentManager(setTypeCache) {
    this->problemP = setProblem;
    this->solutionP = setSolution;
    this->currentManager->createCache(NAME_FILE);
  }




  void handleClient(StreamInput* input, StreamOutput* output) override {


  }


};

#endif //ED2_MYTESTHANDLER_H
