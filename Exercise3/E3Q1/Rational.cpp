#include "Rational.h"
#include <iostream>
//#include <cmath>

int abs(int a) { return a >= 0 ? a : -a; }

int Rational::getnumerator() const { return numerator; } // numerator getter
void Rational::setnumerator(int set) { numerator = set; } // numerator setter
int Rational::getdenominator() const { return denominator; } // denominator getter
void Rational::setdenominator(int set) { denominator = set ? set : 1; } // denominator setter

Rational Rational::fractionReduction() const { // reduces the fraction
    if (!numerator) return Rational(0, 1); // if the Rational-Number is zero - returns 0/1
    int i = abs(numerator) <= abs(denominator) ? abs(numerator) : abs(denominator);// the minimun of the numerator and demuninator
    for (; i > 1 && (numerator % i || denominator % i); i--); // if the numerator and the denominator both devides with no remainder
    return (numerator * denominator > 0) ? Rational(abs(numerator) / i, abs(denominator) / i) : Rational(-abs(numerator) / i, abs(denominator) / i);
    // checks if the number is negative or positive and returns the correct rational number
}

void Rational::print() const { // printing method
    Rational temp = fractionReduction();
    if (!temp.numerator || temp.denominator == 1)
        std::cout << temp.numerator << endl;
    else
        std::cout << temp;
}

Rational::Rational(int nu, int de) : numerator(nu), denominator(de ? de : 1) {} // constractor
Rational::Rational() : numerator(0), denominator(1) {} // default constructor

// operators
Rational Rational::operator+ (const Rational& other) const { // operator +
    return Rational(numerator * other.denominator + denominator * other.numerator, denominator * other.denominator).fractionReduction();
}

Rational Rational::operator- (const Rational& other) const {// operator -
    return Rational(numerator * other.denominator - denominator * other.numerator, denominator * other.denominator).fractionReduction();
}

Rational Rational::operator/ (const Rational& other) const { // operator /
    return Rational(numerator * other.denominator, denominator * other.numerator).fractionReduction();
}

Rational Rational::operator* (const Rational& other) const { // operator * (Rational*Rational)
    return Rational(numerator * other.numerator, denominator * other.denominator).fractionReduction();
}

Rational operator* (const Rational& R, int num) { // operator * (Rational*int)
    return Rational(R.numerator * num, R.denominator * num).fractionReduction();
}

Rational operator* (int num, const Rational& R) { // operator * (int*Rational)
    return R * num;
}

void Rational::operator *= (const Rational& other) { // operator *=
    numerator *= other.numerator;
    denominator *= other.denominator;
    *this = fractionReduction(); // reduces the fractions
}

Rational& Rational::operator++ () { // operator ++ (prefix)
    numerator += denominator;
    return *this = fractionReduction();
}
Rational Rational::operator++ (int) { // operator ++ (postfix)
    Rational temp = *this;
    numerator += denominator;
    return temp;
}

Rational& Rational::operator-- () { // operator -- (prefix)
    numerator -= denominator; 
    return *this = fractionReduction();
}
Rational Rational::operator-- (int) { // operator -- (postfix)
    Rational temp = *this;
    numerator -= denominator;
    return temp;
}
Rational& Rational::operator= (const Rational& other) { // operator =
    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}

bool Rational::operator== (const Rational& other) const { // operator ==
    Rational R1 = fractionReduction(), R2 = other.fractionReduction();
    return (R1.numerator == R2.numerator && R1.denominator == R2.denominator);
}

bool Rational::operator!= (const Rational& other) const { // operator !=
    return !(*this == other);
}

bool Rational::operator< (const Rational& other) const { // operator <
    return (numerator * other.denominator < other.numerator * denominator);
}

bool Rational::operator> (const Rational& other) const { // operator >
    return !(*this < other) && (*this != other);
}

bool Rational::operator>= (const Rational& other) const { // operator >=
    return (*this > other || *this == other);
}

ostream& operator<< (ostream& os, Rational& R) { // operator <<
    os << R.numerator << '/' << R.denominator << endl;
    return os;
}

istream& operator>>(istream& is, Rational& R) { // operator >>
    char slash;
    is >> R.numerator >> slash >> R.denominator;
    if (!R.denominator) {
        cout << "ERROR" << endl;
        R.denominator = 1;
    }
    return is;
}

