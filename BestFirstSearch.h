
#ifndef ED2_BESTFIRSTSEARCH_H
#define ED2_BESTFIRSTSEARCH_H

#include <vector>
#include <set>
#include "SearchAlgorithm.h"
#include <unordered_set>
#include "State.h"

template<class T, class Solution>
class BestFirstSearch : public SearchAlgorithm<T, Solution> {


public:
/**
 * best first search.
 */
    Solution search(Searchable<T> *problemToSolve) override {

        multiset<State<T> *, comp<T>> openList;

        openList.insert(problemToSolve->getStartState());

        multiset<State<T> *, comp<T>> closedList; // = new multiset<State<Problem>>();

        while (openList.size() > 0) {
            State<T> *node = *openList.begin();
            openList.erase(openList.begin());
            closedList.insert(node);
            if (node->getState() == problemToSolve->getEndState()->getState()) {
                while(node != nullptr){
                    cout << node->getCost()<< endl;
                    node = node->getCameFrom();
                }
                cout << endl;
                //   return this->backTrace(node);
            }
            multiset<State<T> *, comp<T>> successors = problemToSolve->getFullState(
                    node);
            for (State<T> *s: successors) {
                if (!contains(s, closedList) && (!contains(s, openList))) {
                    s->setCameFrom(node);
                    this->setDeterminedCost(s);
                    openList.insert(s);

                    //found in closed list but not in open list.
                } else if ((!contains(s, openList))) {
                    s->setCameFrom(node);
                    this->setPriority(node, closedList);
                }
            }
        }
    }


    void
    setPriority(State<T> *state, multiset<State<T> *, comp<T>> &closedList) {
        State<T> *found = *(closedList.find(state));
        double cost = found->getCost();
        if (cost >= state->getCost()) {
            found->setCost(state->getCost());
        }
    }

    virtual void setDeterminedCost(State<T> *state) {
        state->setCost(state->getCameFrom()->getCost() + state->getCost());
    }

    virtual bool contains(const State<T> *stateToCheck,
                          multiset<State<T> *, comp<T>> multiCheck) const {
        for (auto iter = multiCheck.begin(); iter != multiCheck.end(); ++iter) {
            if ((*iter)->getState() == stateToCheck->getState()) {
                return true;
            }
        }
        return false;
    }

};


#endif //ED2_BESTFIRSTSEARCH_H


/**
 * ‘std::vector<State<MatrixMaze<Point> >*, std::allocator<State<MatrixMaze<Point> >*> >’
 * ‘std::vector<std::__cxx11::basic_string<char> >’
 */
