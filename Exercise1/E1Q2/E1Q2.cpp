// Name: Aviel Berkovich, ID: 211981105
// Workshop in c++
// Exercise 1, Question 2
/* The program recives employees, and prints the hardest worker and the highst wage employees*/
#include <iostream>
#include <cstring>
#include <string>
#include "Employee.h"
#pragma warning (disable:4996)
using namespace std;

int main() {
	Employee highestWageEmployee, hardestWorkerEmployee;
	int ID, hours, otHours;
	char name[21];
	float wage;
	cout << "enter details, to end enter 0" << endl;
	cin >> ID;
	do { // we can assume that the first ID is not 0
		cin >> name >> wage >> hours >> otHours;
		if (ID >= 0 && wage >= 0 && hours >= 0 && otHours >= 0) // checks if all fields are valid
		{
			Employee temp(ID, name, wage, hours, otHours);
			if (temp.wageCalc() > highestWageEmployee.wageCalc())
				highestWageEmployee = temp;
			if (temp.getHoursWorked() + temp.getOvertimeHours() > hardestWorkerEmployee.getHoursWorked() + hardestWorkerEmployee.getOvertimeHours())
				hardestWorkerEmployee = temp;
		}
		else
			cout << "ERROR" << endl;
		cin >> ID;
	} while (ID); // until the ID is 0

	cout << "highest salary: " << highestWageEmployee.getID() << " " << highestWageEmployee.getName() << endl;
	cout << "hardest worker: " << hardestWorkerEmployee.getID() << " " << hardestWorkerEmployee.getName() << endl;

	return 0;
}
/*
Example:

--- Input ---
123456789 avrakam 50 40 2
135792468 yaakov 100 30 0
975312468 sara 30 45 100
194857185 moshe -40 39 2
192848423 moshe 60 60 28

--- Program Output ---
enter details, to end enter 0
123456789 avrakam 50 40 2
135792468 yaakov 100 30 0
975312468 sara 30 45 100
194857185 moshe -40 39 2
ERROR
192848423 moshe 60 60 28
0
highest salary : 192848423 moshe
hardest worker : 975312468 sara
*/
