#include<iostream>
#include"List.h"
using namespace std;
int main()
{
	List a;
	srand(time(0));
	for (int i = 1; i < 20; i++)
	{
		a.push(rand()%10);
	}
	a.show();

	//插入
	a.insert(3, 99);
	a.show();

	//删除
	a.del(3);
	a.show();

	//删除所有
	a.delall(6);
	a.show();

	//交换位置
	a.swapPosition(2,5);
	a.show();

	//排序
	a.sort();
	a.show();

	//头插
	a.pushFront(5);
	a.show();

	//反转
	a.reverse();
	a.show();

	//去重
	a.unique();
	a.show();

	cout << a.getlength() << endl;
}
