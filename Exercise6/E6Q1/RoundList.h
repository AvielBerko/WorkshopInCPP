#pragma once
#include "List.h"
class RoundList : public List
{
public:
	void addToEnd(int val); // adding a node to the end
	int search(int n) const; // returns the value in the n's position
	void add(int val); // adds a node to the head of the list
	void clear(); // clears the list
	void removeFirst(); // removes the first node
};

