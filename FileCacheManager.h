#ifndef ED2_FILECACHEMANAGER_H
#define ED2_FILECACHEMANAGER_H
#include <string>
#include <fstream>
#include <unordered_map>
#include "protocols/Protocol.h"
#include "CacheManager.h"
#define TOKEN "$"
using namespace std;

template<class Problem, class Solution>
class FileCacheManager : public CacheManager<Problem, Solution> {
  unordered_map<Problem, Solution> cacheMap;
  fstream cacheFile;

  void createCache(const char *cacheName) override {
  }
    //while (fstream.re)
  //  getline()
//  }
 public:

  FileCacheManager() = default;

  void save(string problemToWrite, string solutionToWrite) override {
    this->cacheFile<<problemToWrite<<TOKEN<<solutionToWrite<<TOKEN;
    }

    bool check(Problem checkProblemExist) override {
      return this->cacheMap.find(checkProblemExist) != this->cacheMap.end();
    }

    Solution getSolution(Problem problemToReturn) override {
      return cacheMap[problemToReturn];
    }

    ~FileCacheManager() {
      if (this->casheFile.is_open()) {
        this->casheFile.close();
      }
    }
  };

#endif //ED2_FILECACHEMANAGER_H

