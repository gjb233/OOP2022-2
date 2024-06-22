#include"Fraction.h"
long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}
Fraction::Fraction(long long p0, long long q0){
        long long a = gcd(p0, q0);
        p = p0 / a;
        q = q0 / a;
    }
Fraction::Fraction(long long p0) : p(p0), q(1){
}
Fraction Fraction::operator+(Fraction& a){
    return Fraction(p * a.q + q * a.p, q * a.q);
}
Fraction Fraction::operator-(Fraction& a){
    return Fraction(p * a.q - q * a.p, q * a.q);
}
Fraction Fraction::operator*(Fraction& a){
    return Fraction(p * a.p, q * a.q);
}
Fraction Fraction::operator/(Fraction& a){
    return Fraction(p * a.q, q * a.p);
}
ostream& operator<<(ostream& out, Fraction a){
    if(a.q == 1){
        out << a.p;
    }
    else{
        out << a.p << '/' << a.q;
    }
    return out;
}