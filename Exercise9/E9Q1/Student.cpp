#include "Student.h"
Student::Student(int setID, const char* setFName, const char* setLName, int setNumCourses) 
	: ID(setID), firstName(new char[strlen(setFName) + 1]), lastName(new char[strlen(setLName) + 1]), numCourses(setNumCourses) {
	strcpy(firstName, setFName); // copy the string
	strcpy(lastName, setLName); // copy the string
}

Student::~Student() {
	if (firstName) // if memory was allocated
		delete[] firstName; // free the dynamic memory
	if (lastName) // if memory was allocated
		delete[] lastName; // free the dynamic memory
}

void Student::print() const {
	cout << "ID: " << ID << endl
	<< "first name: " << firstName << endl
	<< "last name: " << lastName << endl
	<< "num courses: " << numCourses << endl;
}

int Student::getID() const { return ID; }

void Student::setID(int set) { ID = set; }

char* Student::getFirstName() const { return firstName; }

void Student::setFirstName(const char* set) {
	if (firstName) // if memory was allocated
		delete[] firstName; // free the dynamic memory
	firstName = new char[strlen(set) + 1]; // new allocation
	strcpy(firstName, set); // copy the string
}

char* Student::getLastName() const { return lastName; }

void Student::setLastName(const char* set) {
	if (lastName) // if memory was allocated
		delete[] lastName; // free the dynamic memory
	lastName = new char[strlen(set) + 1]; // new allocation
	strcpy(firstName, set); // copy the string
}

int Student::getNumCourses() const { return numCourses; }

void Student::setNumCourses(int set) { numCourses = set; }