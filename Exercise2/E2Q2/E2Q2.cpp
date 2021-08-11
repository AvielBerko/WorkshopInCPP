// Name: Aviel Berkovich, ID: 211981105
// Workshop in c++
// Exercise 2, Question 1
/* The program simulates vectors operations*/
#include "Vector.h"
#include <iostream>
using namespace std;
enum options
{
	stop, assignment, isEqual, mult, add, clear, delLast
};
int main()
{
	Vector  v1(10), v2(10), v3;
	for (int i = 1; i <= 4; i++)
	{
		v1.insert(i);
		v2.insert(i + 4);
	}
	int choice, val;
	cout << "enter your choice 0-6\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case assignment: v3.assign(v1);
			break;
		case isEqual:	if (v1.isEqual(v2)) cout << "v1==v2\n"; else cout << "v1!=v2\n";
			break;
		case mult:		cout << "v1*v2=" << v1.strcatcat(v2) << endl;
			break;
		case add:		v3.assign(v1.strnewcat(v2));
			break;
		case clear:		v1.clear();
			break;
		case delLast:	       v2.delLast();
			break;
		default: cout << "ERROR";
		}
		v1.print();		v2.print();		v3.print();
		cout << "enter your choice 0-6\n";
		cin >> choice;
	}
	return 0;
}

/*
Example:

--- Input ---
4
0
--- Program Output ---
enter your choice 0-6
4
capacity: 10 size: 4 val: 1 2 3 4
capacity: 10 size: 4 val: 5 6 7 8
capacity: 20 size: 8 val: 1 2 3 4 5 6 7 8
enter your choice 0-6
0
*/