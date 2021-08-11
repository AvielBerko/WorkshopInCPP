#include "RoundList.h"
void RoundList::addToEnd(int val) { // adding a node to the end
	if (isEmpty()) { // list is empty
		add(val); // add to the start
		return;
	}
	Link* p = head;
	while (p->next != head) // until the next is the head (last node)
		p = p->next; // move to next node
	p->next = new Link(val, head);
}
int RoundList::search(int n) const { // returns the value in the n's position
	if (isEmpty()) // list is empty
		return -1;
	Link* p = head;
	for (int i = 0; i < n; i++) // repeat n times
		p = p->next; // move to next node
	return p->value;
}
void RoundList::add(int val) { // adds a node to the head of the list
	if (isEmpty()) {  // list is empty
		head = new Link(val, NULL);
		head->next = head; // head's next is head
		return;
	}
	Link* p = head;
	while (p->next != head) // until the next is the head (last node)
		p = p->next; // move to next node
	head = new Link(val, head);
	p->next = head;
}
void RoundList::clear() { // clears the list
	while (!isEmpty())
		removeFirst();
}
void RoundList::removeFirst() { // removes the first node
	if (isEmpty())
		return;
	if (head->next == head) { // only one node
		Link* p = head;
		delete p;
		head = NULL;
		return;
	}
	Link* p = head;
	while (p->next != head) // until the next is the head (last node)
		p = p->next; // move to next node
	p->next = head->next;
	p = head;
	head = p->next;
	p->next = NULL;
	delete p;
}