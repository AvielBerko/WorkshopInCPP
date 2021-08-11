#pragma once
#include "Point.h"
class Polygon
{
	int numOfVertexes; 
	Point* vertexes;
public:
	int getNumOfVertexes() const; // number of vertexes getter
	void setNumOfVertexes(int set); // number of vertexes setter
	void setVertex(Point p, int index); // sets a vertex
	Polygon(int numOfV); // constructor
	Polygon(); // default constructor
	Polygon(const Polygon& other); // copy constructor
	~Polygon(); // destructor
	float circumferenceCalc() const; // circumference calculate

};

