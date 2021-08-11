#include "List.h"
//------------------------------------------------
//  class Link implementation
//------------------------------------------------
List::Link::Link(int val, Link* nxt) : value(val), next(nxt) {}


List::Link::Link(const Link& other) : value(other.value), next(other.next) {}

//--------------------------------------------
//  class List implementation
//--------------------------------------------
List::List() : head(NULL) { // no further initialization
}

List::List(const List& other) {
	Link* src, *trg;
	if (other.head == NULL)
		head = NULL;
	else {
		head = new Link((other.head)->value, NULL);
		src = other.head;
		trg = head;
		while (src->next != NULL) {
			trg->next = new Link((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
	}
}

List::~List() {
	clear();
}

void List::clear() {
	// empty all elements from the List
	Link* theNext;
	for (Link* p = head; p != NULL; p = theNext) {
		// delete the element pointed to by p
		theNext = p->next;
		p->next = NULL;
		delete p;
	}
	// mark that the List contains no elements
	head = NULL;
}

bool List::isEmpty() const {
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null
	return head == NULL;
}

void List::add(int val) {
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == NULL)
		throw "failed in memory allocation";
}

int List::firstElement() const {
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}
bool  List::search(const int& val) const {
	// loop to test each element
	for (Link* p = head; p != NULL; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}

void List::removeFirst() {
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = NULL;
	// recover memory used by the first element
	delete p;
}
// operators
List& List::operator=(const List& other) { // operator= - Like copy constructor
	clear(); // clears the list
	Link* src, * trg;
	if (other.head == NULL)
		head = NULL;
	else {
		head = new Link((other.head)->value, NULL);
		src = other.head;
		trg = head;
		while (src->next != NULL) {
			trg->next = new Link((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
	}
	return *this;
}
ostream& operator<<(ostream& os, const List& L) { // operator <<
	List::Link* p = L.head;
	while (p != NULL) {
		os << p->value << " ";
		p = p->next;
	}
	return os;
}
istream& operator>>(istream& is, List& L) { // operator >>
	int temp;
	is >> temp;
	L.add(temp); // builds the first Link
	List::Link* p = L.head;
	
	is >> temp;
	while (temp > p->value) {
		//L.addToEnd(temp);
		p->next = new List::Link(temp, NULL);
		p = p->next;
		is >> temp;
	}
	return is;
}
void List::insert(int key)
{
	if (head == NULL){ // list is empty
		head = new Link(key, NULL);
		return;
	}

	if (key < head->value){ // checks the first element
		head = new Link(key, head);
		return;
	}

	Link* p1 = head;// checks the list
	while (p1->next != NULL) {
		if (key < p1->next->value) {
			p1->next = new Link(key, p1->next);
			return;
		}
		p1 = p1->next;
	}
	p1->next = new Link(key, NULL); // the value is the last one
}

void List::remove(int key)
{
	if (head == NULL) // empty list
		throw "value not found";

	if (key == head->value) { // checks the first element
		removeFirst();
		return;
	}
	Link* p1 = head, * p2 = p1->next;
	while (p2 != NULL) // checks the list
	{
		if (key == p2->value) { // value was found 
			p1->next = p2->next;
			p2->next = NULL;
			delete p2;
			return;
		}
		p1 = p2;
		p2 = p2->next;
	}
	delete p1, p2;
	throw "value not found";
}
