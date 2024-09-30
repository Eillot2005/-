#include<iostream>
#include"queue.h"
using namespace std;
int main()
{
	queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.pop();
}
