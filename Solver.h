//
// Created by eliadsellem on 1/6/20.
//

#ifndef MILE_STONE2__SOLVER_H_
#define MILE_STONE2__SOLVER_H_

template<typename P, typename S>
class Solver {
 public:
  virtual Solver *clone() = 0;
  virtual S solve(P problem) = 0;
  virtual ~Solver() {}
};

#endif //MILE_STONE2__SOLVER_H_
