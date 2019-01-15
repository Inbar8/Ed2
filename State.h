
#ifndef ED2_STATE_H
#define ED2_STATE_H
#include <unordered_map>
#include <queue>
using namespace std;



template<class T>
class State {
 private:
  T state;
  double cost = 0;
  State<T> *cameFrom;

 public:
  explicit State<T>(T st) : state(st) {}

  T getState() const {
      return state;
  }
  void setCost(double costSet) {
      this->cost = costSet;
  }

  double getCost() {
      return this->cost;
  }
  State<T> &getCameFrom() const {
      return this->cameFrom;
  }

  void setState(T state) {
      this->state = state;
  }

  void setCameFrom(const State &setCameFrom) {
      this->cameFrom = setCameFrom;
  }

  bool operator==(const State<T>& equalCheck) const {
      return this->state == equalCheck.state & this->cost == equalCheck.cost;
  }

  bool operator<(const State<T>& equalCheck) const {
      return this->cost < equalCheck.cost;
  }

};

template <class T>
struct comp {
  bool operator()(State<T> *comp1, State<T> *comp2) {
    return comp1->getCost() < comp2->getCost();
  }
};

#endif //ED2_STATE_H
