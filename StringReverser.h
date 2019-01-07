#ifndef ED2_STRINGREVERSER_H
#define ED2_STRINGREVERSER_H

#include "Solver.h"
#include <string>
class StringReverser : public Solver<string, string>{

public:
  string solve(string problemToSolve) override;

};

#endif //ED2_STRINGREVERSER_H
