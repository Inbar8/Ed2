
#ifndef ED2_CACHEMANAGER_H
#define ED2_CACHEMANAGER_H


template<class Problem, class Solution>
class CacheManager {




public:

  virtual void createCache(const char* cacheName) = 0;

  virtual void save(string saveProblem, string saveSolution) = 0;

  virtual bool check(Problem checkSolutionExist) = 0;

  virtual Solution getSolution(Problem problemToReturn) = 0;


};


#endif //ED2_CACHEMANAGER_H
