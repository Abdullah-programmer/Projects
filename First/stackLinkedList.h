#pragma once
class fullLinkedList{};
class stackLinkedList
{
public:
	struct Node { Node* next;  int data; };
	Node* head;
	stackLinkedList();
	~stackLinkedList();
	void push(int value);
	void pop();
	bool isEmpty();
	int top_Value();
	long long fact(int val);
};

