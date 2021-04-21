//
// Created by eliadsellem on 1/9/20.
//

#ifndef MILE_STONE2__SOLVERSEARCH_H_
#define MILE_STONE2__SOLVERSEARCH_H_

#include <iostream>
#include "Solver.h"
#include "Searcher.h"

// T - the type of the representation of the states
template<typename SOLUTION, typename T>
class SolverSearch : public Solver<ISearchable<T>*, SOLUTION> {
    ISearcher<T, SOLUTION> *searcher;
public:
    // constructor
    SolverSearch(ISearcher<T, SOLUTION> *s) {
        this->searcher = s;
    }
    /*
     * solve the problem by the search algorithm
     */
    virtual SOLUTION solve(ISearchable<T>* problem) {
        return this->searcher->search(problem);
    }
    Solver<ISearchable<T>*,SOLUTION>* clone(){
      return new SolverSearch(searcher->clone());
    }
};

#endif //MILE_STONE2__SOLVERSEARCH_H_
