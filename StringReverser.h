#ifndef ED2_STRINGREVERSER_H
#define ED2_STRINGREVERSER_H

#include "Solver.h"
#include <string>
#include <algorithm>
class StringReverser : public Solver<string, string>{

public:
  string solve(string problemToSolve) override{
      string toReturn = problemToSolve;
      reverse(toReturn.begin(), toReturn.end());
      return toReturn;
  }

};

#endif //ED2_STRINGREVERSER_H
