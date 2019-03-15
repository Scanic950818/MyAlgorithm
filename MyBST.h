#pragma once
#include "iostream"
using std::cout;

struct TreeNode
{
	int val;
	TreeNode* leftChild;
	TreeNode* rightChild;

	TreeNode(int Value)
	{
		val = Value;
		leftChild = NULL;
		rightChild = NULL;
	}
};

class MyBST
{
public:
	MyBST();
	~MyBST();
	TreeNode* root;

	void insertNode(int val);
	TreeNode* searchNode(int val);
	void deleteNode(int val);

	void preOrder();
	void inOrder();
	void postOrder();
private:
	void insertNode(int val, TreeNode* T);
	TreeNode* searchNode(int val, TreeNode* T);
	void preOrder(TreeNode* T);
	void inOrder(TreeNode* T);
	void postOrder(TreeNode* T);

	void freeMemory(TreeNode* &T);
	


};

