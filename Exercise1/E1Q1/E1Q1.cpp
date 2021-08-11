// Name: Aviel Berkovich, ID: 211981105
// Workshop in c++
// Exercise 1, Question 1
// The program recives 2 rational numbers and checks if they are equal 
#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{
	cout << "enter two rational numbers" << endl;
	int nu1, de1, nu2,  de2;
	{
		char slash; // removes the slash (temp variable)
		cin >> nu1 >> slash >> de1 >> nu2 >> slash >> de2;
	}
	Rational R1(nu1, de1), R2(nu2, de2); // builds the 2 Rational numbers
	if (R1.equal(R2)) // checks if the numbers are equal
		cout << "equal" << endl;
	else {
		cout << "different ";
		R1.print();
		cout << " ";
		R2.print();
		cout << endl;
	}
	return 0;
}


/*
Example:

--- Input ---
-15/5 6/-2

--- Program Output ---
enter two rational numbers
-15/5 6/-2
equal
*/