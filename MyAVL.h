#pragma once
#include "MyBST.h"

class MyAVL
{
public:
	MyAVL();
	~MyAVL();
	TreeNode* root;
	void insertNode(int val);
	TreeNode* searchNode(int val);
	void deleteNode(int val);

	void preOrder();
	void inOrder();
	void postOrder();
private:
	TreeNode* insertNode(int val, TreeNode* T);
	TreeNode* searchNode(int val, TreeNode* T);
	TreeNode* deleteNode(TreeNode* T, TreeNode*  Td);
	void preOrder(TreeNode* T);
	void inOrder(TreeNode* T);
	void postOrder(TreeNode* T);

	TreeNode* llRotate(TreeNode* T);
	TreeNode* rrRotate(TreeNode* T);
	TreeNode* lrRotate(TreeNode* T);
	TreeNode* rlRotate(TreeNode* T);

	int height(TreeNode* T);

	void freeMemory(TreeNode* &T);
};

