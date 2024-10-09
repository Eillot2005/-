#pragma once
struct queueNode
{
	int data;
	queueNode* next;
};
class queue
{
private:
	queueNode* front;
	queueNode* rear;
public:
	queue();
	~queue();
	void push(int data);
	int pop();
	int get_front();
	int get_rear();
	bool is_empty();
	void clear();
	int size();
};

