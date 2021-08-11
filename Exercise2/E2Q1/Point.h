#pragma once
class Point
{
	float X;
	float Y;

public:
	float getX() const; // x getter
	void setX(int set); // x setter
	float getY() const; // y getter
	void setY(int set); // y setter
	float distanceCalc(const Point other) const; // distance between 2 points

	Point(float x, float y); // constructor
	Point(); // default constructor
};

