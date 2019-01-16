#ifndef ED2_MANHATTANDISTANCE_H
#define ED2_MANHATTANDISTANCE_H

#include <cmath>
#include "Heuristic.h"
#include "State.h"

template<class T>
class ManhattanDistance : public Heuristic<T> {
private:
    State<T> goalState;

public:
    ManhattanDistance(const State<T> &goalState) : goalState(goalState) {}

    double evaluate(State<T> state) override {
        T position1 = state.getState();
        T position2 = this->goalState.getState();
        double xDistance = abs(position1.first - position2.first);
        double yDistance = abs(position1.second - position2.second);
        return xDistance + yDistance;

    }


};

#endif //ED2_MANHATTANDISTANCE_H
