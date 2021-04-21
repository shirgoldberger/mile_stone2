//
// Created by eliadsellem on 1/9/20.
//

#ifndef MILE_STONE2__POINT_H_
#define MILE_STONE2__POINT_H_

class Point {
  double x;
  double y;
 public:
  Point(double x_, double y_){
    x = x_;
    y = y_;
  }
  double getX()  {
    return x;
  }
  double getY()  {
    return y;
  }
  bool operator==(Point &p) {
      return (this->x == p.getX() && this->y == p.getY());
  }
  ~Point(){}
};

#endif //MILE_STONE2__POINT_H_
