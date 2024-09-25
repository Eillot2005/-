#include<iostream>
#include"arr.h"
using namespace std;
int main()
{
	arr a(5, 1);
	a.show();
	cout << a.getlength() << endl;
	a.insert(2, 6);
	a.show();
	a.push(9);
	a.show();
	cout << a.getlength() << endl;
	a.sort();
	a.show();
	a.del(2);
	a.show();
	a.delall(1);
	a.show();

	arr b(a.getarray());
	b.show();
}