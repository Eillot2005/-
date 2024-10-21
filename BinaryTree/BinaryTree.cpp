#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void insert(int data);
	void remove(int data);
	void pre_order(Node* n);
	void in_order(Node* n);
	void post_order(Node* n);
	void level_order(Node* n, int x, int h);
	void level_order(Node* n, int x, int h, int a[],int &i);
	Node* getroot();
	int GetHeight();
	void ShowStruct();
private:
	Node* root;
};

BinaryTree::BinaryTree()
{
	root = new Node;
	root->left = NULL;
	root->right = NULL;
	root->data = NULL;
}
BinaryTree::~BinaryTree()
{
	Node* temp = root;
	while (temp != NULL)
	{
		if (temp->left != NULL)
		{
			temp = temp->left;
		}
		else if (temp->right != NULL)
		{
			temp = temp->right;
		}
		else
		{
			Node* temp2 = temp;
			temp = temp->right;
			delete temp2;
		}
	}
}
void BinaryTree::insert(int data)
{
	if (root->data == NULL)
	{
		root->data = data;
		return;
	}
	Node* temp = root;
	while (temp != NULL)
	{
		if (temp->data > data)
		{
			if (temp->left != NULL)
			{
				temp = temp->left;
			}
			else
			{
				Node* temp2 = new Node;
				temp2->data = data;
				temp2->left = NULL;
				temp2->right = NULL;
				temp->left = temp2;
				break;
			}
		}
		else
		{
			if (temp->right != NULL)
			{
				temp = temp->right;
			}
			else
			{
				Node* temp2 = new Node;
				temp2->data = data;
				temp2->left = NULL;
				temp2->right = NULL;
				temp->right = temp2;
				break;
			}
		}
	}
}
void BinaryTree::pre_order(Node* n)
{
	if (n == NULL)
		return;
	cout << n->data << " ";
	pre_order(n->left);
	pre_order(n->right);
}
void BinaryTree::in_order(Node* n)
{
	if (n == NULL)
		return;
	in_order(n->left);
	cout << n->data << " ";
	in_order(n->right);
}
void BinaryTree::post_order(Node* n)
{
	if (n == NULL)
		return;
	post_order(n->left);
	post_order(n->right);
	cout << n->data << " ";
}
Node* BinaryTree::getroot()
{
	return root;
}
int BinaryTree::GetHeight()
{
	Node* temp = root;
	int h = 1;
	while (temp != NULL)
	{
		if (temp->left != NULL)
		{
			temp = temp->left;
			h++;
		}
		else if (temp->right != NULL)
		{
			temp = temp->right;
			h++;
		}
		else
		{
			break;
		}
	}
	return h;
}
void BinaryTree::level_order(Node* n, int x, int h)//此函数功能为:按层次遍历二叉树,其中x为当前层数,h为树的高度
{
	if (n == NULL)
		return;
	else
	{
		cout << n->data << " ";
		if (x < h)
		{
			level_order(n->left, x + 1, h);
			level_order(n->right, x + 1, h);
		}
	}
}

void BinaryTree::level_order(Node* n, int x, int h,int *a,int &i)
{
	if (n == NULL)
		return;
	else
	{
		a[i++] = n->data;
		if (x < h)
		{
			level_order(n->left, x + 1, h, a,i);
			level_order(n->right, x + 1, h, a,i);
		}
	}
}
void BinaryTree::ShowStruct()
{
	int h = GetHeight();
	int a[40] = {0};
	int j = 0;
	level_order(root, 1, h, a,j);
	//用树状图结构输出
	/*
	int k = 0;
	for (int i = 1; i <= h; i++)//i为层数
	{
		for (int j = 0; j < (h-i); j++)
		{
			cout << " ";
		}
		for (int j = 0; j < pow(2, i - 1); j++)//j为每层的节点数
		{
			if (a[k] != NULL)
			{
				cout << a[k++];
			}
			else//如果节点为空,则输出空格
			{
				cout << " ";
			}
			for (int m = 0; m < pow(2, h - i); m++)//m为每个节点之间的间隔
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	*/
	int k = 0;
	for (int i = 1; i <= h; i++) // i 表示当前层数
	{
		int leading_spaces = pow(2, h - i) - 1; // 每层行首的空格数
		int between_spaces = pow(2, h - i + 1) - 1; // 每个节点之间的空格数

		// 输出行首的空格
		for (int j = 0; j < leading_spaces; j++) {
			cout << " ";
		}

		// 输出每层的节点
		for (int j = 0; j < pow(2, i - 1); j++) // 每层的节点数
		{
			if (a[k] != 0) {
				cout << a[k++];
			}
			else {
				cout << "_"; // 占位符代替空节点
				k++;
			}

			// 输出节点之间的空格
			for (int m = 0; m < between_spaces; m++) {
				cout << " ";
			}
		}
		cout << endl; // 换行输出下一层
	}
}
//0 1 3 7 15
//1,2,4,8,16

int main()
{
	BinaryTree bt;
	bt.insert(5);
	bt.insert(3);
	bt.insert(7);
	bt.insert(2);
	bt.insert(4);
	bt.insert(6);
	bt.insert(8);
	bt.insert(1);
	bt.insert(9);
	bt.insert(2);
	bt.insert(4);
	bt.insert(2);
	bt.insert(4);
	bt.pre_order(bt.getroot());
	cout << endl;
	bt.in_order(bt.getroot());
	cout << endl;
	bt.post_order(bt.getroot());
	cout << endl;
	cout << bt.GetHeight() << endl;
	bt.level_order(bt.getroot(), 1, bt.GetHeight());
	cout << endl;
	bt.ShowStruct();
}