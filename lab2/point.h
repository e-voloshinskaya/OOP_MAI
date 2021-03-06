#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {

friend std::istream& operator>>(std::istream& is, Point& p);
friend std::ostream& operator<<(std::ostream& os, const Point& p);

public:
  Point();
  Point(double x, double y);
  Point(std::istream &is);

  bool operator==(const Point &other);
  double dist(Point& other);
  
private:
  double x_;
  double y_;
};

#endif // POINT_H