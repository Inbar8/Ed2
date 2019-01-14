
#ifndef ED2_PROTOCOLMATRIX_H
#define ED2_PROTOCOLMATRIX_H

#include <sstream>
#include "Protocol.h"
#include "MatrixMaze.h"

class ProtocolMatrix : public Protocol<MatrixMaze<int>> {



 public:


  MatrixMaze<int> readProtocol(string readMatrix) override {
    auto* matrixBase = new vector<vector<int>>;


    stringstream streamMatrix(readMatrix);

    int row;
    vector<int> line;
    while (streamMatrix >> row) {

      line.push_back(row);

      if (streamMatrix.peek() == ',')
        streamMatrix.ignore();
      if (streamMatrix.peek() == '\n') {

        matrixBase->push_back(line);
        line.clear();

      }
    }
    return MatrixMaze<int>(matrixBase);
  }
  string writeProtocol(MatrixMaze<int> writeThis) override {
    vector<vector<int>>* pointTo = writeThis.getMatrix();
    string returnVector;
    for (const vector<int> &line : *pointTo) {

      for (int row : line) {

        returnVector += to_string(row);
        returnVector += ",";
      }
      returnVector.pop_back();
      returnVector += "\n";

    }
    returnVector += "$";
    return returnVector;
  }

};


#endif //ED2_PROTOCOLMATRIX_H
