// Name: Aviel Berkovich, ID: 211981105
// Workshop in c++
// Exercise 3, Question 1
// The program recives 2 rational numbers and manipulates them (using operators) 

#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{
	cout << "enter two rational numbers" << endl << "a: ";
	// receives the 2 Rational numbers
	Rational a, b;
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "b - a: "; (b - a).print();
	cout << "a != b: "; (a != b) ? cout << "true" << endl : cout << "false" << endl;
	cout << "a < b: "; (a < b) ? cout << "true" << endl : cout << "false" << endl;
	cout << "a > b: "; (a > b) ? cout << "true" << endl : cout << "false" << endl;
	cout << "a >= b: "; (a >= b) ? cout << "true" << endl : cout << "false" << endl;
	cout << "a++: "; (a++).print();
	cout << "--a: "; (--a).print();
	cout << "a--: "; (a--).print();
	b = a;
	cout << "b - a: "; (b - a).print();
	cout << "b / a: "; (b / a).print();
	cout << "a != b: "; (a != b) ? cout << "true" << endl : cout << "false" << endl;
	cout << "a < b: "; (a < b) ? cout << "true" << endl : cout << "false" << endl;
	cout << "a >= b: "; (a >= b) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}


/*
Example:

--- Input ---
-2/-3
3/4

--- Program Output ---
Enter two rational numbers				
a : 2/3
b : 3/4
b - a : 1/12
a != b : true
a<b : true
a>b : false
a >= b : false
a++ : 2/3
--a : 2/3
a-- : 2/3
b - a : 0
b / a : 1
a != b : false
a < b : false
a >= b : true
*/

