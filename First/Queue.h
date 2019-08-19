#pragma once
#include "Itemes.h"
class Queue
{
private :
	int rear = -1;
	int front = -1;
	int size;
	itemtype *item;
public:
	Queue();
	~Queue();
	bool isEmpty();
	bool isfull();
	void Enqueue(itemtype val);
	int Dequeue();
	itemtype front_val();
	void moveNthFront(unsigned int val);
	void length();
	void replace(Queue&, int, int);
};

