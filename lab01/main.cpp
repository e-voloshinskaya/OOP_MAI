#include <iostream>
#include "britishmoney.h"

int main(void) {

    double arg;

    BMoney a1(1, 2, 3);
    BMoney a2(std::cin);
    //std::cin >> arg;
    a1.Print(std::cout);
    a2.Print(std::cout);
    //BMoney a3 = BMoney();
    //Add(a1, a2);
    BMoney a3 = Add(a1, a2);
    a3.Print(std::cout);
    //BMoney a2 = a1.Multiply_real(arg);
    //a2.Print(std::cout);
    //(a1.Divide_real(arg)).Print(std::cout);
    


    return 0;
}