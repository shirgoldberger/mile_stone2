//
// Created by eliadsellem on 1/14/20.
//

#ifndef MILE_STONE2__COMPAREFSCORE_H_
#define MILE_STONE2__COMPAREFSCORE_H_

#include "State.h"
template <class T>
class CompareFScore {
   public:
    // compare two states according to the fScore
    bool operator()(State<T> *s1, State<T> *s2) {
      return (s1->getFScore() > s2->getFScore());
    }
    ~CompareFScore(){}
};

#endif //MILE_STONE2__COMPAREFSCORE_H_
