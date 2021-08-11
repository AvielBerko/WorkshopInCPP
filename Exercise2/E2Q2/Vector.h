#pragma once
class Vector
{
	int* data;
	int capacity;
	int size;

public:
	int getCapacity() const; // capacity getter
	int getSize() const; // size getter
	void print() const; // prints the vector
	void assign(Vector other); // operator =
	bool isEqual(Vector& other) const; // checks if equal
	int& at(int index); // operator []
	int strcatcat(Vector& other) const; // dot product
	Vector strnewcat(Vector& other) const; // concatenates 2 vectors
	void clear(); // clears the vector
	void delLast(); // deletes the last cell 
	void insert(int val); // inserts a new cell
	Vector(int cap = 10); // constructor
	Vector(const Vector& other); // copy constructor
	~Vector(); //destructor 
};

