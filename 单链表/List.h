#pragma once

struct node
{
	int data;
	node* next;
};
class List
{
private:
	node* head;
public:
	List();
	~List();
	void insert(int a, int b);
	void push(int a);
	void sort();
	void del(int a);
	void delall(int a);
	void show();
	int getlength();
	bool empty();
	void swapPosition(int a, int b);
	void pushFront(int a);
	void reverse();
	void unique();
};

