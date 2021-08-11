#include "Student.h"

//constructor
Student::Student(string setID, string setFName, string setLName) : ID(setID), lName(setLName), fName(setFName) {}

bool Student::operator< (const Student& other) const {
	// cats the last and first name and checks who is smaller
	return (this->lName + this->fName) < (other.lName + other.fName);
}

bool Student::operator== (const Student& other) const {
	// cats the last and first name and checks if equal (and ID)
	return (this->lName + this->fName) == (other.lName + other.fName) && (this->ID == other.ID);

}
Student& Student::operator= (const Student& other) {
	// sets values
	this->ID = other.ID;
	this->lName = other.lName;
	this->fName = other.fName;
	return *this;
}
istream& operator>> (istream& is, Student& S) {
	is >> S.ID >> S.fName >> S.lName;
	return is;
}
ostream& operator<< (ostream& os, Student& S) {
	os << S.ID << " " << S.fName << " " << S.lName << endl;
	return os;
}