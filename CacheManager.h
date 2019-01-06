
#ifndef ED2_CACHEMANAGER_H
#define ED2_CACHEMANAGER_H


template <class Problem, class Solution>
class CacheManager {


 public:

  virtual void save(Solution saveSolution) = 0;
  virtual bool check(Problem checkSolutionExist) = 0;
  virtual Solution get(Problem problemToReturn) = 0;


};


#endif //ED2_CACHEMANAGER_H
