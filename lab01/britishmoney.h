#ifndef BRITMONEY_H
#define BRITMONEY_H
#include <iostream>

class BMoney {
    friend BMoney Add(const BMoney &m1, const BMoney &m2); // друж ф-ям есть доступ к приват полям и ф-ям класса
    friend BMoney Subtract(const BMoney &m1, const BMoney &m2);
    friend BMoney Divide(const BMoney &m1, const BMoney &m2);
    friend bool Equal(const BMoney &m1, const BMoney &m2);
    friend bool NotEqual(const BMoney &m1, const BMoney &m2);
    friend bool More(const BMoney &m1, const BMoney &m2);
    friend bool Less(const BMoney &m1, const BMoney &m2);
    friend bool MoreEqual(const BMoney &m1, const BMoney &m2);
    friend bool LessEqual(const BMoney &m1, const BMoney &m2);
    friend BMoney PtoSum(unsigned long long tmp_p);

    public:
        BMoney(); // конструктор по умолчанию (все равно 0)
        BMoney(unsigned long long a, unsigned char b, unsigned char c); // конструктор с параметрами, инициализация напрямую в коде
        BMoney(std::istream &is); // конструктор из istream
        BMoney Divide_real(double C);
        BMoney Multiply_real(double C);
        void Print(std::ostream &os);
        ~BMoney(); // деструктор

    private:
        unsigned long long ps;
        unsigned char sh;
        unsigned char p;
        void Translate();
        unsigned long long ToPennies();
        bool Empty();

};
#endif