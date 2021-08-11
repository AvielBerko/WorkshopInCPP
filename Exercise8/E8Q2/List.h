#pragma once
#include <iostream>
using namespace std;
//------------------------------------------------
//  class List
//      arbitrary size Lists
//      permits insertion and removal 
//      only from the front of the List
//------------------------------------------------
class List
{
protected:
	//--------------------------------------------
	//  inner class link
	//  a single element for the linked List 
	//--------------------------------------------
	class Link
	{
	public:
		Link(int linkValue, Link* nextPtr); // constructor
		Link(const Link& other); // copy constructor
		// data areas
		int value;
		Link* next;
	};	//end of class Link
public:
	// constructors
	List();
	List(const List& other);
	~List();

	// operations
	void add(int val);
	int firstElement() const;
	bool search(const int& val) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();
	void insert(int val);
	void remove(int val);
	// operators
	List& operator=(const List& other); // operator=
	friend ostream& operator<< (ostream& os, const List& L); // operator <<
	friend istream& operator>>(istream& is, List& L); // operator >>

protected:
	// data field
	Link* head;
};

