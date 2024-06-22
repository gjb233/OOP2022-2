#include"Fraction.h"
long long gcd(long long a, long long b){
    if(a < 0) a = -a;
    if(b < 0) b = -b; 
    return b ? gcd(b, a % b) : a;
}
Fraction::Fraction(long long p0, long long q0){
        if(q0 < 0) {
            p0 = -p0;
            q0 = -q0;
        }
        long long a = gcd(p0, q0);
        p = p0 / a;
        q = q0 / a;
    }
Fraction::Fraction(long long p0) : p(p0), q(1){
}
Fraction operator+(Fraction a, Fraction b){
    return Fraction(a.p * b.q + a.q * b.p, a.q * b.q);
}
Fraction operator-(Fraction a, Fraction b){
    return Fraction(a.p * b.q - a.q * b.p, a.q * b.q);
}
Fraction operator*(Fraction a, Fraction b){
    return Fraction(b.p * a.p, b.q * a.q);
}
Fraction operator/(Fraction a, Fraction b){
    return Fraction(a.p * b.q, a.q * b.p);
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