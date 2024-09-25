#pragma once

struct sqlist
{
	int* element;
	int length;
};

class arr
{
private:
	sqlist array;
public:
	arr(sqlist* a);
	arr();
	arr(int a, int b);
	~arr();
	bool empty();
	int getlength();
	void show();
	void insert(int a, int b);
	void push(int a);
	void sort();
	void del(int a);
	void delall(int a);
	sqlist* getarray();
};