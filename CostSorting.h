#ifndef ED2_COSTSORTING_H
#define ED2_COSTSORTING_H

#include "State.h"

template <class T>
class CostSorting{
public:
    bool operator()(State<T>* state1, State<T>* state2)const {
        return state1->getCost() < state2->getCost();
    }
};
#endif //ED2_COSTSORTING_H
