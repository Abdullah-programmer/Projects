#include "stdafx.h"
#include "stackLinkedList.h"
stackLinkedList::stackLinkedList()
{
	head = nullptr;
}
stackLinkedList::~stackLinkedList()
{
	head = nullptr;
}
void stackLinkedList::push(int value)
{
	Node* newnode = new Node;
	newnode->data = value;
	if (isEmpty())
		newnode->next = nullptr;
	else
		newnode->next = head;
	    head = newnode;
}
void stackLinkedList::pop()
{
	if (isEmpty()) return;
		Node* temp = head;
	   head = head->next;
	   delete temp;
}
bool stackLinkedList::isEmpty()
{
	if (head == nullptr) return true;
	return false;
}
 int stackLinkedList::top_Value()
{
	if (isEmpty()) return -1;
	return head->data;
}
long long stackLinkedList::fact(int val)
 {
	 stackLinkedList fac; long long  factorial = 1;
	 for (int i = 1; i <= val; i++)
	 {
		 fac.push(i);
		 factorial = factorial * fac.top_Value();
		 fac.pop();
	 }
	 return factorial;
 }
