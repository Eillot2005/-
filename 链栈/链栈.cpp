#include<iostream>
#include"stack.h"
using namespace std;
int main()
{
	stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.show();
	s.popall();
	s.show();
}