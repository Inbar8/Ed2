#ifndef ED2_FILECACHEMANAGER_H
#define ED2_FILECACHEMANAGER_H

#include <string>
#include <fstream>
#include <unordered_map>
#include "protocols/Protocol.h"
#include "CacheManager.h"

using namespace std;

template<class Problem, class Solution>
class FileCacheManager : public CacheManager<Problem, Solution> {
  unordered_map<Problem, Solution> cacheMap;
  fstream cacheFile;
//  Protocol<Problem> setProblem;
 // Protocol<Solution> setSolution;

  void createCache(const char *cacheName) override {

    cacheFile.open(cacheName, ios::in | ios::out | ios::app);
    if (!this->cacheFile.is_open()) {
      throw runtime_error("Can't open file");
    }


  }


   public:


    FileCacheManager() = default;


    void writeToFile(string &write) {
//      for (auto p : cacheMap) {
//        //one line -> problem.
//        stream << p.first << endl;
//        //next line -> solution. (no $).
//        stream << p.second << endl;
//      }
//      stream.close();
    }


    void readFromFile(string &fileName) {
      fstream stream(fileName);
      string problemStr;
      string solutionStr;
      while (!stream.eof()) {
        //problem.
        getline(stream, problemStr);
        getline(stream, solutionStr);
        cacheMap[problemStr] = solutionStr;
      }
      stream.close();
    }


  void save(string problemToWrite, string solutionToWrite) override {
     // this->cacheFile<<problemToWrite<<endl<<solutionToWrite;
     // this->cacheMap[problemToWrite] = solutionToWrite;
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

