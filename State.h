
#ifndef ED2_STATE_H
#define ED2_STATE_H

using namespace std;

template<class T>
class State {
    T state;
    double cost;
    State<T> cameFrom;

public:
    State(T st) { this->state = st; }

    T getState() const {
        return state;
    }

    const State &getCameFrom() const {
        return cameFrom;
    }

    void setState(T state) {
        State::state = state;
    }

    void setCameFrom(const State &cameFrom) {
        State::cameFrom = cameFrom;
    }
};

#endif //ED2_STATE_H
