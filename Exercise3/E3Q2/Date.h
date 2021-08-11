#pragma once
#include <iostream>
using namespace std;
class Date
{
	int day;
	int month;
	int year;

public:
	int getDay() const; // day getter
	int getMonth() const; // month getter
	int getYear() const; // year getter
	void setDate(int setDay, int setMonth, int setYear); // sets the date (if the date is valid)
	//void setDate(const Date& other); // Overloading
	void print() const;

	Date(int setDay = 1, int setMonth = 1, int setYear = 1970); // constructor
	Date(const Date& other); // copy constructor

	// operators:
	Date& operator++ (); // operator ++ (prefix)
	Date operator++ (int); // operator ++ (postfix)
	Date& operator+= (int days); // operator +=

	bool operator== (const Date& other) const; // operator ==
	bool operator> (const Date& other) const; // operator >
	bool operator< (const Date& other) const; // operator <

	friend ostream& operator<< (ostream& os, const Date& D); // operator <<
	friend istream& operator>>(istream& is, Date& D); // operator >>
};

