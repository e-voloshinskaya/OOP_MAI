#include <iostream>
#include "britishmoney.h"

int main(void) {

    double arg;

    BMoney a1(std::cin);
    BMoney a2(std::cin);
    std::cin >> arg;
    (a1.Multiply_real(arg)).Print(std::cout);
    (a1.Divide_real(arg)).Print(std::cout);
    


    return 0;
}