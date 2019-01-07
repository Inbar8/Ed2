
#ifndef ED2_SOLVER_H
#define ED2_SOLVER_H
#include <iostream>
using namespace std;


template<class Problem, class Solution>
class Solver {
public:
    virtual Solution solve(Problem problemToSolve) = 0;
};

#endif //ED2_SOLVER_H
