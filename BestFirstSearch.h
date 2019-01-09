
#ifndef ED2_BESTFIRSTSEARCH_H
#define ED2_BESTFIRSTSEARCH_H

#include <set>
#include "Searcher.h"
#include "unordered_set"

template <class Problem, class Solution>
class BestFirstSearch : public Searcher<Problem, Solution> {


 public:

  Solution search(Searchable<Problem> problemToSolve) override {

    multiset<State<Problem>> openList = problemToSolve.getStartState();

    unordered_multiset<State<Problem>> closeList =
        new unordered_multiset<State<Problem>>();

    while (openList.size() > 0) {
  //    State<Problem> node = openList.top();
   //   openList.erase()

    }



  }

};


#endif //ED2_BESTFIRSTSEARCH_H
