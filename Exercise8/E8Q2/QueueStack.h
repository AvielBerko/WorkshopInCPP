#pragma once
#include "Queue.h"
#include "StackList.h"
class QueueStack : public Queue
{
protected:
	StackList* data;
public:
	QueueStack();
	void clear() override;
	int dequeue() override;
	void enqueue(int value) override;
	int front() override;
	bool isEmpty() const override;
};