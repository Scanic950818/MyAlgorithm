#include "MyAVL.h"
#include <algorithm>

using std::max;


MyAVL::MyAVL()
{
}


MyAVL::~MyAVL()
{
}

int MyAVL::height(TreeNode* T)
{
	if (T == NULL)
		return -1;
	else
		return T->height;
}
TreeNode* MyAVL::llRotate(TreeNode* T)
{
	TreeNode* tmpNode = T->leftChild;
	T->leftChild = tmpNode->rightChild;
	tmpNode->rightChild = T;
	tmpNode->height = max(height(tmpNode->leftChild), height(tmpNode->rightChild)) + 1;
	T->height = max(height(T->leftChild), height(T->rightChild)) + 1;
	return tmpNode;
}

TreeNode* MyAVL::rrRotate(TreeNode* T)
{
	TreeNode* tmpNode = T->rightChild;
	T->rightChild = tmpNode->leftChild;
	tmpNode->leftChild = T;
	tmpNode->height = max(height(tmpNode->leftChild), height(tmpNode->rightChild)) + 1;
	T->height = max(height(T->leftChild), height(T->rightChild)) + 1;
	return tmpNode;
}

TreeNode* MyAVL::lrRotate(TreeNode* T)
{
	rrRotate(T->leftChild);
	return llRotate(T);
}

TreeNode* MyAVL::rlRotate(TreeNode* T)
{
	llRotate(T->rightChild);
	return rrRotate(T);
}


TreeNode* MyAVL::insertNode(int val, TreeNode* T)
{
	if (T == NULL)
		return new TreeNode(val);
	if (T->val >= val)
	{
		T->leftChild = insertNode(val, T->leftChild);
		if (height(T->leftChild) - height(T->rightChild) == 2)
		{
			if (height(T->leftChild->leftChild) > height(T->leftChild->rightChild))
				return llRotate(T);
			else
				return lrRotate(T);
		}
	}
	else{
		T->rightChild = insertNode(val, T->rightChild);
		if (height(T->rightChild) - height(T->leftChild) == 2)
		{
			if (height(T->rightChild->rightChild) > height(T->rightChild->leftChild))
				return rrRotate(T);
			else
				return rlRotate(T);
		}
	}
	T->height = max(height(T->leftChild), height(T->rightChild)) + 1;
	return T;
}

void MyAVL::insertNode(int val)
{
	root = insertNode(val, root);
}

TreeNode* MyAVL::searchNode(int val, TreeNode* T)
{
	if (T->val == val)
		return T;
	else if (T->val > val)
		return T->leftChild == NULL ? NULL : searchNode(val, T->leftChild);
	else if (T->val < val)
		return T->rightChild == NULL ? NULL : searchNode(val, T->rightChild);
}

TreeNode* MyAVL::searchNode(int val)
{
	if (root == NULL)
		return NULL;
	else
		return searchNode(val, root);
}
TreeNode* minimus(TreeNode* node)
{
	    if (node->leftChild == NULL)
		         return node;
		return minimus(node->leftChild);
 }

/*在AVL树中查找最大值结点并返回*/
TreeNode* maximus(TreeNode* node)
 {
     if (node->rightChild == NULL)
		         return node;
	     return maximus(node->rightChild);
 }

TreeNode* MyAVL::deleteNode(TreeNode* T, TreeNode*  Td)
{
	if (T == NULL)
		return NULL;
	if (Td->val > T->val)
	{
		T->rightChild = deleteNode(T->rightChild, Td);
		T->height = max(height(T->leftChild), height(T->rightChild)) + 1;
		if (height(T->leftChild) - height(T->rightChild) == 2)
		{
			if (height(T->leftChild->leftChild) > height(T->leftChild->rightChild))
				T = llRotate(T);
			else
				T = lrRotate(T);
		}
	}
	else if (Td->val < T->val)
	{
		T->leftChild = deleteNode(T->leftChild, Td);
		T->height = max(height(T->leftChild), height(T->rightChild)) + 1;
		if (height(T->rightChild) - height(T->leftChild) == 2)
		{
			if (height(T->rightChild->rightChild) > height(T->rightChild->leftChild))
				T = rrRotate(T);
			else
				T = rlRotate(T);
		}
	}
	else{
		if (T->leftChild != NULL && T->rightChild != NULL)
		{
			if (height(T->leftChild) > height(T->rightChild))
			{
				TreeNode* tmp = maximus(T->leftChild);
				T->val = tmp->val;
				T->leftChild = deleteNode(T->leftChild, tmp);
			}
			else{
				TreeNode* tmp = maximus(T->rightChild);
				T->val = tmp->val;
				T->rightChild = deleteNode(T->rightChild, tmp);
			}
		}
		else{
			TreeNode* tmp = T->leftChild != NULL ? T->leftChild : T->rightChild;
			delete T;
			return tmp;
		}
	}
	T->height = max(height(T->leftChild), height(T->rightChild)) + 1;
	return T;
}
void MyAVL::deleteNode(int val)
{
	TreeNode* tmp = searchNode(val);
	if (tmp != NULL)
		root = deleteNode(root, tmp);
}

void MyAVL::inOrder(TreeNode* T)
{
	if (T == NULL)
		return;
	inOrder(T->leftChild);
	cout << T->val;
	cout << " ";
	inOrder(T->rightChild);
}
void MyAVL::inOrder()
{
	inOrder(root);
}

void MyAVL::freeMemory(TreeNode* &T)
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