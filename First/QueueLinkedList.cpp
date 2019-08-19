#include "stdafx.h"
#include "QueueLinkedList.h"


QueueLinkedList::QueueLinkedList()
{
	front = nullptr; tail = nullptr;
}
QueueLinkedList::~QueueLinkedList()
{
	front = nullptr; tail = nullptr;
}
bool QueueLinkedList::isEmpty() {
	if (front == nullptr && tail==nullptr) return true;
	return false;
}
void QueueLinkedList::Enqueu(int val)
{
	Node* newnode = new Node;
	newnode->data = val;
	newnode->next = nullptr;
	if (isEmpty()) { tail = front = newnode; }
	else {
		tail->next = newnode;
		tail = newnode;
	}
}
void QueueLinkedList::Dequeu()
{
	if (isEmpty()) return;
	Node* temp = front;
	 if (front == tail) front = tail = nullptr;
	else front = front->next;
	delete temp;
}
int QueueLinkedList::getFront()
{
	if (isEmpty()) return -1;
	return front->data;
}
