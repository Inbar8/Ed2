#ifndef ED2_MATRIXMAZE_H
#define ED2_MATRIXMAZE_H

#include "Searchable.h"
#include <vector>
#include <fstream>
template <class T>
class MatrixMaze : public Searchable<T> {

  vector<vector<T>> matrixBase;

  vector<vector<string>> getMatrixAsString() {
    vector<vector<string>> vectorToReturn;

    for (vector<T> addLine : this->matrixBase) {
      vector<string> vectorLine;
      for (T addVariable : addLine) {
     //   vectorLine.push_back((T));
      }


    }
  }

 public:

  MatrixMaze () {

  }

  State<T> getStartState() override {
    return State<T>(T());
  }
  State<T> getEndState() override {
    return State<T>(T());
  }
  priority_queue<T> getFullState() override {
    return priority_queue<T>();
  }

  friend ofstream &operator<<(ofstream & outPutStream, MatrixMaze & outputIt) {




  }

};
#endif //ED2_MATRIXMAZE_H
