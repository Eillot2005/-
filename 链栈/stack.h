#pragma once
struct node
{
	int data;
	node* next;
};
class stack
{
private:
	node* head;
public:
	stack();
	~stack();
	void push(int x);
	int pop();
	int getsize();
	bool isempty();
	void show();
	void popall();
};



