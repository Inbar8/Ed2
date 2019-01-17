
#ifndef ED2_SOLVER_H
#define ED2_SOLVER_H
#include <iostream>
#include "Searchable.h"
using namespace std;


template<class Problem, class Solution>
class Solver {
public:
    virtual Solution solve(Problem* problemToSolve) = 0;
};

#endif //ED2_SOLVER_H





/**
 * #include "unordered_set"
#include <list>
#include <vector>
using namespace std;


class matrixProblem : public ISearchable<vector<int>>
{
    vector<vector<int>> matrix;
    int length;
    int width;
    vector<int> initState;
    vector<int> goalState;

public:
    matrixProblem(vector<string> mat, vector<int> initState, vector<int> goalState)
    {
        vector<vector<int>> tempMat;
        for (auto it = mat.begin(); it != mat.end(); it++)
        {
            vector<int> line;
            vector<string> values = splitLine(*it,",");
            for (auto it = values.begin(); it != values.end(); it++)
            {
                line.push_back(std::stoi(*it));
            }
            tempMat.push_back(line);
        }

        this->matrix = tempMat;
        this->length = tempMat.size();
        this->width = tempMat[0].size();
        this->initState = initState;
        this->goalState = goalState;
    }

    virtual State<vector<int>> getInitialState()
    {
  /      State<vector<int>> s = State<vector<int>>(initState,0,NULL);
        return s;
    }

    virtual bool isGoalState(State<vector<int>> curState)
    {
        if (curState.getState() == goalState)
            return true;
        else
            return false;
    }

    virtual list<State<vector<int>>> getAllPossibleStates(State<vector<int>> s)
    {
        int minCol = 0;
        int maxCol = width-1;
        int minRow = 0;
        int maxRow = length-1;
        int i = s.getState()[0];
        int j = s.getState()[1];
        list<State<vector<int>>> posStates;

        if (i-1 >= minRow)
        {
            vector<int> up = {i - 1, j};
            State<vector<int>> upState = State<vector<int>>(up,s.getCost() + matrix[i-1][j], &s);
            posStates.push_back(upState);
        }

        if (i+1 <= maxRow)
        {
            vector<int> down = {i + 1, j};
            State<vector<int>> downState = State<vector<int>>(down,s.getCost() + matrix[i+1][j], &s);
            posStates.push_back(downState);
        }

        if (j-1 >= minCol)
        {
            vector<int> left = {i, j - 1};
            State<vector<int>> leftState = State<vector<int>>(left,s.getCost() + matrix[i][j-1], &s);
            posStates.push_back(leftState);
        }

        if ((j+1) <= maxCol)
        {
            vector<int> right = {i, j + 1};
            State<vector<int>> rightState = State<vector<int>>(right,s.getCost() + matrix[i][j+1], &s);
            posStates.push_back(rightState);
        }

        return posStates;
    }

    vector<string> splitLine(string s,string parser)
    {
        vector<string> vec;
        while(s.size() > 0)
        {
            int i = s.find(parser);
            if (i != string::npos)
            {
                vec.push_back(s.substr(0, i)); //We push the string between the parser appearences into the vector
                s = s.substr(i + parser.size());
                if (s.size() == 0)
                {
                    vec.push_back(s);
                }
            }

            else
            {
                vec.push_back(s);
                s="";
            }
        }
        return vec;
    }

};
 */
