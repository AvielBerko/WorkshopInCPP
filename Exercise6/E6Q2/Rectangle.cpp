#include "Rectangle.h"
Rectangle:: Rectangle(int width, int height) : Polygon(4) {
	sides[0] = width;
	sides[1] = height;
	sides[2] = width;
	sides[3] = height;
}