#include "MA.h"
MA::MA(int setID, const char* setFName, const char* setLName, int setNumCourses, int* setGrades, int setGradesSize, bool setResearch)
: BA(setID, setFName, setLName, setNumCourses, setGrades, setGradesSize), research(setResearch) {}
bool MA::milga() const {
	return (numCourses >= 7) && (avg() > 90) && research;
}
void MA::print() const {
	BA::print(); // print the student's details
	cout << "research: ";
	research ? cout << "yes" << endl : cout << "no" << endl;
}
bool MA::getResearch() const { return research; }
void MA::setResearch(bool set) { research = set; }