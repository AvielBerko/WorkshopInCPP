#include "Rational.h"
#include <iostream>
//#include <cmath>

int abs(int a) { return a >= 0 ? a : -a; }

int Rational::getnumerator() const { return numerator; } // numerator getter
void Rational::setnumerator(int set) { numerator = set; } // numerator setter
int Rational::getdenominator() const { return denominator; } // denominator getter
void Rational::setdenominator(int set) { denominator = set ? set : 1; } // denominator setter

void Rational::print() const { // printing method
    if (!numerator || denominator == 1)
        std::cout << numerator;
    else
	    std::cout << numerator << "/" << denominator << endl;
}

bool Rational::equal(Rational other) const { // checks if 2 Rational-Numbers are equal
	Rational R1 = fractionReduction(), R2 = other.fractionReduction(); // reduces the fractions to temporary variables
	return (R1.numerator == R2.numerator && R1.denominator == R2.denominator);
}

Rational Rational::fractionReduction() const { // reduces the fraction
	if (!numerator) return Rational(0, 1); // if the Rational-Number is zero - returns 0/1
	int i = abs(numerator) <= abs(denominator) ? abs(numerator) : abs(denominator);// the minimun of the numerator and demuninator
	for (; i > 1 && (numerator % i || denominator % i); i--); // if the numerator and the denominator both devides with no remainder
	return (numerator*denominator > 0) ? Rational(abs(numerator) / i, abs(denominator) / i) : Rational(-abs(numerator) / i, abs(denominator) / i);
	// checks if the number is negative or positive and returns the correct rational number
}

Rational::Rational(int nu, int de) : numerator(nu), denominator(de ? de : 1) {} // constractor
Rational::Rational() :numerator(0), denominator(1) {}// default constructor


Rational Rational::operator+ (Rational& other) {
   return Rational(numerator * other.denominator + denominator * other.numerator, denominator * other.denominator);
}

Rational Rational::operator* (Rational& other) {
    return Rational(numerator * other.numerator, denominator * other.denominator);
}

Rational Rational::operator- (Rational& other) {
    return Rational(numerator * other.denominator - denominator * other.numerator, denominator * other.denominator);
    //return *this + -1*other;
}

Rational Rational::operator/ (Rational& other) {
    return Rational(numerator * other.denominator, denominator * other.numerator);
}

Rational operator* (Rational& R, int num) {
    return Rational(R.numerator * num, R.denominator * num);
}

Rational operator* (int num, Rational& R) {
    return R * num;
}

Rational& Rational::operator= (const Rational& other) {
    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}

bool Rational::operator== (const Rational& other) const {
    return (numerator == other.numerator && denominator == other.denominator);
}

bool Rational::operator!= (const Rational& other) const {
    return !(*this == other);
}

bool Rational::operator< (const Rational& other) const {
    return (numerator*other.denominator < other.numerator*denominator);
}

bool Rational::operator> (const Rational& other) const {
    return !(*this < other);
}

bool Rational::operator>= (const Rational& other) const {
    return (numerator * other.denominator >= other.numerator * denominator);
}

void Rational::operator*= (Rational& other) {
    numerator *= other.numerator;
    denominator *= other.denominator;
}

Rational& Rational::operator++ () {
    numerator += denominator;
    return *this;
}
Rational Rational::operator++ (int) {
    Rational temp = *this;
    numerator += denominator;
    return temp;
}

Rational& Rational::operator-- () {
    numerator -= denominator;
    return *this;
}
Rational Rational::operator-- (int) {
    Rational temp = *this;
    numerator -= denominator;
    return temp;
}

ostream& operator<< (ostream& os, Rational& R) {
    os << R.numerator << '/' << R.denominator << endl;
    return os;
}

istream& operator>>(istream& is, Rational& R) {
    char slash;
    is >> R.numerator >> slash >> R.denominator;
    return is;
}
