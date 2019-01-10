#ifndef ED2_BFS_H
#define ED2_BFS_H

#include "Searcher.h"

template <class Problem, class Solution>
class BFS : public Searcher<Problem, Solution>{

public:
    Solution search(Searchable<Problem> problemToSolve) override {
        return nullptr;
    }
};

#endif //ED2_BFS_H
