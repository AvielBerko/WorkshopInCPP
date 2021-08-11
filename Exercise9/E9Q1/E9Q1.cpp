// Name: Aviel Berkovich, ID: 211981105
// Workshop in c++
// Exercise 9
// The program uses STL vector and algorithems (with Student polymorphizem)
#include "Student.h"
#include "BA.h"
#include "MA.h"
#include "PHD.h"
#include <vector>
#include <algorithm>

enum option { stop, addNewStudent, milgaList, mostResearch, countMilgaBA, noResearchMA, overheadStudent, removePHDFailers };

void add(vector<Student*>& vec) {
	int choice, id, numOfCourses, *grades = NULL, researchHours;
	char fName[101], lName[101];
	bool isResearch;
	cout << "enter 1 to add a BA student\n";
	cout << "enter 2 to add a MA student\n";
	cout << "enter 3 to add a PHD student\n";
	cin >> choice;
	cout << "enter id, first name, last name and number Of Courses\n";
	cin >> id >> fName >> lName >> numOfCourses;
	switch (choice) {
	case 1: // BA
		grades = new int[numOfCourses]; // dynamic allocation
		cout << "enter " << numOfCourses << " grades\n";
		for (int i = 0; i < numOfCourses; i++)
			cin >> grades[i];
		vec.push_back(new BA(id, fName, lName, numOfCourses, grades)); // insert to vector
		break;
	case 2: // MA
		grades = new int[numOfCourses]; // dynamic allocation
		cout << "enter " << numOfCourses << " grades\n";
		for (int i = 0; i < numOfCourses; i++)
			cin >> grades[i];
		cout << "enter 1 if the student does research and 0 if not\n";
		cin >> isResearch;
		vec.push_back(new MA(id, fName, lName, numOfCourses, grades, isResearch)); // insert to vector
		break;
	case 3: // PHD
		cout << "enter number of research hours\n";
		cin >> researchHours;
		vec.push_back(new PHD(id, fName, lName, numOfCourses, researchHours)); // insert to vector
		break;
	default:
		break;
	}
	if (grades) // if memory was allocated
		delete[] grades; // free the memory
}

void milga(vector<Student*>& vec) {
	for (auto it = vec.begin(); it != vec.end(); it++) // all of the vector
		if ((*it)->milga()) 
			(*it)->print();

}

Student* mostResearchHours(vector<Student*>& vec) {
	Student* maxResearchHours = NULL;
	for (auto it = vec.begin(); it != vec.end(); it++) 
		if ((*it)->studType() == "PHD")
			if (!maxResearchHours || maxResearchHours->getResearchHours() < (*it)->getResearchHours())
				maxResearchHours = (*it);
	return maxResearchHours;
}

int main() {
	vector<Student*> vec;
	int op;
	cout << "enter 0-7\n";
	cin >> op;
	Student* s;
	while (op != stop) {
		switch (op) {
		case addNewStudent:
			add(vec);
			break;
		case milgaList:
			milga(vec);
			break;
		case mostResearch:
			s = mostResearchHours(vec);
			if (s) {
				cout << "PHD studnet with most research hours: ";
				cout << s->getFirstName() << ' ' << s->getLastName() << endl;
			}
			break;
		case countMilgaBA:
			cout << "#BA studnets for milga: ";
			cout << count_if(vec.begin(), vec.end(), [](Student* st) {return st->studType() == "BA" && st->milga(); });
			cout << endl;
			break;
		case noResearchMA:
			cout << "list of no research MA students : ";
			for_each(vec.begin(), vec.end(), [](Student* st) {if (st->studType() == "MA" && !(st->getResearch())) cout << st->getFirstName() << ' ' << st->getLastName(); });
			cout << endl;
			break;
		case overheadStudent:
			if (any_of(vec.begin(), vec.end(), [](Student* st) {return (st->getNumCourses() > 15); }))
				cout << "there is a student that takes more than 15 courses\n";
			else
				cout << "no student takes more than 15 courses\n";
			break;
		case removePHDFailers:
			remove_if(vec.begin(), vec.end(), [](Student* st) { return (st->studType() == "PHD" && st->getNumCourses() == 0); });
			for_each(vec.begin(), vec.end(), [](Student* st) {st->print(); });
			break;
		}
		cout << "enter 0-7\n";
		cin >> op;
	}
}

/*
Example:

--- Input ---
1
1
123
abe
avraham
3
90 100 90
1
1
234
yitzhak
avrahamson
10
100 100 90 100 90 100 90 100 90 100
2
0
--- Program Output ---
enter 0 - 7
1
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
1
enter id, first name, last name and number Of Courses
123
abe
avraham
3
enter 3 grades
90 100 90
enter 0 - 7
1
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
1
enter id, first name, last name and number Of Courses
234
yitzhak
avrahamson
10
enter 10 grades
100 100 90 100 90 100 90 100 90 100
enter 0 - 7
2
ID: 234
first name : yitzhak
last name : avrahamson
num courses : 10
grades : 100 100 90 100 90 100 90 100 90 100
enter 0 - 7
0
*/
