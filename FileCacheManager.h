#ifndef ED2_FILECACHEMANAGER_H
#define ED2_FILECACHEMANAGER_H
#include "CacheManager.h"

template <class Problem, class Solution>
class FileCacheManager : public CacheManager<Problem, Solution> {


 public:
  void save(Solution saveSolution) override {

  }
  bool check(Problem checkSolutionExist) override {
    return false;
  }
  Solution get(Problem problemToReturn) override {
    return nullptr;
  }
  FileCacheManager() = default;

};

#endif //ED2_FILECACHEMANAGER_H
