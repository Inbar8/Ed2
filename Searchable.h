#ifndef ED2_SEARCHABLE_H
#define ED2_SEARCHABLE_H
#include "State.h"
#include <queue>

using namespace std;

template <class T>
class Searchable {


 public:

  virtual State<T> getStartState() const = 0;

  virtual State<T> getEndState() const = 0;

  virtual priority_queue<State<T>> getFullState(const State<T>&) const = 0;
};



#endif //ED2_SEARCHABLE_H
