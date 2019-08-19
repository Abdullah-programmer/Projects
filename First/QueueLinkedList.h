#pragma once
class QueueLinkedList
{
private:
	struct Node { int data; Node *next; };
	Node* front=nullptr, *tail=nullptr;
public:
	QueueLinkedList();
	~QueueLinkedList();
	bool isEmpty();
	void Enqueu(int val);
	void Dequeu();
	int getFront();
};

