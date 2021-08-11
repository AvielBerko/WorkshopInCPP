#pragma once
#include "Student.h"
class BA : public Student
{
protected:
	int gradesSize;
	int* grades;
	float avg() const; // average calculator
public:
	BA(int setID, const char* setFName, const char* setLName, int setNumCourses, int* setGrades, int setGradesSize); // constructor
	virtual ~BA(); // virtual destructor
	virtual bool milga() const; // virtual function
	virtual void print() const; // virtual function

	int* getGrades() const; // grades getter
	void setGrades(int* set, int size); // grades setter
	int getGradesSize() const; // gradesSise getter
	void setGradesSize(int set); // gradesSise setter
};

