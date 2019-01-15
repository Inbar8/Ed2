#ifndef ED2_FILECACHEMANAGER_H
#define ED2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

template<class Problem, class Solution>
class FileCacheManager : public CacheManager<Problem, Solution> {
  string fileName;
  unordered_map<string, string> cacheMap;
  fstream cacheFile;

  void createCache(const char *cacheName) override {

    cacheFile.open(cacheName, ios::in | ios::app);
    if (!this->cacheFile.is_open()) {
      throw runtime_error("Can't open file");
    }
  }


   public:


    FileCacheManager() = default;


    void writeToFile(string &fileName) {
      fstream stream(fileName);
      if (!stream.is_open()) {
        throw ("Can't open file");
      }
      for (auto p : cacheMap) {
        //one line -> problem.
        stream << p.first << endl;
        //next line -> solution. (no $).
        stream << p.second << endl;
      }
      stream.close();
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
      this->cacheFile<<problemToWrite<<endl<<solutionToWrite;
      this->cacheMap[problemToWrite] = solutionToWrite;
    }

    bool check(Problem checkProblemExist) override {
//      return (bool)(cacheMap.count(checkProblemExist));
    }

    Solution getSolution(Problem problemToReturn) override {
//      return cacheMap[problemToReturn];
    }

    ~FileCacheManager() {
      if (this->casheFile.is_open()) {
        this->casheFile.close();
      }
    }
  };

#endif //ED2_FILECACHEMANAGER_H

