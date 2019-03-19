#include "MyRBT.h"
#include "queue"
#include "stack"
#include "utility"
#include "map"

using std::cout;
using std::queue;
using std::stack;
using std::pair;
using std::make_pair;


MyRBT::MyRBT()
{
}


MyRBT::~MyRBT()
{
}

void MyRBT::traverse()
{
	queue<RBTNode*> q;
	if (root != NULL)
		q.push(root);
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++){
			RBTNode* tmp = q.front();
			q.pop();
			cout << tmp->val << "-";
			if (tmp->color == RED)
				cout << "RED ";
			else
				cout << "BLACK ";
			
			if (tmp->parent)
				cout<< "(parent:" << " " << tmp->parent->val << ") ";
			if (tmp->leftChild != NULL)
				q.push(tmp->leftChild);
			if (tmp->rightChild != NULL)
				q.push(tmp->rightChild);
		}
		cout <<"\n";
	}
	cout << "root:" << root->val;
}

void MyRBT::preorder()
{
	if (root == NULL)
		return;
	stack<RBTNode*> s;
	s.push(root);
	while (!s.empty())
	{
		RBTNode* tmp = s.top();
		s.pop();
		if (tmp->rightChild)
			s.push(tmp->rightChild);
		if (tmp->leftChild)
			s.push(tmp->leftChild);
		cout << tmp->val << " ";
	}
}

void MyRBT::inorder()
{
	if (root == NULL)
		return;
	stack<RBTNode*> s;
	RBTNode* p = root;
	while (!s.empty() || p)
	{
		while (p)
		{
			s.push(p);
			p = p->leftChild;
		}
		p = s.top();
		cout << p->val << " ";
		s.pop();
		if (p->rightChild)
			p = p->rightChild;
		else
			p = NULL;
	}
}
struct postNode
{
	RBTNode* node;
	bool vis;
	postNode(RBTNode* n) :node(n), vis(false)
	{

	}
};
/*
void MyRBT::postorder()
{
	if (root == NULL)
		return;
	stack<postNode*> s;
	s.push(new postNode(root));
	while (!s.empty())
	{
		postNode *tmp = s.top();
		if (tmp->vis)
		{
			s.pop();
			cout << tmp->node->val << " ";
			delete tmp;
		}
		else{
			tmp->vis = true;
			if (tmp->node->rightChild)
				s.push(new postNode(tmp->node->rightChild));
			if (tmp->node->leftChild)
				s.push(new postNode(tmp->node->leftChild));
		}
	}
}


void MyRBT::postorder()
{
	if (root == NULL)
		return;
	stack<pair<RBTNode* , bool>> s;
	s.push(make_pair(root , false));
	while (!s.empty())
	{
		if (s.top().second)
		{
			cout << s.top().first->val << " ";
			s.pop();
		}
		else{
			RBTNode* tmp = s.top().first;
			s.top().second = true;
			if (tmp->rightChild)
				s.push(make_pair(tmp->rightChild, false));
			if (tmp->leftChild)
				s.push(make_pair(tmp->leftChild, false));
		}
	}
}

void MyRBT::postorder()
{
	if (root == NULL)
		return;
	stack<RBTNode*> s;
	s.push(root);
	s.push(root);
	RBTNode* tmp = root;
	while (!s.empty())
	{
		tmp = s.top();
		s.pop();
		if (!s.empty() && tmp == s.top())
		{
			if (tmp->rightChild)
			{
				s.push(tmp->rightChild);
				s.push(tmp->rightChild);
			}
			if (tmp->leftChild)
			{
				s.push(tmp->leftChild);
				s.push(tmp->leftChild);
			}
		}
		else{
			cout << tmp->val << " ";
		}
		
	}
}
*/

void MyRBT::postorder()
{
	if (root == NULL)
		return;
	stack<RBTNode*> s;
	s.push(root);
	RBTNode* last = root;
	while (!s.empty())
	{
		RBTNode* tmp = s.top();
		if (last == tmp->rightChild || (tmp->rightChild == NULL && last == tmp->leftChild) || (tmp->leftChild == NULL && tmp->rightChild == NULL))
		{
			s.pop();
			cout << tmp->val << " ";
			last = tmp;
		}
		else{
			if (tmp->rightChild)
				s.push(tmp->rightChild);
			if (tmp->leftChild)
				s.push(tmp->leftChild);
		}
	}
}
RBTNode* MyRBT::leftRotate(RBTNode* node)
{
	RBTNode* pnode = node->parent;
	RBTNode* rnode = node->rightChild;
	node->parent = rnode;
	node->rightChild = rnode->leftChild;
	rnode->leftChild = node;
	rnode->parent = pnode;
	if (pnode == NULL)
		return root = rnode;
	else{
		if (pnode->leftChild == node)
			pnode->leftChild = rnode;
		else
			pnode->rightChild = rnode;
	}
	return rnode;
}
RBTNode* MyRBT::rightRotate(RBTNode* node)
{
	RBTNode* pnode = node->parent;
	RBTNode* lnode = node->leftChild;
	node->parent = lnode;
	node->leftChild = lnode->rightChild;
	lnode->rightChild = node;
	lnode->parent = pnode;
	if (pnode == NULL)
		return root = lnode;
	else{
		if (pnode->leftChild == node)
			pnode->leftChild = lnode;
		else
			pnode->rightChild = lnode;
	}
	return lnode;
}

RBTNode* MyRBT::search(int val)
{
	return search(val, root);
}

RBTNode* MyRBT::search(int val, RBTNode* node)
{
	if (node == NULL)
		return NULL;
	else{
		if (val < node->val)
			return search(val, node->leftChild);
		else if (val > node->val)
			return search(val, node->rightChild);
		else
			return node;
	}
}
void MyRBT::insert(int val)
{
	insert(val, root);
}

void MyRBT::insert(int val, RBTNode* node)
{
	if (node == NULL)
		root = new RBTNode(val);
	else{
		RBTNode* pnode = NULL;
		while (node != NULL)
		{
			pnode = node;
			if (val < node->val)//left
			{
				node = node->leftChild;
			}
			else{
				node = node->rightChild;
			}
		}
		node = new RBTNode(val);
		node->parent = pnode;
		if (val < pnode->val)
			pnode->leftChild = node;
		else
			pnode->rightChild = node;
		if (pnode->color == RED)
		{
			insertFixUp(node);
		}
	}
	root->color = BLACK;
}
void MyRBT::insertFixUp(RBTNode* node)
{
	while (node->parent != NULL && node->parent->parent != NULL && node->parent->color == RED)
	{
		RBTNode* pnode = node->parent;
		RBTNode* gnode = pnode->parent;
		RBTNode* unode = pnode == gnode->leftChild ? gnode->rightChild : gnode->leftChild;

		if (unode != NULL && unode->color == RED)
		{
			pnode->color = BLACK;
			unode->color = BLACK;
			gnode->color = RED;
			node = gnode;
			continue;
		}

		if (pnode == gnode->leftChild)
		{
			if (node == pnode->rightChild)
			{
				node = pnode;
				leftRotate(node);
			}
			pnode = node->parent;
			gnode->color = RED;
			pnode->color = BLACK;
			node = gnode;
			rightRotate(gnode);
		}
		else{
			if (node == pnode->leftChild)
			{
				node = pnode;
				rightRotate(node);
			}
			pnode = node->parent;
			gnode->color = RED;
			pnode->color = BLACK;
			node = gnode;
			leftRotate(gnode);
		}
	}
}

RBTNode* MyRBT::afterNode(RBTNode* node)
{
	node = node->rightChild;
	while (node->leftChild != NULL)
	{
		node = node->leftChild;
	}
	return node;
}
RBTNode* MyRBT::frontNode(RBTNode* node)
{
	node = node->leftChild;
	while (node->rightChild != NULL)
	{
		node = node->rightChild;
	}
	return node;
}


void MyRBT::remove(int val)
{
	RBTNode* node = search(val);
	if (node)
		remove(node);
}
void MyRBT::remove(RBTNode* node)//root problem
{
	if (node->leftChild && node->rightChild)
	{
		RBTNode* after = afterNode(node);
		node->val = after->val;
		remove(after);
		return;
	}
	else {
		if (node->leftChild == NULL && node->rightChild == NULL)
		{
			if (node == root)
			{
				delete node;
				root = NULL;
			}
			else if (node->color == RED)
			{
				RBTNode* pnode = node->parent;
				if (node == pnode->leftChild)
					pnode->leftChild = NULL;
				else
					pnode->rightChild = NULL;
				delete node;
			}
			else{
				removeFixUp(node);
				RBTNode* pnode = node->parent;
				if (node == pnode->leftChild)
					pnode->leftChild = NULL;
				else
					pnode->rightChild = NULL;
				delete node;
			}

		}
		else{
			if (node->leftChild == NULL)
			{
				node->val = node->rightChild->val;
				remove(node->rightChild);
				return;
			}
			else{
				node->val = node->leftChild->val;
				remove(node->leftChild);
				return;
			}	
		}
	}
	root->color = BLACK;
}
bool isBLACK(RBTNode* node)
{
	return node == NULL || node->color == BLACK;
		
}
void MyRBT::removeFixUp(RBTNode* node)
{
	RBTNode* pnode = node->parent;
	RBTNode* bnode;
	if (node == pnode->leftChild)//当前节点是左节点
	{
		bnode = pnode->rightChild;
		if (bnode->color == RED)
		{
			pnode->color = RED;
			bnode->color = BLACK;
			leftRotate(pnode);
			removeFixUp(pnode);
		}
		else{
			if (isBLACK(bnode->leftChild) && isBLACK(bnode->rightChild))
			{
				bnode->color = RED;
				removeFixUp(pnode);
			}
			else if (isBLACK(bnode->rightChild))
			{
				bnode->color = RED;
				bnode->leftChild->color = BLACK;
				rightRotate(bnode);			
				removeFixUp(node);
			}
			else
			{
				bnode->rightChild->color = BLACK;
				bnode->color = pnode->color;
				pnode->color = BLACK;
				leftRotate(pnode);
			}
		}
	}
	else{
		bnode = pnode->leftChild;
		if (bnode->color == RED)
		{
			pnode->color = RED;
			bnode->color = BLACK;
			rightRotate(pnode);
			removeFixUp(pnode);
		}
		else{
			if (isBLACK(bnode->leftChild) && isBLACK(bnode->rightChild))
			{
				bnode->color = RED;
				removeFixUp(pnode);
			}
			else if (isBLACK(bnode->leftChild))//兄弟节点右节点为红
			{
				bnode->color = RED;
				bnode->rightChild->color = BLACK;
				leftRotate(bnode);
				removeFixUp(node);
			}
			else
			{
				bnode->leftChild->color = BLACK;
				bnode->color = pnode->color;
				pnode->color = BLACK;
				leftRotate(pnode);
			}
		}
	}
}