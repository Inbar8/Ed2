
#ifndef ED2_MYTESTHANDLER_H
#define ED2_MYTESTHANDLER_H
#include "ClientHandler.h"
#include "protocols/ProtocolMatrix.h"
#define NAME_FILE "solution.txt"
#define SUFFIX_TYPE "end"

#include "SearchAlgorithm.h"
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

      } while (inputString.rfind(SUFFIX_TYPE) == string::npos);

      inputString.erase(inputString.begin() + inputString.rfind(SUFFIX_TYPE),
                        inputString.end());

      Problem* problemS = problemP->readProtocol(inputString);
      vector<string> solutionS = this->currentSolver->solve((problemS));
      output->write(solutionP->writeProtocol(solutionS));
    }
    catch (invalid_argument &e) {
      cout << e.what() << endl;
    }
    catch (...) {
      cout << "Problem in client handler" << endl;
      return;
    }
  }


  ~MyClientHandler() {
    delete currentSolver;
    delete currentManager;
    delete problemP;
    delete solutionP;
  }
};

#endif //ED2_MYTESTHANDLER_H
