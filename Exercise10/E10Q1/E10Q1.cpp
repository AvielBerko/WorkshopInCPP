// Name: Aviel Berkovich, ID: 211981105
// Workshop in c++
// Exercise 10
// The program uses binary file of students
#include <iostream>
#include <fstream>
using namespace std;

struct Student {
	int studNum = 0;
	char fName[21] = "";
	char lName[21] = "";
	bool courses[5] = { false,false,false,false,false };
};
enum option { ADD = 1, DEL, UPDATE, RISHUM, PRINT, COURSE, overheadStudent, removePHDFailers };

const Student EMPTY_STUDENT; // empty student - default values

void init(fstream& file) {
	for (int i = 0; i < 100; i++)
		file.write((char*) &EMPTY_STUDENT, sizeof(Student)); // sets 100 empty students
}

void add(fstream& file) {
	Student s;
	cout << "Enter student details: Student-Number, first name, last name and 5 courses (0/1)\n";
	cin >> s.studNum >> s.fName >> s.lName; // read from basic input
	for (int i = 0; i < 5; i++)
		cin >> s.courses[i];
	if (s.studNum < 1 || s.studNum > 100) // wrong student number
		throw "ERROR: Invalid student number";
	Student check;
	file.seekg((s.studNum - 1) * sizeof(Student), ios::beg); // non-seriel - jumps to the right student in the file
	file.read((char*) &check, sizeof(Student)); // read the student into check
	if (check.studNum) // if student doesn't exist
		throw "ERROR: Student is already in the file";
	file.seekp((s.studNum - 1) * sizeof(Student), ios::beg); // non-seriel - jumps to the right student in the file
	file.write((char*) &s, sizeof(Student)); // write the student to the file
}

void del(fstream& file, int sNum) {
	if (sNum < 1 || sNum > 100) // wrong student number
		throw "ERROR: Invalid student number";
	file.seekp((sNum - 1) * sizeof(Student), ios::beg);  // non-seriel - jumps to the right student in the file
	file.write((char*)&EMPTY_STUDENT, sizeof(Student)); // write the student to the file
}

void update(fstream& file, int sNum) {
	if (sNum < 1 || sNum > 100) // wrong student number
		throw "ERROR: Invalid student number";
	Student s;
	file.seekg((sNum - 1) * sizeof(Student), ios::beg);  // non-seriel - jumps to the right student in the file
	file.read((char*)&s, sizeof(Student)); // read the student into s
	if (!s.studNum) // if student doesn't exist
		throw "ERROR: Student is not in the file";
	cout << "Enter details of 5 courses: \n";
	for (int i = 0; i < 5; i++) // read from basic input 5 bools
		cin >> s.courses[i];
	file.seekp((sNum - 1) * sizeof(Student), ios::beg);  // non-seriel - jumps to the right student in the file
	file.write((char*) &s, sizeof(Student)); // read the student into s
}

bool rishum(fstream& file, int sNum, int courseNum) {
	if (sNum < 1 || sNum > 100) // wrong student number
		throw "ERROR: Invalid student number";
	if (courseNum < 1 || courseNum > 5) // wrong course number
		throw "ERROR: Invalid course number";
	Student s;
	file.seekg((sNum - 1) * sizeof(Student), ios::beg);  // non-seriel - jumps to the right student in the file
	file.read((char*) &s, sizeof(Student)); // read the student into s
	if (!s.studNum) // if student doesn't exist
		throw "ERROR: Student is not in the file";
	return s.courses[courseNum - 1]; // return if the student is taking the course
}

void print(fstream& file, int sNum) {
	if (sNum < 1 || sNum > 100) // wrong student number
		throw "ERROR: Invalid student number";
	Student s;
	file.seekg((sNum - 1) * sizeof(Student), ios::beg);  // non-seriel - jumps to the right student in the file
	file.read((char*) &s, sizeof(Student)); // read the student into s
	if (!s.studNum) // if student doesn't exist
		throw "ERROR: Student is not in the file";
	cout << "Fisrt name: " << s.fName << endl << "Last name: " << s.lName << endl << "Courses: ";
	for (int i = 0; i < 4; i++) {
		(s.courses[i]) ? cout << "Y, " : cout << "N, ";
	}
	(s.courses[4]) ? cout << "Y" << endl : cout << "N" << endl;
}

void inCourse(fstream& file, int courseNum) {
	if (courseNum < 1 || courseNum > 5) // wrong course number
		throw "ERROR: Invalid course number";
	file.seekg(0, ios::beg); // reset the read pointer
	while (!file.eof()) { // while the file has not ended
		Student s;
		file.read((char*) &s, sizeof(Student)); // read the student into s
		if (s.courses[courseNum - 1]) // if student is taking the course
			cout << "Fisrt name: " << s.fName << endl << "Last name: " << s.lName << endl;
	}
}

int main()
{
	fstream file;
	file.open("students.bin", ios::binary | ios::in | ios::out | ios::trunc);
	if (!file) {
		cout << "ERROR: couldn't open file\n";
		return 0;
	}
	init(file);
	int choice, snum, cnum;
	cout << "Choices are:\n0 to exit\n1 to add a student\n2 to delete a student\n3 to update rishum to courses\n4 to check rishum for a course\n5 to print a student\n6 to print all the students that participate in a specific course\n";
	cout << "enter 0-6:\n";
	cin >> choice;
	while (choice) {
		switch (choice) {
		case ADD: //add to the file
			try { add(file); }
			catch (const char* msg) { cout << msg; }
			break;
		case DEL: //delete from file
			cout << "enter number of student to delete:\n";
			cin >> snum;
			try { del(file, snum); }
			catch (const char* msg) { cout << msg; }
			break;
		case UPDATE: //update the list of courses of a student
			cout << "enter number of student to update:\n";
			cin >> snum;
			try { update(file, snum); }
			catch (const char* msg) { cout << msg; }
			break;
		case RISHUM: //check rishum to a specific course
			cout << "enter number of student to check rishum:\n";
			cin >> snum;
			cout << "enter number of course to check rishum:\n";
			cin >> cnum;
			try {
				cout << "The student is" << (rishum(file, snum,	cnum) ? " " : " not ") << "taking the course\n";
			}
			catch (const char* msg) { cout << msg; }
			break;
		case PRINT: //print the details of a specific student
			cout << "enter number of student to print:\n";
			cin >> snum;
			try { print(file, snum); }
			catch (const char* msg) { cout << msg; }
			break;
		case COURSE: //print the details of all the students that are taking a specific course
				cout << "enter number of course to check rishum:\n";
			cin >> cnum;
			try { inCourse(file, cnum); }
			catch (const char* msg) { cout << msg; }
			break;
		default:
			cout << "ERROR: invalid choice\n";
		}
		cout << "\nenter 0-6:\n";
		cin >> choice;
	}
	file.close();
	return 0;
}
/*
Example:

--- Input ---
1
14
moshe
cohen
1 0 1 0 0
1
57
david
levi
1 0 0 0 1
2
57
3
14
1 0 0 0 1
4
15
3
4
14
3
5
14
6
2
0
--- Program Output ---
Choices are:
0 to exit
1 to add a student
2 to delete a student
3 to update rishum to courses
4 to check rishum for a course
5 to print a student
6 to print all the students that participate in a specific course
enter 0-6:
1
Enter student details: Student-Number, first name, last name and 5 courses (0/1)
14
moshe
cohen
1 0 1 0 0

enter 0-6:
1
Enter student details: Student-Number, first name, last name and 5 courses (0/1)
57
david
levi
1 0 0 0 1

enter 0-6:
2
enter number of student to delete:
57

enter 0-6:
3
enter number of student to update:
14
Enter details of 5 courses:
1 0 0 0 1

enter 0-6:
4
enter number of student to check rishum:
15
enter number of course to check rishum:
3
ERROR: Student is not in the file
enter 0-6:
4
enter number of student to check rishum:
14
enter number of course to check rishum:
3
The student is not taking the course

enter 0-6:
5
enter number of student to print:
14
Fisrt name: moshe
Last name: cohen
Courses: Y, N, N, N, Y

enter 0-6:
6
enter number of course to check rishum:
2

enter 0-6:
0
*/
