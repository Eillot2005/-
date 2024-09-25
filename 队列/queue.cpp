#include "queue.h"
#include<iostream>
using namespace std;
queue::queue(int size)
{
	q = new sqqueue;
	q->base = new int[size];
	q->front = -1;
	q->rear = -1;
	capacity = size;
}
queue::~queue()
{
	delete[] q->base;
	delete[] q;
}
void queue::push(int data)
{
	if (is_full())
	{
		cout << "队列已满  ";
		return;
	}
	q->rear = (q->rear + 1) % capacity;
	q->base[q->rear] = data;
}
int queue::pop()
{
	if (is_empty())
	{
		cout << "队列为空  ";
		return 0;
	}
	q->front = (q->front + 1) % capacity;
	int temp = q->base[q->front];
	return temp;
}
int queue::get_front()
{
	if (is_empty())
	{
		cout << "队列为空   ";
		return 0;
	}
	return q->base[q->front];
}
int queue::get_rear()
{
	if (is_empty())
	{
		cout << "队列为空" << endl;
		return 0;
	}
	return q->base[q->rear];
}
bool queue::is_empty()
{
	return q->front == q->rear;
}
bool queue::is_full()
{
	return (q->rear + 1) % capacity == q->front;
}
int queue::get_size()
{
	return (q->rear - q->front + capacity + 1 ) % capacity;
}
void queue::clear()
{
	q->front = q->rear = -1;
}