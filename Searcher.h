//
// Created by shirgold on 07/01/2020.
//

#ifndef MILE_STONE2_SEARCHER_H
#define MILE_STONE2_SEARCHER_H

#include "CompareFScore.h"
#include "ISearcher.h"
#include <queue>

using namespace std;

// T - the type of the representation of the states
template<typename T, typename SOLUTION>
class Searcher : public ISearcher<T, SOLUTION> {
protected:
    int evaluatedNodes;
    /*
     * the function returns the solution of the algorithm:
     * calculates the steps from the initial state to the goal state
     */
     string printAll(State<T>* goalState, ISearchable<T>* searchable) {
        vector<string> steps;
        State<T>* son = goalState;
        State<T>* father = son->getCameFrom();
        // while we don't arrive to the initial state
        while (father != nullptr) {
            string s = searchable->printOne(son);
            steps.push_back(s);
            son = father;
            father = son->getCameFrom();
        }
        string solution = "";
        // save in solution all the steps
        for (string s : steps) {
            solution = s + solution;
        }
        return solution.substr(0, solution.length() - 2);
    }
public:
    // constructor
    Searcher() {
        evaluatedNodes = 0;
    }

    int getNumberOfNodesEvaluated() {
        return evaluatedNodes;
    }

    virtual SOLUTION search(ISearchable<T>* searchable) = 0;
};

#endif //MILE_STONE2_SEARCHER_H
