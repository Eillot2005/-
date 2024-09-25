#include "List.h"
#include<iostream>
using namespace std;

List::List()
{
	head = new node;
	head->next = NULL;
	head->data = 0;
}
List::~List()
{
	node* pp=new node;
	for (node* p = head; p != NULL;)
	{
		pp = p; 
		p = p->next;
		delete pp;
	}
}
void List::push(int a)
{
	node* p = new node;
	p->data = a;
	p->next = head->next;
	head->next = p;
}
void List::show()
{
	for (node* p = head->next; p != NULL; p = p->next)
	{
		cout << p->data << " ";
	}
	cout << endl;
}
int List::getlength()
{
	int len = 0;
	for (node* p = head->next; p != NULL; p = p->next)
	{
		len++;
	}
	return len;
}
bool List::empty()
{
	if (head->next == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void List::insert(int a, int b)
{
	node* p=new node;
	p->data = b;
	node* pp = head;
	for (int i = 1; i < a; i++, pp = pp->next)
	{
		if (pp == NULL)
		{
			cout << "error" << endl;
			return;
		}
	}
	p->next = pp->next;
	pp->next = p;
}
void List::sort()
{
	for (node* p = head->next; p->next != NULL; p = p->next)
	{
		for (node* pp = head->next; pp->next != NULL; pp = pp->next)
		{
			if (pp->data > pp->next->data)
			{
				swap(pp->data, pp->next->data);
			}
		}
	}
}
void List::swapPosition(int a, int b)
{
	node* p = head->next;
	node* pp = head->next;
	for (; p->data != a; p = p->next)
	{
		if (p->next == NULL)
		{
			cout << "error" << endl;
			return;
		}
	}
	for (; pp->data != b; pp = pp->next)
	{
		if (pp->next == NULL)
		{
			cout << "error" << endl;
			return;
		}
	}
	swap(p->data, pp->data);
}
void List::del(int a)
{
	node* p = head;
	for (; p->next != NULL; p = p->next)
	{
		if (p->next->data == a)
		{
			p->next = p->next->next;
			break;
		}
	}
}
void List::delall(int a)
{
	node* p = head;
	for (; p->next != NULL; )
	{
		if (p->next->data == a)
		{
			p->next = p->next->next;
		}
		else
		{
			p = p->next;
		}
	}
}

void List::pushFront(int a)
{
	node* p = new node;
	p->data = a;
	p->next = head->next;
	head->next = p;
}

void List::reverse()
{
	node *p = head->next;
	node* pp = head->next->next;
	while (pp != NULL)
	{
		node* ppp = pp->next;
		pp->next = p;
		p = pp;
		pp = ppp;
	}
	head->next->next = NULL;
	head->next = p;
}

void List::unique()
{
	
	for (node* p = head->next; p->next != NULL; p = p->next)
	{
		for (node* pp = p; pp->next != NULL; )
		{
			if (p->data == pp->next->data)
			{
				pp->next = pp->next->next;
				continue;
			}
			pp = pp->next;
		}
	}
}