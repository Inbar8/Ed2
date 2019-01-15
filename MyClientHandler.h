
#ifndef ED2_MYTESTHANDLER_H
#define ED2_MYTESTHANDLER_H
#include "ClientHandler.h"
#include "ProtocolMatrix.h"
#define NAME_FILE "solution.txt"
#define SUFFIX_TYPE "end\n"
#define SUFFIX_SIZE 4
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

try {
    string inputString;

    do {
      inputString += input->read();

      unsigned long suffixExist = inputString.find(SUFFIX_TYPE);
      if (suffixExist) {
        inputString.erase(suffixExist, inputString.size());
      }
    } while (inputString.compare(inputString.size() - SUFFIX_SIZE,
        SUFFIX_SIZE, SUFFIX_TYPE) != 0);


    output->write(solutionP->writeProtocol(
        currentSolver->solve(problemP->readProtocol(inputString))));
  }
catch (...){
  return;
}
  }

};

#endif //ED2_MYTESTHANDLER_H
