#ifndef ED2_FILECACHEMANAGER_H
#define ED2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

////
class FileCacheManager : public CacheManager<string, string> {
    string fileName;
    unordered_map<string, string> cacheMap;

public:
    FileCacheManager(const string &fileName,
                     const unordered_map<string, string> &cacheMap) : fileName(
            fileName), cacheMap(cacheMap) {}

public:
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

    void save(string saveProblem,string saveSolution) override {
        cacheMap[saveProblem] = saveSolution;
    }

    bool check(string checkProblemExist) override {
        return (bool)(cacheMap.count(checkProblemExist));
    }


    string getSolution(string problemToReturn) override {
        return cacheMap[problemToReturn];
    }

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
