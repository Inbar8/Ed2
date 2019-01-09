#ifndef ED2_FILECACHEMANAGER_H
#define ED2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <string>
#include <fstream>
#include <unordered_map>
#define SUFFIX ".txt"
using namespace std;

template <class Problem, class Solution>
class FileCacheManager : public CacheManager<Problem, Solution> {
    unordered_map<Problem, Solution> cacheMap; //TODO: how to create this hashmap in o(1).
    fstream cacheFile;



  Solution readFromFile(Problem& problemToRead) {

    while (!this->cacheFile.eof()) {
   //   if (strcmp())
    }
    throw invalid_argument("No such problem in file");
  }

public:

    void getTheCacheReady(string& typeOfFile) override {
      typeOfFile.append(SUFFIX);
      cacheFile.open(typeOfFile, ios::in | ios::app);
      if (!this->cacheFile.is_open()) {
        throw runtime_error ("Can't open file");
      }
      ////////////
      ///////////
      ////////////
      ///////////////// how to get data from map.

    }


 public:
  void save(Problem problemToWrite, Solution solutionToWrite) override {
    this->cacheFile<<problemToWrite<<endl<<solutionToWrite;
    this->cacheMap[problemToWrite] = solutionToWrite;
  }

  bool check(Problem checkProblemExist) override {
    return (bool)(cacheMap.count(checkProblemExist));
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
