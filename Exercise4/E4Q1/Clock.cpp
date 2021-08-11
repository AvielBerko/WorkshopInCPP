#include "Clock.h"
const Clock MAX(23, 59, 59);

Clock::Clock(int setH, int setM, int setS) { // defualt and parameter constructor
	try {
		(setH < 0) ? throw "Invalid time - negative number of hours.\n" : ((setH >= 24) ? throw "Invalid time - more than 24 hours.\n" : hour = setH);
		(setM < 0) ? throw "Invalid time - negative number of minutes.\n" : ((setM >= 60) ? throw "Invalid time - more than 60 minutes.\n" : minute = setM);
		(setS < 0) ? throw "Invalid time - negative number of seconds.\n" : ((setS >= 60) ? throw "Invalid time - more than 60 seconds.\n" : second = setS);
	}
	catch (const char* msg) { // cathes the message
		*this = Clock(); // sets time to 00:00:00
		cout << msg; // prints the error
	}

}

Clock::Clock(const Clock& other) :
	hour(other.hour), minute(other.minute), second(other.second) {} // copy constructor

int Clock::getHour() const { return hour; } // hour getter 
int Clock::getMinute() const { return minute; } // minute getter
int Clock::getSecond() const { return second; } // second getter
void Clock::setHour(int setH) { // hour setter
	try {
		(setH < 0) ? throw "Invalid time - negative number of hours.\n" : ((setH >= 24) ? throw "Invalid time - more than 24 hours.\n" : hour = setH);	}
	catch (const char* msg) { // cathes the message
		hour = 0;
		cout << msg; // prints the error
	}
}	 
void Clock::setMinute(int setM) { // minute setter
	try {
		(setM < 0) ? throw "Invalid time - negative number of minutes.\n" : ((setM >= 60) ? throw "Invalid time - more than 60 minutes.\n" : minute = setM);
	}
	catch (const char* msg) { // cathes the message
		minute = 0;
		cout << msg; // prints the error
	}
}	 
void Clock::setSecond(int setS) { // second setter
	try {
		(setS < 0) ? throw "Invalid time - negative number of seconds.\n" : ((setS >= 60) ? throw "Invalid time - more than 60 seconds.\n" : second = setS);
	}
	catch (const char* msg) { // cathes the message
		second = 0;
		cout << msg; // prints the error
	}
}


Clock& Clock::operator+= (int addSeconds) { // operator +=
	if (!addSeconds) // negative seconds
		throw "Invalid time - negative number of seconds.\n";

	int sumSeconds = second + addSeconds;
	if (sumSeconds <= MAX.second) { // fits the seconds
		second += addSeconds;
		return *this;
	}
	else {
		minute += sumSeconds / (MAX.second + 1); // adds the month added
		second = sumSeconds % (MAX.second + 1); // sets the day
		if (minute <= MAX.minute) // if the month is set correctly
			return *this;
		else {
			hour += minute / (MAX.minute + 1); // adds the years added
			minute %= (MAX.minute + 1); // sets the month
			if (hour <= MAX.hour) // if the date is bigger the the maximum date
				return *this;
			else {
				hour %= MAX.hour + 1;
				return *this;
			}
		}
	}
}

ostream& operator<< (ostream& os, const Clock& C) { // operator <<
	(C.hour < 10) ? os << '0' << C.hour : os << C.hour; // hours
	os << ':';
	(C.minute < 10) ? os << '0' << C.minute : os << C.minute; // minutes
	os << ':';
	(C.second < 10) ? os << '0' << C.second : os << C.second; // seconds
	os << endl;
	return os;
}

istream& operator>>(istream& is, Clock& C) { // operator >>
	int h, m, s;
	char garbge;
	is >> h >> garbge >> m >> garbge >> s;
	try {
		if (garbge != ':')
			throw "Wromg time format."; // not ':'
	}
	catch (const char* msg) {
		C = Clock(); // sets time to 00:00:00
		cout << msg; // prints the error
	}
	C = Clock(h, m, s); // sets the time 
	return is;
}
