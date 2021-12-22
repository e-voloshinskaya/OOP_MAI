#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>

#include "figure.h"

class Triangle : public Figure {
public:
  Triangle();
  Triangle(double a, double b, double c);
  Triangle(std::istream &is);
  Triangle(const Triangle& other);

  double Area();
  void Print(std::ostream& os);

  virtual ~Triangle();

private:
  double side_a;
  double side_b;
  double side_c;
};

#endif // TRIANGLE_H
