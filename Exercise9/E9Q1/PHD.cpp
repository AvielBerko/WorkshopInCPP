#include "PHD.h"
PHD::PHD(int setID, const char* setFName, const char* setLName, int setNumCourses, int setRHours) 
	: Student(setID, setFName, setLName, setNumCourses), researchHours(setRHours) {}

bool PHD::milga() const {
	return (numCourses >= 2) && (researchHours > 25);
}

void PHD::print() const {
	Student::print(); // print the student's details
	cout << "hours: " << researchHours << endl;
}
int PHD::getResearchHours() const { return researchHours; }

void PHD::setResearchHours(int set) { researchHours = set; }

string PHD::studType() const { return "PHD"; } // virtual function
