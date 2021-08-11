#include "Vector.h"
#include <iostream>
//#define cout std::cout
//#define endl std::endl

int Vector::getCapacity() const { return capacity; } // capacity getter

int Vector::getSize() const { return size; } // size getter

void Vector::print() const { // prints the vector

	std::cout << "capacity: " << capacity << " size: " << size << " val: ";
	for (int i = 0; i < size; i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;
} 

void Vector::assign(const Vector other) { // operator =
	capacity = other.capacity;
	size = other.size;
	delete[] data;
	data = new int[capacity]; // new allocation
	for (int i = 0; i < size; i++)
		data[i] = other.data[i]; // copies the cells
} 

bool Vector::isEqual(Vector& other) const { // checks if equal
	if (size != other.size) // not the same size
		return false;
	for (int i = 0; i < size; i++) {
		if (data[i] != other.data[i]) // one of the cells is different
			return false;
	}
	return true;
} 

int& Vector::at(int index) { // operator []
	if (index < 0 || index >= size) // invalid index
		std::cout << "ERROR" << std::endl;
	else return data[index]; // returns a reference to the cell
}

int Vector::strcatcat(Vector& other) const { // dot product
	if (size != other.size) { // if not the same size
		std::cout << "ERROR" << std::endl;
		return -1;
	}
	int result = 0;
	for (int i = 0; i < size; i++)
		result += data[i] * other.data[i]; // sums the products
	return result; 
} 

Vector Vector::strnewcat(Vector& other) const { // concatenates 2 vectors
	Vector v(capacity + other.capacity);// new vector with the size and capacity of the 2 vectors combined
	v.size = size + other.size;
	for (int i = 0; i < size; i++) // copies the first vector
		v.data[i] = data[i];
	for (int i = size; i < v.size; i++) // copies the second vector
		v.data[i] = other.data[i - size];
	return v;
}

void Vector::clear() { // clears the vector
	size = 0;
} 

void Vector::delLast() { // deletes the last cell 
	if (size)
		size--;
	else
		std::cout << "ERROR" << std::endl;
} 

void Vector::insert(int val) { // inserts a new cell
	if (size < capacity)
		data[size++] = val;
	else
		std::cout << "ERROR" << std::endl;
}
Vector::Vector(int cap) : capacity(cap), size(0), data(new int[cap]) {} // constructor

Vector::Vector(const Vector& other) : capacity(other.capacity), size(other.size), data(new int[capacity]) { // copy constructor
	for (int i = 0; i < size; i++)
		data[i] = other.data[i];
}

Vector::~Vector() { if (data) delete[] data; data = NULL; } //destructor
