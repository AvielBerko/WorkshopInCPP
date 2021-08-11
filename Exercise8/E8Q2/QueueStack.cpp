#include "QueueStack.h"
QueueStack::QueueStack() { data = new StackList(); }
void QueueStack::clear() { data->clear(); }
int QueueStack::dequeue() {
	if (!isEmpty()) {
		StackList stk;
		while (!data->isEmpty())
			stk.push(data->pop()); // copy and reverse the stack
		int val = stk.pop(); // remove the first element
		while (!stk.isEmpty())
			data->push(stk.pop()); // recopy the stack
		return val;
	}
	return -1; // was empty
}
void QueueStack::enqueue(int value) { data->push(value); }
int QueueStack::front() {
	if (!isEmpty()) {
		StackList stk;
		while (!data->isEmpty())
			stk.push(data->pop()); // copy and reverse the stack
		int val = stk.top(); // saves the first element
		while (!stk.isEmpty())
			data->push(stk.pop()); // recopy the stack
		return val;
	}
	return -1; // was empty
}
bool QueueStack::isEmpty() const { return data->isEmpty(); }