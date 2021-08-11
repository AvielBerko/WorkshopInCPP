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
	bool equal(Rational other) const; // checks if 2 Rational-Numbers are equal

	Rational(int nu, int de); // constractor
	Rational(); // default constructor

    void operator*= (Rational& other);
    Rational operator* (Rational& other);
    Rational operator+ (Rational& other);
    Rational operator- (Rational& other);
    Rational operator/ (Rational& other);
    bool operator== (const Rational& other) const;
    bool operator!= (const Rational& other) const;
    bool operator< (const Rational& other) const;
    bool operator> (const Rational& other) const;
    bool operator>= (const Rational& other) const;
    Rational& operator= (const Rational& other);
    Rational& operator++ ();
    Rational operator++ (int);
    Rational& operator-- ();
    Rational operator-- (int);
    friend Rational operator* (Rational& R, int num);
    friend Rational operator* (int num, Rational& R);
    friend ostream& operator<< (ostream& os, Rational& R);
    friend istream& operator>> (istream& is, Rational& R);
};