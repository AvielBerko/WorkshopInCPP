#pragma once
class Polygon
{
protected:
	int numSides;
	int* sides;

public:
	Polygon(int noSides); // constructor
	Polygon(const Polygon& other); // copy constructor
	int getNumSides() const; // numSides getter
	int circumference() const; // polygon circumference calculate
	bool operator== (const Polygon& other) const; // operator == 
};

