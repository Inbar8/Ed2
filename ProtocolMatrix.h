
#ifndef ED2_PROTOCOLMATRIX_H
#define ED2_PROTOCOLMATRIX_H

#include <sstream>
#include "Protocol.h"
#include "MatrixMaze.h"

class ProtocolMatrix : public Protocol<MatrixMaze<Point>> {

  Point singleVectorPoint(vector<int>& vectorPoint) {
    if (vectorPoint.size() != POINT_ARGS) {
      throw invalid_argument("Bad matrix point set");
    }
    return Point(vectorPoint.front(), vectorPoint.back());
  }
  string pointToString(Point& convert) {
    string returnString;
    returnString += std::to_string(convert.x);
    returnString += ",";
    returnString += std::to_string(convert.y);
    returnString += "\n";
    return returnString;
  }

 public:


  MatrixMaze<Point> readProtocol(string readMatrix) override {
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
    Point start = this->singleVectorPoint(matrixBase->back());
    matrixBase->pop_back();

    Point end = this->singleVectorPoint(matrixBase->back());
    matrixBase->pop_back();


    return MatrixMaze<Point>(matrixBase, start, end);
  }
  string writeProtocol(MatrixMaze<Point> writeThis) override {
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
//    Point startToString = writeThis.getStartState().getState();
    //returnVector += this->pointToString(startToString);
   // Point endToString = writeThis.getEndState().getState();
//    returnVector += this->pointToString(endToString);

    return returnVector;
  }

};


#endif //ED2_PROTOCOLMATRIX_H
