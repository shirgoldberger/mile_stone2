//
// Created by shirgold on 12/01/2020.
//

#ifndef MILE_STONE2_DFS_H
#define MILE_STONE2_DFS_H

#include "Searcher.h"
#include <set>

template<class T, class SOLUTION>
class DFS : public Searcher<T, SOLUTION> {
    int time = 0;
    set<State<T> *> used;
    bool flag = false;
    int count = 0;
public:
    // Searcher's abstract method overriding
    SOLUTION search(ISearchable<T> *searchable) {
        searchable->nullify();
        used.clear();
        this->evaluatedNodes = 0;
        count = 0;
        time = 0;
        State<T> *initialState = searchable->getInitialState();
        initialState->setTrailCost(initialState->getCost());
        dfsVisit(initialState, searchable);
        if (!flag) {
            return "no solution";
        }
        // for the next running
        flag = false;
        // return the solution

      return this->printAll(searchable->getGoalState(), searchable);
    }

    void dfsVisit(State<T> *u, ISearchable<T> *searchable) {

        used.insert(u);
        vector<State<T> *> adj = searchable->getAllPossibleState(u);
        // for all the neighbors of u:
        for (State<T> *v : adj) {
            if (v->getCost() < 0) {
                continue;
            }
            if (u == searchable->getGoalState() &&!flag) {
                flag = true;
              this->evaluatedNodes = count;
                return;
            }
            if (used.find(v) == used.end()) {
              count++;
              v->setCameFrom(u);
              v->setTrailCost(u->getTrialCost() + v->getCost());
                dfsVisit(v, searchable);

            }
        }
    }

    ISearcher<T, SOLUTION> *clone() {
        return new DFS();
    }
};

#endif //MILE_STONE2_DFS_H


