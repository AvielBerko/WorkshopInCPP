#include "Circle.h"
#include "Point.h"
#include <cmath>
const float PI = 3.14;

Point Circle::getCenter() const { return center; }// center getter
void Circle::setCenter(Point set) { center = set; }// center setter
float Circle::getRadius() const { return radius; } // radius getter
void Circle::setRadius(float set) { radius = set; } // radius setter

float Circle::areaCalc() const { return PI * radius * radius; } // calculates the area
float Circle::circumferenceCalc() const { return 2 * PI * radius; } // calculates the circumference
int Circle::checkIfOnTheCircle(Point p) const { // check if a point is inside, outside or on the circle
	float distance = (pow(center.getX() - p.getX(), 2) + pow(center.getY() - p.getY(), 2)); // checks the distans from the point to the center
	return (distance == radius * radius) ? 0 : ((distance > radius * radius) ? 1 : -1);
}


Circle::Circle(Point cen, float rad) : center(cen), radius(rad) {} // constructor
Circle::Circle() : center(Point(0, 0)), radius(0) {}  // default constructor


