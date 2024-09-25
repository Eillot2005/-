#pragma once
class stack
{
private:
	int* data;
	int top;
	int size;
public:
	stack(int size = 10);
	stack(const stack& s);
	~stack();
	void push(int x);
	int pop();
	void popall();
	int gettop();
	int getsize();
	bool isempty();
	bool isfull();
	void show();
	void extend();
	int getcapacity();
};

