//
// Created by shirgold on 07/01/2020.
//

#ifndef MILE_STONE2_ISEARCHER_H
#define MILE_STONE2_ISEARCHER_H

#include "ISearchable.h"
// T - the type of the representation of the state
template <class T, class SOLUTION>
class ISearcher {
    virtual int getNumberOfNodesEvaluated() = 0;
 public:
  virtual SOLUTION search(ISearchable<T>* searchable) = 0;
  virtual ISearcher* clone() = 0;
  virtual ~ISearcher(){}

};


#endif //MILE_STONE2_ISEARCHER_H
