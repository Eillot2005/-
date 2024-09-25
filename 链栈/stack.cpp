#include "stack.h"
#include<iostream>
using namespace std;

stack::stack()
{
	head = new node;
	head->next = NULL;
}
stack::~stack()
{
	node* p = head;
	while (p)
	{
		node* q = p->next;
		delete p;
		p = q;
	}
}
void stack::push(int x)
{
	node* p = new node;
	p->data = x;
	p->next = head->next;
	head->next = p;
}
int stack::pop()
{
	if (isempty())
	{
		cout << "栈为空" << endl;
		return -1;
	}
	node* p = head->next;
	int x = p->data;
	head->next = p->next;
	delete p;
	cout << x << " ";
	return x;
}
int stack::getsize()
{
	int count = 0;
	node* p = head->next;
	while (p)
	{
		count++;
		p = p->next;
	}
	cout << "栈中元素个数为：" << count << endl;
	return count;
}
bool stack::isempty()
{
	return head->next == NULL;
}
void stack::show()
{
	if (isempty())
	{
		cout << "栈为空" << endl;
		return;
	}
	node* p = head->next;
	while (p!=NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void stack::popall()
{
	if (isempty())
	{
		cout << "栈为空" << endl;
		return;
	}
	while (!isempty())
	{
		pop();
	}
	cout << endl;
}
