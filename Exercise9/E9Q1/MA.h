#pragma once
#include "BA.h"
class MA : public BA
{
private:
	bool research;
public:
	MA(int setID, const char* setFName, const char* setLName, int setNumCourses, int* setGrades, bool setResearch); // constructor
	bool milga() const; // (virtual)
	void print() const; // (virtual)
	string studType() const; // (virtual)


	bool getResearch() const; // research getter
	void setResearch(bool set); // research setter
};

