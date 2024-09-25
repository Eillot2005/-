#include "stack.h"
#include<iostream>
using namespace std;

stack::stack(int size)
{
	this->size = size;
	data = new int[size];
	top = -1;
}
stack::stack(const stack& s)
{
	data = new int[s.size];
	top = s.top;
	size = s.size;
	for (int i = 0; i < top; i++)
		data[i] = s.data[i];
}
stack::~stack()
{
	delete[] data;
}
void stack::push(int x)
{
	if (getsize() >= getcapacity() - 2)
		extend();
	data[++top] = x;
}
int stack::pop()
{
	return data[top--];
}
int stack::gettop()
{
	return data[top];

}
int stack::getsize()
{
	return top+1;
}
bool stack::isempty()
{
	return top == -1;
}
bool stack::isfull()
{
	return top == size - 1;
}
void stack::show()
{
	cout << "从栈底到栈顶：";
	for (int i = 0; i <= top; i++)
		cout << data[i] << " ";
	cout << endl;
}
void stack::extend()
{
	int* temp = new int[size * 2];
	for (int i = 0; i < this->getsize(); i++)
	{
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
	size *= 2;
}
int stack::getcapacity()
{
	return size;
}
void stack::popall()
{
	while (top != -1)
	{
		cout << data[top--] << " ";
	}
	cout << "已清空   " << "当前容量为：" << this->getcapacity() << endl;
}