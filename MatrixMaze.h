#ifndef ED2_MATRIXMAZE_H
#define ED2_MATRIXMAZE_H

#include "Searchable.h"
#include <vector>
#include <list>
#include <fstream>

/**
 * Basic data structure to represent searchable matrix.
 * @tparam T - type of data stored.
 */
template <class T>
class MatrixMaze : public Searchable<T> {

  vector<vector<T>>* matrixBase;

 public:

  explicit MatrixMaze (vector<vector<T>>* setMatrix) {
    this->matrixBase = setMatrix;
  }

  State<T> getStartState() override {
    return State<T>(T());
  }
  State<T> getEndState() override {
    return State<T>(T());
  }
  priority_queue<State<T>> getFullState() override {
    return priority_queue<T>();
  }

};
#endif //ED2_MATRIXMAZE_H
