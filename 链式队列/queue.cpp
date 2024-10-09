#include "queue.h"
#include<iostream>
using namespace std;
queue::queue()
{
	front = new queueNode;
	rear = front;
}
queue::~queue()
{
	queueNode* temp = front;
	while (temp != rear)
	{
		temp = front->next;
		delete front;
		front = temp;
	}
	delete rear;
}
void queue::push(int data)
{
	queueNode* temp = new queueNode;
	temp->data = data;
	temp->next = NULL;
	rear->next = temp;
	rear = temp;
}
int queue::pop()
{
	if (is_empty())
	{
		cout << "队列为空  " << endl;
		return 0;
	}
	queueNode* temp = front->next;
	int data = temp->data;
	front->next = temp->next;
	if (rear == temp)
		rear = front;
	delete temp;
	cout << data << "  ";
	return data;
}
int queue::get_front()
{
	if (is_empty())
	{
		cout << "队列为空  ";
		return 0;
	}
	return front->next->data;
}
int queue::get_rear()
{
	if (is_empty())
	{
		cout << "队列为空  ";
		return 0;
	}
	return rear->data;
}
bool queue::is_empty()
{
	return front == rear;
}
void queue::clear()
{
	if (is_empty())
	{
		cout << "队列已经为空  " << endl;
		return;
	}
	queueNode* temp = front->next;
	while (temp != rear)
	{
		queueNode* t = temp->next;
		delete[] temp;
		temp = t;
	}
	delete temp;
	rear = front;
}
int queue::size()
{
	if (is_empty())
		return 0;
	int count = 1;
	queueNode* temp = front->next;
	while (temp != rear)
	{
		count++;
		temp = temp->next;
	}
	return count;
}
