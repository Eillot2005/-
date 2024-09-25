#include<iostream>
#include"DList.h"
using namespace std;
int main()
{
	DList a;
	a.insert(1, 0);
	a.insert(2, 1);
	a.insert(3, 2);
	a.insert(4, 3);
	a.insert(5, 4);
	a.show();
	a.getsize();
	a.del(2);
	a.show();
	a.getsize();
	a.delall(4);
	a.show();
	a.getsize();
	a.reverse();
	a.show();
	a.sort();
	a.show();
	return 0;
}
