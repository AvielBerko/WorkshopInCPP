#include "Point.h"
#include <cmath>
float Point::getX() const { return X; } // x getter
void Point::setX(int set) { X = set; } // x setter
float Point::getY() const { return Y; } // y getter
void Point::setY(int set) { Y = set; } // y setter
float Point::distanceCalc(const Point other) const { // distance between 2 points
	return sqrt((pow(X - other.X, 2) + pow(Y - other.Y, 2)));
}


Point::Point(float x, float y) : X(x), Y(y) {} // constructor
Point::Point() : X(0), Y(0) {} // default constructor


