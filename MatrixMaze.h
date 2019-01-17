#ifndef ED2_MATRIXMAZE_H
#define ED2_MATRIXMAZE_H

#include "Searchable.h"
#include <vector>
#include <list>
#include <fstream>
#include <unordered_map>
#include <algorithm>
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
  friend bool operator==(const Point& rightP,const Point& leftP) {
    return rightP.x == leftP.getX() && rightP.y == leftP.getY();
  }
};




/**
 * Basic data structure to represent searchable matrix.
 * @tparam T - type of data stored.
 */
template <class T>
class MatrixMaze : public Searchable<Point> {


  vector<vector<int>>* matrixBase;
  T start, end;


 public:

  explicit MatrixMaze (vector<vector<int>>* setMatrix, T setStart,
      T setEnd) : start(setStart), end(setEnd), matrixBase(setMatrix) {}

  State<T>* getStartState() const override  {
    return new State<T>(this->start);
  }
  State<T>* getEndState() const override  {
    return new State<T>(this->end);
  }

  multiset<State<T>*, comp<T>> getFullState(const State<T>* findAdj)  override {

    try {
      const unsigned int x = findAdj->getState().getX();
      const unsigned int y = findAdj->getState().getY();

      multiset<State<T>*, comp<T>> returnList;

      if (x > 0 && (this->matrixBase->at(y).at(x - 1) != WALL)) {
        State<Point>* left = new State<Point>(Point(x - 1, y));
        left->setCost(this->matrixBase->at(y).at(x - 1));
        returnList.emplace(left);
      }
      if (x < (this->matrixBase->at(y).size() - 1)
          && (this->matrixBase->at(y).at(x + 1) != WALL)) {
        State<Point>* right = new State<Point>(Point(x + 1, y));
        right->setCost(this->matrixBase->at(y).at(x + 1));
        returnList.emplace(right);
      }

      if (y > 0 && (this->matrixBase->at(y - 1).at(x) != WALL)) {

        State<Point>* up = new State<Point>(Point(x, y - 1));
        up->setCost(this->matrixBase->at(y - 1).at(x));
        returnList.emplace(up);
      }

      if (y < (this->matrixBase->size() - 1)
          && (this->matrixBase->at(y + 1).at(x) != WALL)) {

        State<Point>* down = new State<Point>(Point(x, y + 1));
        down->setCost(this->matrixBase->at(y + 1).at(x));
        returnList.emplace(down);
      }

      return returnList;

    } catch(...) {
      throw invalid_argument("Problem in returning adj");
    }
  }
  vector<vector<int>>* getMatrix() const {
    return this->matrixBase;
  }

  friend bool operator==(const MatrixMaze<Point>& left, const MatrixMaze<Point>& right) {
    return ((left.getStartState() == right.getStartState()) &
        (left.getEndState() == right.getEndState()) &
        (left.getMatrix() == right.getMatrix()));
  }


};

namespace std {
template<>
struct hash<MatrixMaze<Point>> {
  typedef std::size_t result_hash;

  result_hash operator()(MatrixMaze<Point> const &s) const noexcept {
    State<Point>* pointTo = s.getStartState();

    result_hash h1 = std::hash<int>{}(
        (pointTo->getState().getX() << 1) ^
            pointTo->getState().getY());

    delete pointTo;

    pointTo = s.getEndState();
    result_hash h2 = std::hash<int>{}(
        (pointTo->getState().getX() << 1) ^
            pointTo->getState().getY());

    delete pointTo;

    string hashIt;
    for (const vector<int> &vector : *(s.getMatrix())) {
      for (int ij : vector) {
        hashIt += std::to_string(ij);
      }
    }
    result_hash h3 = std::hash<std::string>{}(hashIt);
    return h1 ^ h3 ^ (h2 << 1);
  }


};
}

#endif //ED2_MATRIXMAZE_H
