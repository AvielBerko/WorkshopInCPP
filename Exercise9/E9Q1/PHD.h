#pragma once
#include "Student.h"
class PHD : public Student
{
private:
	int researchHours;
public:
	PHD(int setID, const char* setFName, const char* setLName, int setNumCourses, int setRHours); // constructor
	bool milga() const; // (virtual)
	void print() const; // (virtual)
	string studType() const; // (virtual)

	int getResearchHours() const; // researchHours getter
	void setResearchHours(int set); // researchHours setter
};