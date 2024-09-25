#include "DList.h"
#include<iostream>
using namespace std;

DList::DList()
{
	head = new node;
	head->next = NULL;
	head->pre = NULL;
}
DList::~DList()
{
	node* p = head;
	while (p)
	{
		node* q = p->next;
		delete p;
		p = q;
	}
}
void DList::insert(int x, int y)
{
	node* p = head;
	p->data = x;
	node* q = new node;
	q = head;
	for (int i = 0; i < y; i++)
	{
		q = q->next;
	}
	p->next = q->next;
	q->next = p;
	p->pre = q;
	p->next->pre = p;
}
void DList::show()
{
	node* p = head->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int DList::getsize()
{
	int count = 0;
	node* p = head->next;
	while (p)
	{
		count++;
		p = p->next;
	}
	cout << "链表中元素个数为：" << count << endl;
	return count;
}
bool DList::isempty()
{
	return head->next == NULL;
}
void DList::del(int x)
{
	node* p = head->next;
	while (p->data != x)
	{
		p = p->next;
	}
	p->pre->next = p->next;
	p->next->pre = p->pre;
	delete p;
}
void DList::delall()
{
	node* p = head->next;
	while (p)
	{
		node* q = p->next;
		delete p;
		p = q;
	}
	head->next = NULL;
}
void DList::delall(int x)
{
	node* p = head->next;
	while (p)
	{
		if (p->data == x)
		{
			p->pre->next = p->next;
			p->next->pre = p->pre;
			delete p;
		}
		p = p->next;
	}
}
void DList::reverse()
{
	node* p = head->next;
	node* q = new node;
	while (p)
	{
		q = p->next;
		p->next = p->pre;
		p->pre = q;
		p = q;
	}
	head->next = p;
}