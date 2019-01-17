
#ifndef ED2_PROTOCOLMATRIX_H
#define ED2_PROTOCOLMATRIX_H
#include <sstream>
#include "Protocol.h"
#include "../MatrixMaze.h"
#define SPACE ' '

class ProtocolMatrix : public Protocol<MatrixMaze<Point>> {

  Point singleVectorPoint(vector<int>& vectorPoint) {
    if (vectorPoint.size() != POINT_ARGS) {
      throw invalid_argument("Start or end points invalid");
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


  MatrixMaze<Point>* readProtocol(string readMatrix) override {
    auto* matrixBase = new vector<vector<int>>;

    readMatrix.erase(std::remove(readMatrix.begin(), readMatrix.end(), SPACE),
        readMatrix.end());
    stringstream streamMatrix(readMatrix);

    int row;
    vector<int> line;
    while (streamMatrix >> row) {

      line.push_back(row);

      if (streamMatrix.peek() == ',' | streamMatrix.peek() == SPACE) {
        streamMatrix.ignore();
      }

      if (streamMatrix.peek() == '\n') {

        matrixBase->push_back(line);
        line.clear();
      }

    }

    Point end = this->singleVectorPoint(matrixBase->back());
    matrixBase->pop_back();

    Point start = this->singleVectorPoint(matrixBase->back());
    matrixBase->pop_back();

    if (start.x < 0 | start.x > matrixBase[0].size()
    | start.y < 0 | start.y > matrixBase->size()) {
      throw invalid_argument("Point start/end invalid");
    }

    return new MatrixMaze<Point>(matrixBase, start, end);
  }
  string writeProtocol(MatrixMaze<Point> writeThis) override {
    vector<vector<int>> *pointTo = writeThis.getMatrix();
    string returnVector;
    for (const vector<int> &line : *pointTo) {

      for (int row : line) {

        returnVector += to_string(row);
        returnVector += ",";
      }
      returnVector.pop_back();
      returnVector += "\n";

    }
    State<Point> *states = writeThis.getStartState();

    Point startToString = states->getState();
    returnVector += this->pointToString(startToString);
    delete states;

    states = writeThis.getEndState();

    Point endToString = states->getState();
    returnVector += this->pointToString(endToString);
    delete states;

    return returnVector;
  }

};


#endif //ED2_PROTOCOLMATRIX_H
