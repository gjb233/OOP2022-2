#pragma once
#include<iostream>
using namespace std;
class Fraction{
private:
    long long p;
    long long q;
public:
    Fraction(long long p0, long long q0);
    Fraction(long long p0);
    friend Fraction operator+(Fraction a, Fraction b);
    friend Fraction operator-(Fraction a, Fraction b);
    friend Fraction operator*(Fraction a, Fraction b);
    friend Fraction operator/(Fraction a, Fraction b);
    friend ostream& operator<<(ostream& out, Fraction a);
};