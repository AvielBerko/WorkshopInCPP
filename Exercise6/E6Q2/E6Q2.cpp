// Name: Aviel Berkovich, ID: 211981105
// Workshop in c++
// Exercise 6 Question 2
// The program simulates Polygons
#include <iostream>
#include "Polygon.h"
#include "Triangle.h"
#include "Rectangle.h"
using namespace std;

int main()
{
	// 6 empty pointers
	Triangle* T1 = NULL, * T2 = NULL;
	Rectangle* R1 = NULL, * R2 = NULL;
	Polygon* P1 = NULL, * P2 = NULL;
	cout << "enter number of sides for polygon 1:" << endl;
	int numSides1;
	cin >> numSides1;
	if (numSides1 > 4)
		P1 = new Polygon(numSides1); // polygon - more than 4 sides (dymanic allocation)
	else {
		int a, b, c;
		cout << "enter sides for polygon:" << endl;
		if (numSides1 == 3) {
			cin >> a >> b >> c;
			T1 = new Triangle(a, b, c); // tringle - 3 sides(dymanic allocation)
		}
		else if (numSides1 == 4) {
			cin >> a >> b;
			R1 = new Rectangle(a, b); // rectangle - 4 sides(dymanic allocation)
		}
	}
	cout << "enter number of sides for polygon 2:" << endl;
	int numSides2;
	cin >> numSides2;
	if (numSides1 != numSides2)
		cout << "not equal" << endl;
	else {
		if (numSides2 > 4) {
			P2 = new Polygon(numSides2); // polygon - more than 4 sides (dymanic allocation)
			if (*P1 == *P2) // if the polygons are equal
				cout << "equal" << endl;
			else
				cout << "not equal" << endl;
		}
		else {
			int a, b, c;
			cout << "enter sides for polygon:" << endl;
			if (numSides2 == 3) {
				cin >> a >> b >> c;
				T2 = new Triangle(a, b, c); // tringle - 3 sides(dymanic allocation)
				if (*T1 == *T2) // if the tringles are equal
					cout << "equal" << endl;
				else
					cout << "not equal" << endl;
			}
			else if (numSides2 == 4) {
				cin >> a >> b;
				R2 = new Rectangle(a, b); // rectangle - 4 sides(dymanic allocation)
				if (*R1 == *R2) // if the rectangles are equal
					cout << "equal" << endl;
				else
					cout << "not equal" << endl;
			}
		}
	}
	// free the memory from the dynamic allocation
	if (P1) delete P1;
	if (P2) delete P2;
	if (R1) delete R1;
	if (R2) delete R2;
	if (T1) delete T1;
	if (T2) delete T2;
	return 0;
}

/*
Example:

--- Input ---
3
20 10 15
3
11 14 20
--- Program Output ---
enter number of sides for polygon 1:
3
enter sides for polygon:
20 10 15
enter number of sides for polygon 2:
3
enter sides for polygon:
11 14 20
equal
*/
