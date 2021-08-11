#include "Polygon.h"

int Polygon::getNumOfVertexes() const { return numOfVertexes; } // number of vertexes getter
void Polygon::setNumOfVertexes(int set) { numOfVertexes = set; } // number of vertexes setter
void Polygon::setVertex(Point p, int index) { // sets a vertex
    if (index < numOfVertexes)
        vertexes[index] = p;
}
Polygon::Polygon(int numOfV) : numOfVertexes(numOfV), vertexes(new Point[numOfV]) {} // constructor
Polygon::Polygon() : numOfVertexes(3), vertexes(new Point[3]) {} // default constructor - minimun vertexes of a polygon is 3
Polygon::Polygon(const Polygon& other) : numOfVertexes(other.numOfVertexes) { // copy constructor
    vertexes = new Point[numOfVertexes];
    for (int i = 0; i < other.numOfVertexes; i++)
        vertexes[i] = other.vertexes[i];
}
Polygon::~Polygon() { delete[] vertexes; } // destructor
float Polygon::circumferenceCalc() const { // circumference calculate
    float cirucmference = 0;
    for (int i = 0; i < numOfVertexes - 1; i++)
        cirucmference += vertexes[i].distanceCalc(vertexes[i + 1]); // distance between 2 close vertexes
    cirucmference += vertexes[0].distanceCalc(vertexes[numOfVertexes - 1]); // the distance between the last and first vertexes
    return cirucmference;
}
