#pragma once
struct sqqueue
{
	int* base;
	int front;//队头指针
	int rear;//队尾指针
};
class queue
{
public:
	queue(int size);
	~queue();
	void push(int data);
	int pop();
	int get_front();
	int get_rear();
	bool is_empty();
	bool is_full();
	int get_size();
	void clear();

private:
	sqqueue* q;
	int capacity;
};

