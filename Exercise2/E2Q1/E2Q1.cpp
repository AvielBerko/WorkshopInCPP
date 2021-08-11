// Name: Aviel Berkovich, ID: 211981105
// Workshop in c++
// Exercise 2, Question 1
/* The program calculates a circumference of a polygon*/
#include <iostream>
#include <cmath>
#include "Polygon.h"
using namespace std;

int main() {
	int sides;
	cout << "enter number of sides:" << endl;
	cin >> sides;
	while (sides < 3) {
		cout << "ERROR" << endl;
		cin >> sides;
	}
	cout << "enter points:" << endl;
	Polygon Pol(sides);
	float x, y;
	for (int i = 0; i < sides; i++) {
		cin >> x >> y;
		Pol.setVertex(Point(x, y), i); // sets all vertexes
	}
	cout << round(Pol.circumferenceCalc()) << endl; // calculates the circumference
	return 0;
}

/*
Example:

--- Input ---
3
10 10 10 14 13 10
--- Program Output ---
enter number of sides:
3
enter points:
10 10 10 14 13 10
12

*/
