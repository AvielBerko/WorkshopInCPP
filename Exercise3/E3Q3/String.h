#pragma once
#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

class String
{
	char* str;
	void setString(const char* s);

public:
	char* getString() const;
	String& operator=(const String&);
	int length() const;
	void print() const;
	//String& insert(int index, const char* string) const; // cats 2 strings in the index's location
	String insert(int index, const char* string) const; // cats 2 strings in the index's location

	String(const char* s = "");  // constructor 
	String(const String& s); // copy constructor
	~String(); // destructor

	// operators
	bool operator==(const String& other) const;
	bool operator!= (const String& other) const; // operator !=
	bool operator> (const String& other) const;  // operator > (using strcmp)
	bool operator< (const String& other) const;  // operator < (using strcmp)
	bool operator>= (const String& other) const; // operator >= (using strcmp)
	bool operator<= (const String& other) const; // operator <= (using strcmp)
	String operator+(const String& other) const;
	String operator* (const int num) const; 
	friend ostream& operator<< (ostream& os, const String& S); // operator <<
	friend istream& operator>>(istream& is, String& S); // operator >>
};
