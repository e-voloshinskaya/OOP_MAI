#include "britishmoney.h"
#include <cmath>

unsigned char ps_sh = 20;
unsigned char sh_p = 12;

BMoney::BMoney() {
    ps = 0;
    sh = 0;
    p = 0;
    std:: cout << "Start: " << std:: endl;
}

BMoney::BMoney(unsigned long long a, unsigned char b, unsigned char c) {
    if (ps < 0 || sh < 0 || p < 0) {
        std:: cout << "Parameters must be positive or zero integer numbers" << std:: endl;
        // что тут происходит
    }
    else {
        ps = a;
        sh = b;
        p = c;
    }
    std:: cout << "Virtual wallet has been created according to parameters" << std:: endl;
}

BMoney::BMoney(std::istream &is) {
    std:: cout << "Please enter your wallet data in order [pounds] [shillings] [pennies]: " << std:: endl;
    is >> ps >> sh >> p;
    while (ps < 0 || sh < 0 || p < 0) {
        std:: cout << "Invalind input. Try again." << std:: endl;
        is >> ps >> sh >> p;
    }
    std:: cout << "Virtual wallet has been created via istream" << std:: endl;
}

void Translate() {
    if (this.p > sh_p || this.sh > ps_sh) {
        this.sh += this.p / sh_p;
        this.p %= this.p;
        this.ps += this.sh / ps_sh;
        this.sh %= this.sh;
    }
}


bool Equal(const BMoney &m1, const BMoney &m2) {
    if (m1.ps = m2.ps && m1.sh = m2.sh && m1.p = m2.p)
        return 1;
    return 0;
}

bool NotEqual(const BMoney &m1, const BMoney &m2) {
    if (m1.ps != m2.ps || m1.sh != m2.sh || m1.p != m2.p)
        return 1;
    return 0;
    //return !Equal(m1, m2);
}

bool More(const BMoney &m1, const BMoney &m2) {
    m1.Translate();
    m2.Translate();
    if (m1.ps > m2.ps) { return 1;}
    else if (m1.ps == m2.ps) {
        if (m1.sh > m2.sh) { return 1;}
        else if (m1.sh == m2.sh && m1.p > m2.p) { return 1;}
    }
    return 0;
}

bool LessEqual(const BMoney &m1, const BMoney &m2) {
    return !More(m1, m2);
}

bool Less(const BMoney &m1, const BMoney &m2) {
    return More(m2, m1);
}

bool MoreEqual(const BMoney &m1, const BMoney &m2) {
    return !More(m2, m1);
}

bool Empty() {
    if (this.ps == 0 && this.sh == 0 && this.p == 0)
        return 1;
    return 0;
}


BMoney Add(const BMoney& m1, const BMoney &m2) {
    BMoney res;
    res.p = (m1.p + m2.p) % sh_p;
    res.sh = (m1.sh + m2.sh) % ps_sh + (m1.p + m2.p) / sh_p;
    res.ps = m1.ps + m2.ps + (m1.sh + m2.sh) / ps_sh;
    return res;
}

unsigned long long ToPennies() {
    unsigned long long res = this.ps * ps_sh * sh_p + this.sh * sh_p + this.p;
    return res;
};

BMoney PtoSum(unsigned long long tmp_p) {
    BMoney res;
    res.ps = tmp_p / (ps_sh * sh_p);
    res.sh = tmp_p / sh_p % ps_sh;
    res.p = tmp_p % sh_p;
    return res;
}

BMoney Subtract(const BMoney& m1, const BMoney &m2) {
    BMoney res;
    if (MoreEqual(m1, m2)) {
        unsigned long long tmp = m1.ToPennies() - m2.ToPennies();
        res = PtoSum(tmp);
        return res;
    }
    std:: cout << "The operation could not be performed. The first sum is less than the second." << std:: endl;
    return;
}

BMoney Divide(const BMoney &m1, const BMoney &m2) {
    BMoney res;
    if (!m2.Empty()) {
        unsigned long long tmp = m1.ToPennies() / m2.ToPennies();
        res = PtoSum(tmp);
        return res;
    }
    std:: cout << "The operation could not be performed. The second sum equals null." << std:: endl;
    return;
}

BMoney Divide_real(double C) {
    if (C == 0) {
        std:: cout << "The operation could not be performed. The number equals null." << std:: endl;
        return;
    }
    BMoney res;
    unsigned long long tmp = this.ToPennies() / C;
    res = PtoSum(tmp);
    return res;
} 

BMoney Multiply_real(double C) {
    BMoney res;
    unsigned long long tmp = this.ToPennies() * C;
    res = PtoSum(tmp);
    return res;
}

void Print(std::ostream &os) {
    os << m.ps << " pounds " << m.sh << " shillings " << m.p << " pennies " << std::endl;
    return os;
}

BMoney::~BMoney() {
    std:: cout << "Your wallet has been deleted" << std:: endl;
}