#include "Polygon.h"
#include <iostream>
using namespace std;
Polygon::Polygon(int noSides) : numSides(noSides),sides (new int[numSides]) { // constructor
	if (numSides > 4) {
		cout << "enter sides for polygon:" << endl;
		for (int i = 0; i < numSides; i++)
			cin >> sides[i];
	}
}
Polygon::Polygon(const Polygon& other) : numSides(other.numSides), sides (new int[numSides]) {  // copy constructor
	for (int i = 0; i < numSides; i++)
		sides[i] = other.sides[i]; // deep copy
}
int Polygon::getNumSides() const { return numSides; } // numSides getter
int Polygon::circumference() const {
	int sum = 0;
	for (int i = 0; i < numSides; i++)
		sum += sides[i]; // sums the sides sizes
	return sum;
}
bool Polygon::operator== (const Polygon& other) const { // operator == 
	return (numSides == other.numSides) && (circumference() == other.circumference()); // same number of sides and circumference
}