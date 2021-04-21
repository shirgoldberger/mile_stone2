//
// Created by shirgold on 12/01/2020.
//

#ifndef MILE_STONE2_BFS_H
#define MILE_STONE2_BFS_H

#include <set>
#include "Searcher.h"

template<class T, class SOLUTION>
class BFS : public Searcher<T, SOLUTION> {
    queue<State<T> *> myQueue;
    // for know if we used this state or not
    set<State<T> *> used;
public:
    // Searcher's abstract method overriding
    SOLUTION search(ISearchable<T> *searchable) {
        searchable->nullify();
        used.clear();
        this->evaluatedNodes = 0;
        State<T> *initialState = searchable->getInitialState();
        initialState->setTrailCost(initialState->getCost());
        used.insert(initialState);
        addToQueue(initialState);
        while (!myQueue.empty()) {
            State<T> *u = popQueue();
            vector<State<T> *> adj = searchable->getAllPossibleState(u);
            for (State<T> *v : adj) {
                if (v->getCost() < 0) {
                    continue;
                }
                // we don't arrive to this state before
                if (used.find(v) == used.end()) {
                    used.insert(v);
                    v->setTrailCost(u->getTrialCost() + v->getCost());
                    v->setCameFrom(u);
                    addToQueue(v);
                }
                // arrive to goal state
                if (v == searchable->getGoalState()) {
                    string s = this->printAll(searchable->getGoalState(), searchable);
                  return s;
                }
            }
        }
        clearQueue();
            return "no solution";

    }

    /*
     * the function pop from the queue and updates the evaluated Nodes.
     */
    State<T> *popQueue() {
        this->evaluatedNodes++;
        if (myQueue.empty()) {
            return nullptr;
        }
        auto top = myQueue.front();
        myQueue.pop();
        return top;
    }

    /*
     * the function inserts the state to the queue
     */
    void addToQueue(State<T> *state) {
        myQueue.push(state);
    }

    /*
     * the function clear the queue for the next running
     */
    void clearQueue() {
        while (!myQueue.empty()) {
            myQueue.pop();
        }
    }


    ISearcher<T, SOLUTION> *clone() {
        return new BFS();
    }
};


#endif //MILE_STONE2_BFS_H
