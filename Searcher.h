
#ifndef ED2_SEARCHER_H
#define ED2_SEARCHER_H
#include <cstdint>
#include "Searchable.h"
template <class Problem, class Solution>
class Searcher {

  uint64_t counter;

 public:
  virtual Solution search(Searchable<Problem> problemToSolve) = 0;

  uint64_t getNumOfNodesEvaluated() {

    return this->counter;

  }
  void counterPlusPlus() {
    ++counter;
  }
};

#endif //ED2_SEARCHER_H
