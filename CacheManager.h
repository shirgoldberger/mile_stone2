//
// Created by eliadsellem on 1/6/20.
//

#ifndef MILE_STONE2__CACHEMANAGER_H_
#define MILE_STONE2__CACHEMANAGER_H_
using namespace std;
template<typename P, typename S>
class CacheManager {
 public:
  virtual S getSolution(P problem) = 0;
  virtual void saveSolution(P problem, S& solution) = 0;
  virtual bool isSolved(P problem) = 0;
  virtual ~CacheManager(){}
};
#endif //MILE_STONE2__CACHEMANAGER_H_
