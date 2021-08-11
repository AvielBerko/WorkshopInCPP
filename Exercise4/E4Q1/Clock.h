#pragma once
#include <iostream>
using namespace std;

class Clock
{
	int hour;
	int minute;
	int second;
public:
	Clock(int setH = 0, int setM = 0, int setS = 0); // defualt and parameter constructor
	Clock(const Clock& other); // copy constructor

	int getHour() const; // hour getter
	int getMinute() const; // minute getter
	int getSecond() const; // second getter
	void setHour(int setH); // hour setter
	void setMinute(int setM); // minute setter
	void setSecond(int setS); // second setter
	
	Clock& operator+= (int addSeconds); // operator +=
	friend ostream& operator<< (ostream& os, const Clock& C); // operator <<
	friend istream& operator>>(istream& is, Clock& C); // operator >>
};

