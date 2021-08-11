#pragma once
// String.h
#include <iostream>
#include <cstring>
using namespace std;
class String
{
private:
	char* str;
	void setString(const char* s);
public:
	String(char* s = nullptr); //empty ctor or not empty ctor
	String(const String& s);//copy ctor
	~String(); //dtor
	char* getString() const; // view function.
	String& operator=(const String&);// modify function.
	bool operator==(const String&) const;
	String  operator+(const String&) const;
	String  operator* (const int) const;
	friend ostream& operator<<(ostream& os, String st);

	int length() const;
	void print() const;
}
