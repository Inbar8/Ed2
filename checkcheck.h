

#ifndef ED2_CHECKCHECK_H
#define ED2_CHECKCHECK_H
#include "MatrixMaze.h"
#include "Solver.h"
#include <string>
#include <vector>
#include <algorithm>
class checkcheck : public Solver<MatrixMaze<Point>, vector<string>>{

 public:
  vector<string> solve(MatrixMaze<Point> problemToSolve) override{

    State<Point>* start = problemToSolve.getStartState();

    multiset<State<Point>*, comp<Point>> lol = problemToSolve.getFullState(*start);


    return vector<string>();
  }

};
#endif //ED2_CHECKCHECK_H
