#pragma once
class Employee
{
	int ID;
	char name[21];
	float wagePerHour;
	int hoursWorked;
	int overtimeHours;

public:
	int getID() const; // ID getter
	void setID(int set); // ID setter
	char* getName(); // name getter
	void setName(const char* set); // name setter
	float getWagePerHour() const; // wagePerHour getter
	void setWagePerHour(float set); // wagePerHour setter
	int getHoursWorked() const; // hoursWorked getter
	void setHoursWorked(int set); // wagePerHour setter
	int getOvertimeHours() const; // OvertimeHours getter
	void setOvertimeHours(int set); // wagePerHour setter
	float wageCalc() const; // wage calculate

	Employee(int ID, char* name, float wagePerHour, int hoursWorked, int overtimeHours); // constructor
	Employee(); // default constructor
};

