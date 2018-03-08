// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>    

using namespace std;

typedef int TelemType;

typedef struct BinaryTreeNode
{
	TelemType data;
	struct BinaryTreeNode *Left;
	struct BinaryTreeNode *Right;
}Node;


Node* createBinaryTree()
{
	Node *p;
	TelemType ch;
	cin >> ch;
	if (ch == 0)
	{
		p = NULL;
	}
	else
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = ch;
		p->Left = createBinaryTree();
		p->Right = createBinaryTree();
	}
	return p;
}

void preOrderTraverse(Node* root)
{
	if (root)
	{
		cout << root->data << ' ';
		preOrderTraverse(root->Left);
		preOrderTraverse(root->Right);
	}
}

void inOrderTraverse(Node* root)
{
	if (root)
	{
		inOrderTraverse(root->Left);
		cout << root->data << ' ';
		inOrderTraverse(root->Right);
	}
}

void lastOrderTraverse(Node* root)
{
	if (root)
	{
		lastOrderTraverse(root->Left);
		lastOrderTraverse(root->Right);
		cout << root->data << ' ';
	}
}

int Nodenum(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + Nodenum(root->Left) + Nodenum(root->Right);

	}
}

int DepthOfTree(Node* root)
{
	if (root)
	{
		return DepthOfTree(root->Left)>DepthOfTree(root->Right) ? DepthOfTree(root->Left) + 1 : DepthOfTree(root->Right) + 1;
	}
	if (root == NULL)
	{
		return 0;
	}
}

int Leafnum(Node* root)
{
	if (!root)
	{
		return 0;
	}
	else if ((root->Left == NULL) && (root->Right == NULL))
	{
		return 1;
	}
	else
	{
		return  (Leafnum(root->Left) + Leafnum(root->Right));
	}
}


int main()
{
	Node *root = NULL;
	root = createBinaryTree();
	printf("build success");
	cout << endl;

	cout << "Node Number  " << Nodenum(root) << endl;

	cout << "depth " << DepthOfTree(root) << endl;

	cout << "leaf number" << Leafnum(root) << endl;

	cout << "pre order: " << endl;
	preOrderTraverse(root);
	cout << endl;

	cout << "in order: " << endl;
	inOrderTraverse(root);
	cout << endl;

	cout << "last order: " << endl;
	lastOrderTraverse(root);
	cout << endl;

	return 0;
}
