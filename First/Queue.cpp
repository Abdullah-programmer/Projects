#include "stdafx.h"
#include "Queue.h"
#include<iostream>
using namespace std;
Queue::Queue()
{
	front = rear = -1;
	size = 100;
	item = new itemtype[size];
}
Queue::~Queue()
{
	front = rear = -1;
}
bool Queue::isEmpty()
{
	if (front == -1 && rear == -1) return true;
	return false;
}
bool Queue::isfull()
{
	if (rear == (size-1)) return true;
	return false;
}
void Queue::Enqueue(itemtype val)
{
	if (isfull()) return;
	else if (isEmpty())
	{
		front = rear = 0;
	}
	else { rear++; }
	item[rear] = val;
}
itemtype Queue::Dequeue()
{
	if (isEmpty()) return -1;
	//else if (front == rear)   front = rear = -1;
	else return item[front++];
}
itemtype Queue::front_val() {
	if (isEmpty()) return -1;
	return item[front];
}
void Queue::moveNthFront(unsigned int position)
{
	Queue q;  int temp;
	q.Enqueue(5); q.Enqueue(11); q.Enqueue(34); q.Enqueue(67); q.Enqueue(43); q.Enqueue(55); 
	temp = q.item[q.front];
	q.item[q.front] = q.item[position-1];
	for (int i = position-1; i > 1; i--)
	{
		q.item[i] = q.item[i-1];
	}
	q.item[q.front + 1] = temp;
	while (!q.isEmpty())
	{
		cout << q.front_val() << " ";
		q.Dequeue();
	}
	cout << endl;
}
void Queue::length()
{
	Queue q;
	int count = 0;
	q.Enqueue(1); q.Enqueue(2); q.Enqueue(3); q.Enqueue(1); q.Enqueue(1);
	while (!q.isEmpty())
	{
		q.Dequeue();
		count++;
	}
	cout <<" Numbers of items in queue is :" << count << endl;
}
//void Queue::replace(Queue& k, int o, int n) {
//	Queue j;
//	while (!k.isEmpty())
//	{
//		int item;
//		k.Dequeue();
//		if (item == o)
//			k.Enqueue(n);
//		else
//			k.Enqueue(item);
//
//	}
//	while (!j.isEmpty())
//	{
//		int y;
//		j.Dequeue();
//		k.Enqueue(y);
//	}
//}