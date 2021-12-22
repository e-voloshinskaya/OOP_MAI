#include <iostream>

#include "triangle.h"

int main(int argc, char** argv) {
  Triangle a;
  a.Print(std::cout);

  Triangle b(3, 4, 5);
  b.Print(std::cout);
  std::cout << b.Area() << std::endl;

  Triangle c(std::cin);
  c.Print(std::cout);

  Triangle d = b;
  d.Print(std::cout);

  Figure* ptr = new Triangle(c);
  ptr->Print(std::cout);
  std::cout << "squre: " << ptr->Area() << std::endl;
  delete ptr;

  return 0;
}
