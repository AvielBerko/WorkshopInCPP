#include "Date.h"
#include <iostream>
using namespace std;
const Date MIN_DATE, MAX_DATE(30, 12, 2099);

int Date::getDay() const { return day; }// day getter
int Date::getMonth() const { return month; } // month getter
int Date::getYear() const { return year; } // year getter

void Date::setDate(int setDay, int setMonth, int setYear) { // sets the date (if the date is valid)
	if (!(setDay > MAX_DATE.day || setDay < MIN_DATE.day || setMonth > MAX_DATE.day || setMonth < MIN_DATE.month || setYear > MAX_DATE.year || setYear < MIN_DATE.year))
		*this = Date(setDay, setMonth, setYear);
}

/*void Date::setDate(const Date& other) { // Overloading
	if (!(other.day > 30 || other.day < 1 || other.month > 12 || other.month < 1 || other.year > 2099 || other.year < 1970))
		*this = other;
}*/

void Date::print() const {
	cout << day << '/' << month << '/' << year << endl;
}

Date::Date(int setDay, int setMonth, int setYear) { // constructor
	if (setDay > 30 || setDay < 1) { // day error
		cout << "Error day" << endl;
		day = MIN_DATE.day; // sets day = 1
	}
	else
		day = setDay;
	if (setMonth > 12 || setMonth < 1) { // month error
		cout << "Error month" << endl;
		month = MIN_DATE.month; // sets month = 1
	}
	else
		month = setMonth;
	if (setYear > 2099 || setYear < 1970) { // year error
		cout << "Error year" << endl;
		year = MIN_DATE.year; // sets year = 1970
	}
	else
		year = setYear; 
}

Date::Date(const Date& other) { // copy constructor
	day = other.day;
	month = other.month;
	year = other.year;
}

// operators:
Date& Date::operator++ () { // operator ++ (prefix)
	if (*this == MAX_DATE) { // last date
		*this = MIN_DATE; // set the date to minimun (1/1/1970)
		return *this;
	}
	if (day < MAX_DATE.day) { // the days don't exceeds the month
		day++; // next day
		return *this;
	}
	else {
		day = MIN_DATE.day; // sets day = 1
		if (month < MIN_DATE.month) { // the months don't exceeds the year
			month++; // next month
			return *this;
		}
		else { // next year
			month = MIN_DATE.month; // sets month = 1
			year++; // next year
			return *this;
		}
	}
	/*if (month < MAX_DATE.month) {
		month++;
		return *this;
	}
	else {
		month = MIN_DATE.month;
		year++;
		return *this;
	}*/
}
Date Date::operator++ (int) { // operator ++ (postfix)
	Date temp = *this; // saves the day
	++(*this); // increases by 1
	return temp; // returns the saved day
}

Date& Date::operator+= (int daysToAdd) { // operator +=
	int sumDays = day + daysToAdd;
	if ((sumDays) <= MAX_DATE.day) { // the days don't exceeds the month
		day += daysToAdd; // adds the days
		return *this;
	}
	else {
		month += sumDays / MAX_DATE.day; // adds the month added
		day = sumDays % MAX_DATE.day; // sets the day
		if (month <= MAX_DATE.month) // if the month is set correctly
			return *this;
		else {
			year += month / MAX_DATE.month; // adds the years added
			month %= MAX_DATE.month; // sets the month
			if (*this > MAX_DATE) // if the date is bigger the the maximum date
				*this = MIN_DATE; // set the date to minimun (1/1/1970)
			return *this;
		}
	}
}

bool Date::operator== (const Date& other) const { // operator ==
	return (day == other.day && month == other.month && year == other.year);
}

bool Date::operator> (const Date& other) const { // operator >
	if (year == other.year) { // if the same year
		if (month == other.month) // if the same month
			return day > other.day; 
		return month > other.month;
	}
	return year > other.year;
}

bool Date::operator< (const Date& other) const { // operator >
	return !(*this > other) && !(*this == other); // < is: not > AND not ==
}

ostream& operator<< (ostream& os, const Date& D) { // operator <<
	os << D.day << '/' << D.month << '/' << D.year;
	return os;
}

istream& operator>>(istream& is, Date& D) { // operator >>
	char slash;
	is >> D.day >> slash >> D.month >> slash >> D.year;
	if (D.day > 30 || D.day < 1) {
		cout << "Error day" << endl;
		D.day = MIN_DATE.day;
	}
	if (D.month > 12 || D.month < 1) {
		cout << "Error month" << endl;
		D.month = MIN_DATE.month;
	}
	if (D.year > 2099 || D.year < 1970) {
		cout << "Error year" << endl;
		D.year = MIN_DATE.year;
	}
	return is;
}

/*while (days > 0) {
if (day + days > MAX_DATE.day) {
	if (month < MAX_DATE.month) {
		days -= MAX_DATE.day;
		month++;
	}
	else {
		days -= MAX_DATE.day;
		month = MIN_DATE.month;
		year++;
	}
}
else {
	day += days;
	break;
}
if (days < 0)
	day += days;
return *this;*/