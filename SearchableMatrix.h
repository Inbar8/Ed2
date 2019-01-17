

#ifndef ED2_SEARCHABLEMATRIX_H
#define ED2_SEARCHABLEMATRIX_H

#include "MatrixMaze.h"
template<class T>
class SearchableMatrix : public Searchable<T>, public MatrixMaze<Point> {


  MatrixMaze<T>* matrixBase;


 public:

  explicit SearchableMatrix(MatrixMaze<T>* matrix) : matrixBase(matrix){};

  State<T> *getStartState() const override {
    return matrixBase->getStartState();
  }
  State<T> *getEndState() const override {
    return matrixBase->getEndState();
  }

  multiset<State<T>*, comp<T>> getFullState(
      const State<T> *state) override {
    return matrixBase->getFullState(state);
  }
};

#endif //ED2_SEARCHABLEMATRIX_H
