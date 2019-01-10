
#ifndef ED2_SEARCHALGORITHM_H
#define ED2_SEARCHALGORITHM_H
#include "Searcher.h"

template <class Problem, class Solution>
class SearchAlgorithm : public Searcher<Problem, Solution> {


  uint64_t counter = 0;

 protected:

  virtual uint64_t getNumOfNodesEvaluated() {

    return this->counter;

  }

  virtual void counterPlusPlus() {
    ++counter;
  }
};

#endif //ED2_SEARCHALGORITHM_H
