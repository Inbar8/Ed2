#ifndef ED2_SOLVERALGORITHMS_H
#define ED2_SOLVERALGORITHMS_H
#include "SearchableMatrix.h"

#include "BestFirstSearch.h"
#include "BFS.h"
#include "DFS.h"
#include "Astar.h"
#include "Solver.h"

template <class Problem, class Solution>
class SolverAlgorithms : public Solver<Problem,Solution> {
  Searcher<Problem, Solution> *solver;
 public:
  explicit SolverAlgorithms(Searcher<Problem, Solution> *sa) {
      this->solver = sa;
  }

  Solution solve(Problem* problemToSolve) override {

    //auto * matrixToSearch
    //= new SearchableMatrix<Point>(problemToSolve);
  //    solver->search(matrixToSearch);
  }

};

#endif //ED2_SOLVERALGORITHMS_H
