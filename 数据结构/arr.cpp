#include "arr.h"
#include<iostream>
using namespace std;

arr::arr(sqlist* a)
{
	array.element = new int[100];
	for (int i = 0; i < a->length; i++)
	{
		array.element[i] = a->element[i];
	}
	array.length = a->length;
	cout << "拷贝构造函数" << endl;
}
arr::arr()
{
	array.element = new int[100];
	array.length = 0;
	cout << "构造函数" << endl;
}
arr::arr(int a, int b)
{
	array.element = new int[100];
	for (int i = 0; i < a; i++)
	{
		array.element[i] = b;
	}
	array.length = a;
	cout << "构造函数" << endl;
}
bool arr::empty()
{
	if (this->array.length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int arr::getlength()
{
	cout << "长度为：";
	return this->array.length;
}
void arr::show()
{
	for (int i = 0; i < array.length; i++)
	{
		cout << array.element[i] << " ";
	}
	cout << endl;
	cout << "数组大小为：" << sizeof(array.element) << endl;
}
void arr::insert(int a, int b)
{
	if (a<1 || a>array.length)
	{
		cout << "error" << endl;
	}
	else
	{
		for (int i = array.length; i >= a; i--)
		{
			this->array.element[i] = array.element[i - 1];
		}
		this->array.element[a - 1] = b;
		this->array.length++;
	}
}
void arr::push(int a)
{
	this->array.element[array.length] = a;
	this->array.length++;
}
void arr::sort()
{
	for (int i = 0; i < array.length; i++)
	{
		for (int j = 0; j < array.length - i - 1; j++)
		{
			if (array.element[j] > array.element[j + 1])
			{
				int temp = array.element[j];
				array.element[j] = array.element[j + 1];
				array.element[j + 1] = temp;
			}
		}
	}
}
arr::~arr()
{
	delete[] array.element;
	cout << "析构函数" << endl;
}
void arr::del(int a)
{
	for (int i = a; i < array.length; i++)
	{
		array.element[i - 1] = array.element[i];
	}
	array.element[array.length - 1] = 0;
	array.length--;
}
void arr::delall(int a)
{
	for (int i = 0; i < array.length; i++)
	{
		if (array.element[i] == a)
		{
			for (int j = i; j < array.length; j++)
			{
				array.element[j] = array.element[j + 1];
			}
			array.length--;
			i--;
		}
	}
}
sqlist* arr::getarray()
{
	return &array;
}



