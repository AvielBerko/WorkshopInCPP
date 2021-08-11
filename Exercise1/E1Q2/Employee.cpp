#include "Employee.h"
#include <cstring>
#include <string>
#include "Employee.h"
#pragma warning (disable:4996)
const float MINIMUN_WAGE = 29.12; // minimun wage in Israel

int Employee::getID() const { return ID; } // ID getter
void Employee::setID(int set) { ID = set; } // ID setter
char* Employee::getName() { return name; } // name getter
void Employee::setName(const char* set) { strcpy(name, set); } // name setter
float Employee::getWagePerHour() const { return wagePerHour; } // wagePerHour getter
void Employee::setWagePerHour(float set) { wagePerHour = set; } // wagePerHour setter
int Employee::getHoursWorked() const { return hoursWorked; } // hoursWorked getter
void Employee::setHoursWorked(int set) { hoursWorked = set; } // wagePerHour setter
int Employee::getOvertimeHours() const { return overtimeHours; } // OvertimeHours getter
void Employee::setOvertimeHours(int set) { overtimeHours = set; } // wagePerHour setter
float Employee::wageCalc() const { return wagePerHour * hoursWorked + 1.5 * wagePerHour * overtimeHours; } // wage calculate

Employee::Employee(int ID, char* name, float wagePerHour, int hoursWorked, int overtimeHours) :
	ID(ID), wagePerHour(wagePerHour), hoursWorked(hoursWorked), overtimeHours(overtimeHours) { // constructor
	strcpy(Employee::name, name);
}
Employee::Employee() { ID = 0; name[0] = '\0'; wagePerHour = MINIMUN_WAGE; hoursWorked = 0; overtimeHours = 0; }; // default constructor