#include <iostream>
#include "britishmoney.h"

int main(void) {
    
    BMoney a1;
    BMoney a2;
    double arg;

    BMoney a1(std::cin);
    BMoney a2(std::cin);
    std::cin >> arg;
    a1.Multiply_real(arg).Print();
    (a1.Divide_real(arg)).Print();
    


    return 0;
}