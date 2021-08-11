#pragma once
#include <iostream>
using namespace std;
class Rational
{
    int numerator;
    int denominator;
    Rational fractionReduction() const; // reduces the fraction

public:
    int getnumerator() const; // numerator getter
    void setnumerator(int set); // numerator setter
    int getdenominator() const; // denominator getter
    void setdenominator(int set); // denominator setter
    void print() const; // printing method

    Rational(int nu, int de); // constractor
    Rational(); // default constructor

    // math operations
    Rational operator+ (const Rational& other) const; // operator +
    Rational operator- (const Rational& other) const; // operator -
    Rational operator/ (const Rational& other) const; // operator /
    Rational operator* (const Rational& other) const; // operator * (Rational*Rational)
    friend Rational operator* (const Rational& R, int num) ; // operator * (Rational*int)
    friend Rational operator* (int num, const Rational& R); // operator * (int*Rational)
    void operator*= (const Rational& other); // operator *=
    Rational& operator++ (); // operator ++ (prefix)
    Rational operator++ (int); // operator ++ (postfix)
    Rational& operator-- (); // operator -- (prefix)
    Rational operator-- (int); // operator -- (postfix)

    // comparing operators
    Rational& operator= (const Rational& other); // operator =
    bool operator== (const Rational& other) const; // operator ==
    bool operator!= (const Rational& other) const; // operator !=
    bool operator< (const Rational& other) const; // operator <
    bool operator> (const Rational& other) const; // operator >
    bool operator>= (const Rational& other) const; // operator >=

    // stream operators
    friend ostream& operator<< (ostream& os, Rational& R); // operator <<
    friend istream& operator>> (istream& is, Rational& R); // operator >>
};