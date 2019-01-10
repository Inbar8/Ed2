
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

    unordered_multiset<State<Problem>> closedList =
        new unordered_multiset<State<Problem>>();

    while (openList.size() > 0) {
      State<Problem> node = openList.begin();
      openList.begin().erase();
      if(node == problemToSolve.getEndState()){
          return getTrace();
      }
      multiset<State<Problem>> successors = problemToSolve.getFullState();
      for(auto s: successors){
          if(!(bool)(closedList.count(s)) && !(bool) (openList.count(s))){
              openList.insert(s);
          } else{

          }
      }
    }



  }

  Solution getTrace(){
      return nullptr;
  }
};


#endif //ED2_BESTFIRSTSEARCH_H
