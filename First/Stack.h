#pragma once
#include "Itemes.h"
#include<string>
using namespace std;
class fullstack{};
class emptystack {};
class Stack
{
private:
	int top;
	int size;
	itemtype *item;
public:
	Stack();
	Stack(int size);
	~Stack();
	itemtype push(itemtype value);
	itemtype pop();
	bool isEmpty();
	bool isfull();
	itemtype top_value();
	int fact(int val);
	void Palindrome(string expression);
    void reverse(string s);
	void ConvertBinay(unsigned int BinaryNumber);
	void ReplaceItem(Stack&, itemtype, itemtype);
	bool identical(Stack s1, Stack s2);
};

