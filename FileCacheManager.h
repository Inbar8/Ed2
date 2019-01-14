#ifndef ED2_FILECACHEMANAGER_H
#define ED2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;

template <class Problem, class Solution>
class FileCacheManager : public CacheManager<Problem, Solution> {
   // unordered_map<Problem, Solution> cacheMap; //TODO: how to create this hashmap in o(1).
    fstream cacheFile;




  Solution readFromFile(Problem& problemToRead) {

    while (!this->cacheFile.eof()) {
   //   if (strcmp())
    }
    throw invalid_argument("No such problem in file");
  }

public:

  void createCache(const char *cacheName) override {

    cacheFile.open(cacheName, ios::in | ios::app);
    if (!this->cacheFile.is_open()) {
      throw runtime_error ("Can't open file");
    }



  }


  void save(Problem problemToWrite, Solution solutionToWrite) override {
  }

  bool check(Problem checkProblemExist) override {
  }


  Solution getSolution(Problem problemToReturn) override {
  }



  ~FileCacheManager() {
      if (this->casheFile.is_open()) {
        this->casheFile.close();
      }
    }
};

#endif //ED2_FILECACHEMANAGER_H
