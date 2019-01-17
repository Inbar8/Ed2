#ifndef ED2_FILECACHEMANAGER_H
#define ED2_FILECACHEMANAGER_H
#include <string>
#include <fstream>
#include <unordered_map>
#include "protocols/Protocol.h"
#include "CacheManager.h"
#include <list>
#define TOKEN "$"
using namespace std;

template<class Problem, class Solution>
class FileCacheManager : public CacheManager<Problem, Solution> {
  unordered_map<Problem, Solution> cacheMap;
  fstream cacheFile;
  Protocol<Problem>* problemP;
  Protocol<Solution>* solutionP;
  void createCache(const char *cacheName) override {

    this->cacheFile.open(cacheName,
                   std::fstream::in | std::fstream::out | std::fstream::app);
    if (!this->cacheFile.is_open()) {
      throw runtime_error("Problem in opening file");
    }
    if (this->cacheFile.peek() != std::fstream::traits_type::eof()) {

      this->cacheFile.seekg(0, fstream::beg);

      bool readProblem = false;

      string temp, problem;
      string stringToReturn;

      while (getline(this->cacheFile, temp)) {

        if (temp == (TOKEN) & !readProblem) {
          problem = stringToReturn;
          readProblem = true;
          stringToReturn.clear();

        } else if (temp == (TOKEN) & readProblem) {
          Solution* s = this->solutionP->readProtocol(stringToReturn);
          this->cacheMap[*this->problemP->readProtocol(problem)] = *s;
          readProblem = false;
          problem.clear();
          stringToReturn.clear();
        } else if (temp == (TOKEN)) {
          temp.clear();
        } else {
          stringToReturn += temp;
          stringToReturn += "\n";
          temp.clear();
        }
      }
      }    cout<<endl;

  }

 public:

  FileCacheManager(Protocol<Problem>* setProblem,
      Protocol<Solution>* setSolution) :
      problemP(setProblem), solutionP(setSolution) {};

  void save(Problem problemToWrite, Solution solutionToWrite) override {
    this->cacheFile<<this->problemP->writeProtocol(problemToWrite)<<
    TOKEN<<this->solutionP->writeProtocol(solutionToWrite)<<TOKEN;
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
      delete problemP;
      delete solutionP;
    }
  };

#endif //ED2_FILECACHEMANAGER_H

