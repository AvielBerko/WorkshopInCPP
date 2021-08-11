#pragma once
#include "Point.h"
class Circle
{
	Point center;
	float radius;

public:
	Point getCenter() const; // center getter
	void setCenter(Point set); // center setter
	float getRadius() const; // radius getter
	void setRadius(float set); // radius setter

	float areaCalc() const; // calculates the area
	float circumferenceCalc() const; // calculates the circumference
	int checkIfOnTheCircle(Point p) const; // check if a point is inside, outside or on the circle

	Circle(Point cen, float rad); // constructor
	Circle(); // default constructor
};

