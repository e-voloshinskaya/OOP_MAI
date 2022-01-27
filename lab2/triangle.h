#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>

#include "figure.h"

class Triangle : public Figure {

public:
  Triangle();
  Triangle(Point a, Point b, Point c);
  Triangle(std::istream &is);
  Triangle(const Triangle& other);

  Triangle &operator=(const Triangle &other);
  bool operator==(const Triangle &other);
  friend std::istream& operator>>(std::istream& is, Triangle& o);
  friend std::ostream& operator<<(std::ostream& os, const Triangle& t);


  size_t VertexesNumber();
  double Area();
  void Print(std::ostream& os);

  virtual ~Triangle();

private:
  Point p1;
  Point p2;
  Point p3;
};

#endif // TRIANGLE_H
