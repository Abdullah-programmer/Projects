#include "stdafx.h"
#include "Stack.h"
#include<iostream>
Stack::Stack()
{
	top = -1;
	//cout << "enter size of array" << endl;
	//cin >> size;
	size=100;
	item = new itemtype[size];
}
Stack::Stack(int size)
{
	top = -1;
	size = this->size;
	item = new itemtype[size];
}
Stack::~Stack()
{
	delete [] item;
}
itemtype Stack::push(itemtype value)
{
	if (isfull()) throw fullstack();
	top++;
	item[top] = value;
	return item[top];
}
itemtype Stack::pop()
{
	if (isEmpty()) throw emptystack();
	return item[top--];
}
bool Stack::isEmpty()
{
	if (top == -1) return true;
	return false;
}
bool Stack::isfull()
{
	if (top == (size - 1)) return true;
	else return false;

}
itemtype Stack::top_value()
{
	if (isEmpty()) return -1;
	return item[top];
}
int Stack :: fact(int val)
{
	Stack fac; int factorial = 1;
	for (int i = 1; i <= val; i++)
	{
		fac.push(i);
		factorial = factorial * fac.top_value();
		fac.pop();
	}
	return factorial;
}
void Stack::Palindrome(string expression)
{
	Stack exp; char ch; bool palindrome; 
	for (int i = 0; i < expression.length(); i++)
	{
		exp.push(expression[i]);
		ch = exp.top_value();
		if (ch == expression[(expression.length()-1)-i])   palindrome = true;		
		else { palindrome = false; break; }
		exp.pop();
	}
	if (palindrome) cout << "the expression is palindrome " << endl;		
	else cout << "the expression is not palindrome " << endl;
}
void Stack::reverse(string s)
{
	Stack st; 
	for (int i = 0; i < s.length(); i++)
	{
		st.push(s[i]);
	}
	while (!st.isEmpty())
	{
		cout << st.top_value();
		st.pop();
	}
}
void Stack::ConvertBinay(unsigned int BinaryNumber)
{
	Stack Binary; unsigned int  DecimalNumber, SumDecimalNumber = 0, DivideBinaryNumber;
	int length = ceil(log10(BinaryNumber));
	cout << "Enter binary number like(01101) to convert decimal" << endl;
	for (int i = 0; i <= length ; i++)
	{
		DivideBinaryNumber = BinaryNumber % 10;
		Binary.push(DivideBinaryNumber);
		BinaryNumber /= 10;
		DecimalNumber = pow(2, i)*Binary.top_value();
		SumDecimalNumber += DecimalNumber;
		Binary.pop();
	}
	cout << "Decimal is :" << SumDecimalNumber << endl;
}
void Stack::ReplaceItem(Stack& stack, itemtype oldItem, itemtype newItem) {


	Stack temp;
	itemtype item;
	while (!stack.isEmpty()) {

		item = stack.top_value();

		if (item == oldItem) {

			temp.push(newItem);
		}
		else {

			temp.push(item);
		}
		stack.pop();

	}


	while (!temp.isEmpty()) {

		stack.push(temp.top_value());
		temp.pop();
	}

}
bool Stack::identical(Stack s1, Stack s2)
{
	bool identical = true;
	while (!s1.isEmpty() && !s2.isEmpty())
	{
		if (s1.top_value() != s2.top_value())
		{
			identical = false;
			break;
		}
		else {
			s1.pop(); s2.pop();
		}
		
	}
if (!s1.isEmpty() || !s2.isEmpty()) identical = false;
	return identical;
}

