#include "BA.h"
float BA::avg() const { // simple average calculate
	if (gradesSize) {
		float sum = 0;
		for (int i = 0; i < gradesSize; i++)
			sum += grades[i];
		sum /= gradesSize;
		return sum;
	}
	return 0;
}
BA::BA(int setID, const char* setFName, const char* setLName, int setNumCourses, int* setGrades, int setGradesSize)
	: Student(setID, setFName, setLName, setNumCourses), gradesSize(setGradesSize), grades(new int[gradesSize]) {
	for (int i = 0; i < gradesSize; i++) // deep copy of array
		grades[i] = setGrades[i];
}

BA::~BA() {
	if (grades) // if memory was allocated
		delete[] grades; // free the dynamic memory
}
bool BA::milga() const {
	return (numCourses >= 10) && (avg() > 95);
}
void BA::print() const {
	Student::print(); // print the student's details
	cout << "grades: "; 
	for (int i = 0; i < gradesSize; i++) // print the grades
		cout << grades[i] << " ";
	cout << endl;
}

int* BA::getGrades() const { return grades; }
void BA::setGrades(int* set, int size) {
	if (grades) // if memory was allocated
		delete[] grades; // free the dymanic memory
	grades = new int[size]; // new allocation
	for (int i = 0; i < size; i++) // deep copy
		grades[i] = set[i];
}
int BA::getGradesSize() const { return gradesSize; }
void BA::setGradesSize(int set) { gradesSize = set; }