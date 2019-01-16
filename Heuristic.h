#ifndef ED2_HEURISTIC_H
#define ED2_HEURISTIC_H

#include "State.h"

template <class T>
class Heuristic{
public:
    virtual double evaluate(State<T> state);
};


#endif //ED2_HEURISTIC_H
