
#ifndef ED2_CACHEMANAGER_H
#define ED2_CACHEMANAGER_H


template<class Problem, class Solution>
class CacheManager {


public:

    virtual void save(Problem saveProblem, Solution saveSolution) = 0;

    virtual bool check(Problem checkSolutionExist) = 0;

    virtual Solution getSolution(Problem problemToReturn) = 0;


};


#endif //ED2_CACHEMANAGER_H
