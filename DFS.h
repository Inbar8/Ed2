#ifndef ED2_DFS_H
#define ED2_DFS_H


#include "Searcher.h"

template <class Problem, class Solution>
class DFS : public Searcher<Problem, Solution> {

public:
    Solution search(Searchable<Problem> problemToSolve) override {
        return nullptr;
    }
};
#endif //ED2_DFS_H
