
#ifndef ED2_SEARCHER_H
#define ED2_SEARCHER_H
#include <cstdint>
#include "Searchable.h"
template <class T, class Solution>
class Searcher {


 public:
  virtual Solution search(Searchable<T>* problemToSolve) = 0;
};

#endif //ED2_SEARCHER_H
