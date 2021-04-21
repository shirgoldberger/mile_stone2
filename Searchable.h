//
// Created by shirgold on 07/01/2020.
//
#ifndef MILE_STONE2_SEARCHABLE_H
#define MILE_STONE2_SEARCHABLE_H

#include <unordered_map>
#include "ISearchable.h"
#include <vector>
template<class T>
class Searchable : public ISearchable<T> {
protected:
    State<T> *goalState;
    State<T> *initialState;
public:
    Searchable() {}
    // getters and setters
    virtual State<T>* getInitialState() {
        return this->initialState;
    }
    virtual State<T>* getGoalState() {
        return this->goalState;
    }
    virtual void setInitialState(State<T>* initial) {
        this->initialState = initial;
    }
    virtual void setGoalState(State<T>* goal) {
        this->goalState = goal;
    }
};
#endif //MILE_STONE2_SEARCHABLE_H