#pragma once
#include <iostream>
using namespace std;
class Student {
private:
	string ID;
	string lName;
	string fName;

public:
	Student(string setID = "0", string setLName = "", string setFName = "");
	bool operator< (const Student& other) const;
	bool operator== (const Student& other) const;
	Student& operator= (const Student& other);
	friend istream& operator>> (istream& is, Student& S);
	friend ostream& operator<< (ostream& os, Student& S);
};

