#include "MyBST.h"


MyBST::MyBST()
{
}


MyBST::~MyBST()
{
	freeMemory(root);
}

void MyBST::insertNode(int val, TreeNode* T)
{
	if (T->val >= val)
		T->leftChild == NULL ? T->leftChild = new TreeNode(val) : insertNode(val, T->leftChild);
	else
		T->rightChild == NULL ? T->rightChild = new TreeNode(val) : insertNode(val, T->rightChild);
}

void MyBST::insertNode(int val)
{
	if (root == NULL)
	{
		root = new TreeNode(val);
	}
	else{
		insertNode(val, root);
	}

}

TreeNode* MyBST::searchNode(int val, TreeNode* T)
{
	if (T->val == val)
		return T;
	else if (T->val > val)
		return T->leftChild == NULL ? NULL : searchNode(val, T->leftChild);
	else if (T->val < val)
		return T->rightChild == NULL ? NULL : searchNode(val, T->rightChild);
}

TreeNode* MyBST::searchNode(int val)
{
	if (root == NULL)
		return NULL;
	else
		return searchNode(val, root);
}

void MyBST::deleteNode(int val)
{
	TreeNode* node = root;
	TreeNode* pnode = NULL;
	if (root == NULL)
		return;
	while (node->val != val){
		pnode = node;
		if (node->val > val && node->leftChild != NULL)
			node = node->leftChild;
		else if (node->val < val && node->rightChild != NULL)
			node = node->rightChild;
		else
			return;
	}
	if (node->leftChild == NULL || node->rightChild == NULL)
	{
		TreeNode* tmpNode = node->leftChild == NULL ? node->rightChild : node->leftChild;
		if (pnode->leftChild == node)
			pnode->leftChild = tmpNode;
		else
			pnode->rightChild = tmpNode;
		delete node;
		return;
	}
	TreeNode* pleftRightNode = node;
	TreeNode* leftRightNode = node->leftChild;
	while (leftRightNode->rightChild != NULL)
	{
		pleftRightNode = leftRightNode;
		leftRightNode = leftRightNode->rightChild;
	}
	node->val = leftRightNode->val;
	if (pleftRightNode->rightChild == leftRightNode)
		pleftRightNode->rightChild = NULL;
	else
		pleftRightNode->leftChild = NULL;
	delete leftRightNode;
	return;
}

void MyBST::inOrder(TreeNode* T)
{
	if (T == NULL)
		return;
	inOrder(T->leftChild);
	cout << T->val;
	cout << " ";
	inOrder(T->rightChild);
}
void MyBST::inOrder()
{
	inOrder(root);
}

void MyBST::freeMemory(TreeNode* &T)
{
	if (T == NULL)
		return;
	else
	{
		freeMemory(T->leftChild);
		freeMemory(T->rightChild);
	}
	delete T;
	T = NULL;
}