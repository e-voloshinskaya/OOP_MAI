#include "triangle.h"

#include <iostream>
#include <cmath>

Triangle::Triangle()
    : side_a(0.0), side_b(0.0), side_c(0.0) {
  std::cout << "Default triangle created" << std::endl;
}

Triangle::Triangle(double a, double b, double c)
    : side_a(a), side_b(b), side_c(c) {
  std::cout << "Triangle created: " << side_a << ", " << side_b << ", " << side_c << std::endl;
}

Triangle::Triangle(std::istream &is) {
  is >> side_a >> side_b >> side_c;
}

Triangle::Triangle(const Triangle& other)
    : Triangle(other.side_a, other.side_b, other.side_c) {
  std::cout << "Triangle copy created" << std::endl;
}

double Triangle::Area() {
  double p = (side_a + side_b + side_c) / 2.0;
  return std::sqrt(p * (p - side_a) * (p - side_b) * (p - side_c));
}

void Triangle::Print(std::ostream& os) {
  os << "a = " << side_a << ", ";
  os << "b = " << side_b << ", ";
  os << "c = " << side_c << std::endl;
}

Triangle::~Triangle() {
  std::cout << "Triangle deleted" << std::endl;
}
