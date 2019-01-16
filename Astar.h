#ifndef ED2_ASTAR_H
#define ED2_ASTAR_H

#include <set>
#include "BestFirstSearch.h"
#include <unordered_set>
#include "Heuristic.h"

template<class T, class Solution>
class Astar : public BestFirstSearch<T, Solution> {

private:

    Heuristic<T> heuristic;
public:
    Astar(Heuristic<T> h) {
        this->heuristic = h;
    }

    void setDeterminedCost(State<T> *state) override {
        if(state->getCameFrom() == NULL){
            state->setCost(state->getCost()+this->heuristic.evaluate(state));
        } else{

        }
        state->setCost(state->getCameFrom()->getCost() + state->getCost() +
                      this->heuristic.evaluate(state) - this->heuristic.evaluate(state->getCameFrom()));
    }
};

#endif //ED2_ASTAR_H
