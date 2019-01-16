
#ifndef ED2_SEARCHALGORITHM_H
#define ED2_SEARCHALGORITHM_H

#include <vector>
#include "Searcher.h"
using namespace std;
template<class T, class Solution>
class SearchAlgorithm : public Searcher<T, Solution> {
    bool visited;
    uint64_t counter = 0;

protected:

    virtual uint64_t getNumOfNodesEvaluated() {

        return this->counter;
    }

    void setCounter(uint64_t counter) {
        SearchAlgorithm::counter = counter;
    }


    virtual void counterPlusPlus() {
        ++counter;
    }

    bool getVisited() const {
        return visited;
    }


    void setVisited(bool visited) {
        SearchAlgorithm::visited = visited;
    }

    //Solution = vec<State<T>*>
    vector<T> backTrace(State<T> *stateToStartFrom){
        vector<T> vecToReturn;
        T point;
        while(stateToStartFrom != nullptr){
            point = stateToStartFrom->getState();
            vecToReturn.push_back(point);
            stateToStartFrom = stateToStartFrom->getCameFrom();
        }
        return vecToReturn;
    }
};

#endif //ED2_SEARCHALGORITHM_H
