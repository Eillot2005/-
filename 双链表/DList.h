#pragma once
struct node
{
	int data;
	node* next;
	node* pre;
};
class DList
{
public:
	DList();
	~DList();
	void insert(int x,int y);
	void show();
	int getsize();
	bool isempty();
	void del(int x);
	void delall();
	void delall(int x);
	void reverse();
	void sort();
private:
	node* head;
};

