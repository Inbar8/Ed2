#ifndef ED2_MATRIXMAZE_H
#define ED2_MATRIXMAZE_H

#include "Searchable.h"
#include <vector>
#include <list>
#include <fstream>
#define POINT_ARGS 2
#define WALL -1
struct Point {
  int x, y;

  explicit Point(int setX, int setY) {
  this->x = setX;
  this->y = setY;
  }
  int getX() const {
    return this->x;
  }
  int getY() const {
    return this->y;
  }
};
/**
 * Basic data structure to represent searchable matrix.
 * @tparam T - type of data stored.
 */
template <class T>
class MatrixMaze : public Searchable<T> {


  vector<vector<int>>* matrixBase;
  T start, end;


 public:

  explicit MatrixMaze (vector<vector<int>>* setMatrix, T setStart,
      T setEnd) : start(setStart), end(setEnd), matrixBase(setMatrix) {}

  State<T> getStartState() override {
    return State<T>(this->start);
  }
  State<T> getEndState() override {
    return State<T>(this->end);
  }


  priority_queue<State<T>> getFullState(const State<T>& findAdj) override {

    unsigned int lineX = findAdj.getState().getX();
    unsigned int  rowY = findAdj.getState().getY();

//    auto compare = [](State<T> lhs, State<T> rhs) {
//      return lhs.getCost() < rhs.getCost();
//    };

   // priority_queue<State<T>, vector<int>, decltype(compare)> returnList(compare);
    priority_queue<State<T>> returnList;
    if (lineX == 0 & this->matrixBase->at(lineX--).at(rowY) != WALL) {
      State<Point> left(Point(lineX--, rowY));
      left.setCost(this->matrixBase->at(lineX--).at(rowY));
      returnList.emplace(left);
    }
    if (lineX == this->matrixBase[0].size()
        & this->matrixBase->at(lineX++).at(rowY) != WALL) {
      State<Point> right(Point(lineX++, rowY));
      right.setCost(this->matrixBase->at(lineX++).at(rowY));
      returnList.emplace(right);
    }

    if (rowY == 0 & this->matrixBase->at(lineX).at(rowY--) != WALL) {

      State<Point> down(Point(lineX, rowY--));
      down.setCost(this->matrixBase->at(lineX).at(rowY--));
      returnList.emplace(down);
    }

    if (rowY == this->matrixBase->size()
        & this->matrixBase->at(lineX).at(rowY++)!= WALL) {

      State<Point> up(Point(lineX, rowY++));
      up.setCost(this->matrixBase->at(lineX).at(rowY++));
      returnList.emplace(up);
    }

    return returnList;
  }
  vector<vector<int>>* getMatrix() {
    return this->matrixBase;
  }

};
#endif //ED2_MATRIXMAZE_H
