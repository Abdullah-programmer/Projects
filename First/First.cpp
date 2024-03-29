// First.cpp : Definthe entry point for the console application.
#include "stdafx.h"
#include<iostream>
#include<stack>
#include "Stack.h"
#include "Queue.h"
#include "stackLinkedList.h"
#include"QueueLinkedList.h"
#include<queue>
#include<string>
#include<algorithm>
#include<exception>
#include<vector>
#include<iomanip>
using namespace std;
typedef short item;
#define all(v)
#define sz(v)

class LinkedList {
	struct Node { Node* next; item data; };
public:
	~LinkedList() { 
		Node *temp = Head;
		while (Head != nullptr)
		{
			Head = Head->next;
			delete temp;
			temp = Head;
		}
	}
	Node* Head = NULL;
	void Appand(item value)
	{
		Node* newnode = new Node;
		newnode->data = value;
		newnode->next = NULL;
		if (Head == NULL)
		{
			Head = newnode;
		}
		else {
			Node* temp = Head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newnode;
		}
	}
	void display()
	{
		Node *temp = Head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void remove(int val) {
		if (Head == NULL) return;
		Node* temp, *prev;
		temp = prev = Head;
		if (temp->data == val) {
			Head = temp->next;
			delete temp;
			return;
		}
		while (temp != NULL && temp->data != val)
		{
			prev = temp;
			temp = temp->next;
		}
		if (temp == NULL/* && temp->data == val*/)
		{
			//prev->next = NULL;
			return;
		}
		else
		{
			prev->next = temp->next;
			delete temp;
		}

	}
	void insert_at_position(int val, int pos) {
		Node* newnode = new Node;
		Node* temp = Head;
		newnode->data = val;
		newnode->next = nullptr;
		if (pos == 0) {
			newnode->next = Head;
			Head = newnode;
			return;
		}
		for (int i = 0; i < pos - 1; i++)
		{
			if (temp->next == nullptr) break;
			temp = temp->next;
		}
		newnode->next = temp->next;
		temp->next = newnode;

	}
	void delete_at_position(int pos) {
		if (Head == NULL) return;
		Node* temp, *temp2;
		temp = Head;
		if (pos == 0) {
			Head = Head->next;
			delete temp;
			return;
		}
		for (int i = 0; i < pos - 1; i++)
		{
			if (temp->next == nullptr) break;
			temp = temp->next;
		}
		if (temp->next == NULL) return;
		temp2 = temp->next;
		temp->next = temp->next->next;
		delete temp2;
	}
	void reverse() {
		Node* prev, *curr, *next;
		curr = Head; prev = next = nullptr;
		if (Head == NULL)return;
		while (curr != NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		Head = prev;
	}
	void search(int val) {
		bool isFound = false; int pos = 0;
		Node* temp = Head;
		if (Head == NULL)return;
		while (temp != NULL)
		{
			if (temp->data != val) {
				temp = temp->next;
				pos++;
			}
			else
			{
				isFound = true;
				break;
			}
		}
		if (isFound) cout << "Value is found and index in list is " << pos << endl;
		else cout << "Value is not found and is at postion " << -1 << endl;
	}
	void getNthNode() {
		int count = 0;
		Node* temp = Head;
		if (Head == NULL)return;
		while (temp != NULL)
		{
			temp = temp->next;
			count++;
		}
		cout << " Number of nodes is " << count << endl;
	}
	void DeleteOdd() {
		Node* temp = Head; Node* prev = Head;
		if (Head == nullptr)return;
		if (temp->data % 2 != 0)
		{
			Head = temp->next;
			//delete temp;
		}
		while (temp != NULL)
		{
			if (temp->data % 2 == 0)
			{
				prev = temp;
				temp = temp->next;
			}
			else
			{
				temp = temp->next;
				prev->next = temp;
				//delete prev->next;
			}
		}
	}
	void FindMiddelElement() {
		short count = 0; Node* temp = Head; Node* prev = Head;
		if (Head == nullptr) return;
		while (temp != nullptr)
		{
			temp = temp->next;
			count++;
		}
		count /= 2;
		for (int i = 0; i <= count; i++)
		{
			if (i < count)
			{
				prev = prev->next;
			}
			else if (i == count)
			{
				//prev->next = nullptr;
				cout << prev->data << endl;
			}
		}
	}
	void SumOddEven() {
		short SumOdd = 0, SumEven = 0; Node* temp = Head;
		if (Head == nullptr)return;
		while (temp != nullptr)
		{
			if (temp->data % 2 == 0) {
				SumEven += temp->data;
			}
			else if (temp->data % 2 != 0) {
				SumOdd += temp->data;
			}
			temp = temp->next;
		}
		cout << " Even Sum = " << SumEven << endl;
		cout << " Odd Sum = " << SumOdd << endl;
	}
	void SwapNodes(short key1 , short key2) {
		Node* prev = Head;
		Node* curr = Head->next;
		Node* temp = Head;
		if (Head = nullptr) return;
		if ((prev->data == key1) && (curr->data == key2)) {
			prev->next = prev->next->next;
			curr->next = Head;
			exit(0);
		}
		else {
			prev = prev->next;
			curr = curr->next;
		}
		while (prev != nullptr)
		{
			if ((prev->data == key1) && (curr->data == key2)) {
				temp = prev->next;
				prev = curr;
				break;
			}
			else {
				prev = prev->next;
				curr = curr->next;
			}
			
		}
		Node* node = Head;
		while (node != nullptr)
		{
			cout << node->data << " ";
			node = node->next;
		}cout << endl;
	}
	void move() {
		Node* temp1 = Head;
		Node* temp2 = Head;		Node *pr = Head;
		while (temp1 != nullptr)
		{

			if (temp1->next == nullptr) { cout << temp1->data << " "; break; }// temp2 = temp1;
			else temp1 = temp1->next;
		}

		/*while (temp2!=nullptr)
		{

			pr = pr->next;
			cout << pr->data << " ";
		}cout << endl;
*/
	}
	void print(int n) { 
		// function to print element from end of linked list
		Node *temp = Head;
		short len = 0;
		while (temp!=nullptr)
		{
			temp = temp->next;
			len++;
		}
		if (len < n)return;
		temp = Head;
		for (int i = 1; i < len - n + 1; i++)
			temp = temp->next;

		cout << temp->data << endl;
	}
	void removeFirstElement() {
		Node* temp1 = Head;
		if (Head == nullptr) return;
		Head = Head->next;
		Node* temp2 = Head;
		delete temp1;
		while (temp2 != nullptr)
		{
			cout << temp2->data << " ";
			temp2 = temp2->next;
		}cout << endl;
	}
	void removeLastElement() {
		Node* temp1 = Head;
		Node* temp2 = Head;
		if (Head == nullptr) return;
		while (temp1 !=nullptr)
		{
			if (temp2->next->next == nullptr) {
				delete temp1->next;
			    temp2->next = nullptr;
				temp2 = Head;
				break;
			}
			else{
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
		}
		while (temp2 !=nullptr)
		{
			cout << temp2->data << " ";
			temp2 = temp2->next;
		}cout << endl;
	}
	short sumGreaterThanNextNode() {
		short sum = 0;
		Node* temp = Head;
		if (Head == nullptr) return 0;
		//9 -> 2 -> 3 -> 5 -> 4 -> 6 -> 8
		while (temp != nullptr)
		{
			if (temp->next == nullptr) {
				if (temp->data > Head->data) {
					sum += temp->data;
					break;
				}
				else
					break;
			}
			else if (temp->data > ((temp->next)->data)) {
				sum += temp->data;
				temp = temp->next;
			}
			 else
				temp = temp->next;
		}
		return sum;
	}
	short CountSpchialKey(short key) {
		short count = 0;
		Node* temp = Head;
		if (Head == nullptr) return 0;
		while (temp != nullptr)
		{
			if (temp->data == key) 
				count++;
			temp = temp->next;
			
		}
		return count;
	}
	void removeDuplicates() {
	      Node *ptr1, *ptr2, *dup;
		ptr1 = Head;

		/* Pick elements one by one */
		while (ptr1 != NULL && ptr1->next != NULL)
		{
			ptr2 = ptr1;

			/* Compare the picked element with rest
			of the elements */
			while (ptr2->next != NULL)
			{
				/* If duplicate then delete it */
				if (ptr1->data == ptr2->next->data)
				{
					/* sequence of steps is important here */
					dup = ptr2->next;
					ptr2->next = ptr2->next->next;
					delete(dup);
				}
				else /* This is tricky */
					ptr2 = ptr2->next;
			}
			ptr1 = ptr1->next;
		}
		Node* node = Head;
		while (node != nullptr)
		{
			cout << node->data << " ";
			node = node->next;
		}cout << endl;
	}
	void MoveLastElement() {
		Node* last = Head;
		Node* Seclast = NULL;
		if (Head == nullptr) return;
		while (last->next != nullptr)
		{
			Seclast = last;
			last = last->next;
		}
		Seclast->next = nullptr;
		last->next = Head;
		Head = last;
		Node* node = Head;
		while (node != nullptr)
		{
			cout << node->data << " ";
			node = node->next;
		}cout << endl;

	}
	void MiddleInHead() {
		Node* middle = Head;
		Node* temp = Head;
		Node* temp2=Head;
		short count = 0;
		if (Head == nullptr) return;
		while (temp != nullptr)
		{
			temp = temp->next;
			count++;
		}
		count /= 2;
		for (short i = 0; i <= count; i++) {
			if (i < count) {
				temp2 = middle;
				middle = middle->next;
			}
			else if(i==count) {
				temp2->next = middle->next;
				middle->next = Head;
				Head = middle;
			}
		}
		Node* node = Head;
		while (node != nullptr)
		{
			cout << node->data << " ";
			node = node->next;
		}cout << endl;
	}
	

};
// i am not studying it yet;
class DoublyLinkedList {
private:
	struct Node {
		int data;
		Node* next;
		Node* prev;

		Node() {
			next = nullptr;
			prev = nullptr;
		}
	};
	Node* head = nullptr;
public:
	void append(int val) {
		Node* newNode = new Node;
		newNode->data = val;
		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->prev = temp;
		}
	}

	void insert_at_pos(int val, int pos) {
		Node* newNode = new Node;
		newNode->data = val;
		if (head == nullptr) {//
			head = newNode;
			return;
		}//
		if (pos == 0) {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
			return;
		}

		Node* temp = head;
		for (int i = 0; i < pos && temp != nullptr; i++) {
			temp = temp->next;
		}

		if (temp == nullptr) {
			this->append(val);
			return;
		}

		newNode->prev = temp->prev;
		temp->prev->next = newNode;
		temp->prev = newNode;
		newNode->next = temp;
	}

	void remove(int val) {
		if (head == nullptr)
			return;

		Node* temp;
		temp = head;

		if (temp->data == val) {
			head = temp->next;
			if (head != nullptr)
				head->prev = nullptr;
			delete temp;
			return;
		}

		while (temp != nullptr && temp->data != val) {
			temp = temp->next;
		}

		if (temp == nullptr) {
			return;
		}
		else {
			temp->prev->next = temp->next;
			if (temp->next != nullptr)
				temp->next->prev = temp->prev;
			delete temp;
		}
	}

	void remove_at_pos(int pos) {
		if (head == nullptr)
			return;

		Node* temp = head;
		if (pos == 0) {
			head = temp->next;
			if (head)
				head->prev = nullptr;
			delete temp;
			return;
		}

		for (int i = 0; i < pos && temp != nullptr; i++)
			temp = temp->next;

		if (temp == nullptr)
			return;

		temp->prev->next = temp->next;
		if (temp->next)
			temp->next->prev = temp->prev;
		delete temp;

	}

	void display() {
		Node* temp = head;
		while (temp != nullptr) {
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << endl;

	}

	void reverse_display() {
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		//---------------------------
		while (temp != nullptr) {
			std::cout << temp->data << " ";
			temp = temp->prev;
		}
		std::cout << std::endl;

	}

	~DoublyLinkedList() {
		Node* temp = head;
		while (head != nullptr) {
			head = head->next;
			delete temp;
			temp = head;
		}
	}
};
struct CircleQueue
{
	int arr[3];
	int front = -1, rear = -1;
	bool isEmpty()
	{
		if (front == -1 && rear == -1) return true;
		return false;
	}
	void Enqueue(int val)
	{
		if ((rear + 1) % 3 == front) return;
		else if (isEmpty()) { front = rear = 0; }
		else{ rear = (rear + 1) % 3;}
		arr[rear] = val;
	}
	void Dequeue()
	{
		if (isEmpty()) return;
		else if (front == rear) { front = rear = -1; }
		else front = (front + 1) % 3;
	}
	int getFront()
	{
		if (isEmpty()) return - 1;
		return arr[front];
	}
};
class Tree {
	struct Node
	{
		short data; Node* left, *right;
	};
	Node* current, *parent;
public:
	Node * root; 
	Tree() { root = nullptr; } ~Tree() { root=current=parent=nullptr; };
	void insert(short val) {
		Node* newnode = new Node;
		newnode->data = val; newnode->left = newnode->right = nullptr;
		if (root == nullptr) {
			root = newnode;
		}
		else {
			current = root;
			parent = nullptr;
			while (current!=nullptr)
			{
				parent = current;
				if (val < parent->data) {
					current = current->left;	
				/*if (current == NULL) {
					parent->left = newnode;
					return;
				}*/
				}
				else
				{
					current = current->right;
					/*if (current == NULL) {
						parent->right = newnode;
						return;
					}*/
				}
			}
			if (newnode->data < parent->data)
			{
				parent->left = newnode;
			}
			else {
				parent->right = newnode;
			}
		}
	}
	//another method 
	void insertt(short val){
		Node* newnode = new Node;
		newnode->data = val; newnode->left = newnode->right = nullptr;
	queue<struct Node*> q;
	Node* temp = root;
	q.push(temp);
	while (!q.empty())
	{
	    temp = q.front();
		q.pop();
		if (!temp->left) {
			temp->left = newnode;
			break;
		}
		else q.push(temp->left);
		if (!temp->right) {
			temp->right = newnode;
			break;
		}
		else q.push(temp->right);

	}
}   
	
	//program to count leaf 
	unsigned int countleafnode(struct Node* pt) {
		if (pt == NULL)
			return 0;
		if (pt->left == NULL && pt->right == NULL)
			return 1;
		else
	 return countleafnode(pt->left) + countleafnode(pt->right);
	}
	unsigned int displaycountleaf() { return countleafnode(root); }
	//program to count node in tree
	int countnodeintree(Node* ptr){
		if (ptr == NULL)
			return 0;
		if (ptr->left == NULL && ptr->right == NULL)
			return 1;
		else
			return	(1 + (countnodeintree(ptr->left) + countnodeintree(ptr->right)));
	}
	int displaycountnode() { return countnodeintree(root); }
	//function to print tree in inorder form
	void displayInOrder(Node* ptrl) {
		if (ptrl == nullptr)return;
		displayInOrder(ptrl->left);
		cout << ptrl->data << " ";
		displayInOrder(ptrl->right);
	}
	void inorder() {
		displayInOrder(root);
	}
	//program to check if tree is BST or not
	bool BST(Node* temp,Node* lef,Node* righ) {
		if (temp == nullptr) return true;
		 if (lef != nullptr&&temp->data <lef->data) return false;
		 if (righ != nullptr && temp->data > righ->data) return false;
		 return BST(temp->left, lef, temp) &&
			 BST(temp->right, temp, righ);
	}
	bool printBST() { return BST(root,nullptr,nullptr); }
	void delete_tree(Node *root) {   // i am not aunderstand this 
		if (root != NULL)
		{
			delete_tree(root->left);
			delete_tree(root->right);
			delete(root);
			if (root->left != NULL)
				root->left = NULL;
			if (root->right != NULL)
				root->right = NULL;
			root = NULL;
		}
	}
	int minValue( Node* node)
	{
	 Node* current = node;

		/* loop down to find the leftmost leaf */
		while (current->left != NULL)
		{
			current = current->left;
		}
		return(current->data);
	}int findmin() {return  minValue(root); }
	int getnodeTleft(Node * root)
	{
		while (root->left != NULL)
			root = root->left;
		return root->data;
	}int x() { return getnodeTleft(root); }
	//jjljjj
	bool search(Node* ptr, int n) {
		if (ptr == nullptr)return false;
		else if (ptr->data == n)return true;
		else
			if (n > ptr->data)
				search(ptr->right, n);
			else
				search(ptr->left, n);
		
	}bool sea(int n) { return search(root, n); };

	//calculate hight of the tree 
	int hight(Node* temp) {
		short countLeft ; short countRight ;
		if (temp == nullptr )
			return -1;
				countLeft = hight(temp->left) ;
			    countRight = hight(temp->right) ;
		
		return 1+ max(countLeft, countRight);
	}
	int highte() {
		return hight(root);
	}

};

short vowel(string s) {
	short num=0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'u' || s[i] == 'o'||s[i]=='i') {
			 num++;
		}
	}
	return num;
}
vector<short> v1 = { 1,2,3,4,5,6 };
void room() {
	for (short i = 0; i < v1.size(); i++) {
		cout << " Available room " << v1[i] << endl;
	}
}
void reserve() {
	vector<short>::iterator t;
	t = v1.begin();
	short n;
	cout << " enter room of number to reserve" << endl;
	cin >> n;
	while (t != v1.end())
	{
		if (*t ==n)
		{
			t=v1.erase(t);
		}
		else
		  t++;
	}
}
void afterreserve() {
	vector<short>::iterator t;
	t = v1.begin();
	cout << "After resrvation " << endl;
	for (t; t != v1.end(); t++) {
		cout << *t<< endl;
	}
}
int Priority(char c) {
	if (c == '-' || c == '+')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '^')
		return 3;
	else
		return 0;
}
string postfix(string exp) {
	stack<char> stk;
	string output="";
	for (size_t i = 0; i < exp.length(); i++)
	{
		if (exp[i] == ' ') continue;
		if (isdigit(exp[i]) || isalpha(exp[i]))
			output += exp[i];
		else if (exp[i] == '(')
			stk.push('(');
		else if (exp[i] == ')') {
			while (stk.top() != '(')
			{
				output += stk.top();
				stk.pop();
			}
			stk.pop();
		}
		else {
			while (!stk.empty() && Priority(exp[i]) <= Priority(stk.top()))
			{
				output += stk.top();
				stk.pop();
			}
			stk.push(exp[i]);
		}
	}
	while (!stk.empty())
	{
		output += stk.top();
		stk.pop();
	}
	return output;
 }
float Mathoperation(float op1, float op2, char ch) {
	if (ch == '+')
		return op1 + op2;
	else if (ch == '/')
		return op1 / op2;
	else if (ch == '-')
		return op1 - op2;
	else if (ch == '*')
		return op1 * op2;
}
float evaluatePostfix(string exp) {
	stack<float> stk;
	float answer=0.0f;
	for (size_t i = 0; i < exp.length(); i++)
	{
		if (exp[i] == ' ') continue;
		if (isdigit(exp[i])) stk.push(exp[i] - '0');
		else {
			float op2 = stk.top();
			stk.pop();

			float op1 = stk.top();
			stk.pop();

			float result = Mathoperation(op1, op2, exp[i]);
			stk.push(result);
		}

	}
	return stk.top();
}

int main() {

	/*string infixExpression ="336*-2+";
	cout << evaluatePostfix (infixExpression) << endl;*/

	
	/*room();
	reserve();
	afterreserve();*/

	LinkedList l;
	l.Appand(1); l.Appand(2); l.Appand(3); l.Appand(4);l.Appand(5);  l.Appand(6);// l.Appand(6);   l.Appand(8);   // l.Appand('E'); 
	l.MiddleInHead();
	//l.removeFirstElement();
	//l.removeLastElement();
	
	
	
	//	cout << *(v1.end()-1) << endl;
	//string s = "mohammed";
	//cout <<" Number of lowercase vowel = "<< vowel(s) << endl;
	//double se = 4.0; double d = 4.0;
	//cout <<fixed<<setprecision(1)<<se + d <<endl;
	
     vector<int> v = { 3,6,1,5,4,2 };
	sort(v.begin(), v.end(),greater<int>());  //بتتطبع من الاكبر للاصغر
	//v.insert(v.begin() + 1, 10);
	//v.erase(find(all(v), 5));
	 //v.resize(5);
	 //v.shrink_to_fit();
	// int *pos = v.data();
	 //cout << *(pos+2) << endl;
	// v.emplace_back(20);
	/*for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i]<<" ";
	}
	cout << endl;*/
	v.~vector();
	/*vector<int> v = { 1,2,3,4,5,6 };
	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 2 == 0) {
			v.erase(v.begin() + i);
		}
		else
			cout << v[i] << endl;
	}*/
	/*for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}*/
	/*v.erase(v.begin()+1);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}*/
	// Tree
		//Tree t;
		//t.insert(15);  t.insert((int)('+')); t.insert(0);// t.insert(25); t.insert(30);  t.insert(31);

		//cout << t.highte() << endl;
		//t.inorder();
		/*//cout << t.sea(15) << endl;
		  cout << endl;
		cout << "Number Of Leafs in tree is: " << t.displaycountleaf() << endl;
		cout << "Number of Nodes in tree is: " << t.displaycountnode() << endl;
		if (t.printBST()) { cout << " Tree is BST" << endl; }
		else  {cout << "Tree is not BST" << endl;}
		t.~Tree(); */




		//LinkedList link; //int val, pos;
		//
		//for (item i = 0; i <=3 ; i++)
		//{
		//	link.Appand(i);
		//}
		//link.move();
		//link.SumOddEven();
		//link.FindMiddelElement();
		/* link.getNthNode();
		*/// link.DeleteOdd(); link.display();
		/*link.display(); cout << "Enter value to search" << endl;
		cin >> val; link.search(val);*/
		/*link.display();
		link.reverse(); link.display();*/
		/*link.Appand(1); link.Appand(2); link.Appand(3); link.Appand(4); link.Appand(5);
		link.display(); link.reverse(); link.display();*/
		/*cout << "Enter psition to remove, position must larger than zero(0)" << endl;
		cin >> pos;
		link.delete_at_position(pos-1); link.insert_at_position(100, 8);
		link.display();*/
		/*cout << "Enter value to remove from linedlist" << endl;
		cin >> val;
		link.remove(val); link.display();*/



		/*int x = 111;
		cout << ceil(log10(x)) << endl;*/


		/*stack<int> mystack;

		for (int i = 5-1; i > -1; --i) mystack.push(i);

		cout << "Popping out elements...";
		while (!mystack.empty())
		{
			cout << ' ' << mystack.top();
			mystack.pop();
		}
		cout << '\n';*/


	return 0;
}