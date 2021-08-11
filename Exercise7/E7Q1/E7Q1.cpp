// Name: Aviel Berkovich, ID: 211981105
// Workshop in c++
// Exercise 7
// The program simulates 3 levels of student using inheritance and polymorphism
#include "Student.h"
#include "BA.h"
#include "MA.h"
#include "PHD.h"
const int SIZE = 7;

void printScholar(Student** students, int size) {
	for (int i = 0; i < size; i++) { // goes through every student in the vector
		if (students[i]->milga()) { // if the student is eligible of a scholarship
			students[i]->print(); // print the student
			cout << endl;
		}
	}
}
int main() {
	int gradesBA1[3] = { 90, 100, 90 };
	int gradesBA2[10] = { 100, 100, 90, 100, 90, 100, 90, 100, 90, 100 };
	int gradesMA1[7] = { 90, 100, 90, 100, 90, 100, 90 };
	int gradesMA2[7] = { 90, 100, 90, 100, 90, 100, 90 };

	Student** students = new Student*[SIZE]{ new BA(123, "abe", "avraham", 3, gradesBA1, 3),
										   new BA(234, "yitzhak", "avrahamson", 10, gradesBA2, 10),
										   new MA(345, "yaacov", "jacobson", 7, gradesMA1, 7, false),
										   new MA(456, "sara", "emanu", 7, gradesMA2, 7, true),
										   new PHD(567, "rivka", "imanu", 1, 30),
										   new PHD(678, "rachel", "jacobs", 2, 20),
										   new PHD(789, "leah", "jacobs", 2, 30) };
	printScholar(students, SIZE);
	for (int i = 0; i < SIZE; i++) {
		delete students[i]; // free the allocation of every student
	}
	delete[] students; // delete the vector
}

/*
Example:

--- Input ---

--- Program Output ---
ID: 234
first name: yitzhak
last name: avrahamson
num courses: 10
grades: 100 100 90 100 90 100 90 100 90 100

ID: 456
first name: sara
last name: emanu
num courses: 7
grades: 90 100 90 100 90 100 90
research: yes

ID: 789
first name: leah
last name: jacobs
num courses: 2
hours: 30
*/
