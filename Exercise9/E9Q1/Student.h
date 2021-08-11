#pragma once
#include <cstring>
#pragma warning (disable:4996)
#include<iostream>
#include <string>
using namespace std;
class Student // abstract class
{
protected:
	int ID;
	char* firstName;
	char* lastName;
	int numCourses;
public:
	Student(int setID, const char* setFName, const char* setLName, int setNumCourses); // constructor
	virtual ~Student(); // virtucal destructor
	virtual bool milga() const = 0; // pure virtual function
	virtual string studType() const = 0; // pure virtual function
	virtual int getResearchHours() const { return 0; }; // researchHours getter
	virtual bool getResearch() const { return false; }; // research getter

	virtual void print() const; // virtual function

	int getID() const; // ID getter
	void setID(int set); // ID setter
	char* getFirstName() const; // first name getter
	void setFirstName(const char* set); // first name setter
	char* getLastName() const; // last name getter
	void setLastName(const char* set); // last name setter
	int getNumCourses() const; // numCourses getter
	void setNumCourses(int set); // numCourses setter
};

