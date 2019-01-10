
#ifndef ED2_SEARCHER_H
#define ED2_SEARCHER_H
#include <cstdint>
#include "Searchable.h"
template <class Problem, class Solution>
class Searcher {


 public:
  virtual Solution search(Searchable<Problem> problemToSolve) = 0;


};

#endif //ED2_SEARCHER_H
