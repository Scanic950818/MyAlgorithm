#pragma once
#include "iostream"
enum RBTColor{RED , BLACK};

struct RBTNode
{
	int val;
	RBTColor color;
	RBTNode* leftChild;
	RBTNode* rightChild;
	RBTNode* parent;


	RBTNode(int Value) :val(Value), leftChild(NULL), rightChild(NULL), parent(NULL), color(RED)
	{
	}
};

class MyRBT
{
public:
	MyRBT();
	~MyRBT();
	RBTNode* search(int val);
	void remove(int val);
	void insert(int val);
	void traverse();

	void preorder();
	void inorder();
	void postorder();
private:
	RBTNode* root;
	RBTNode* search(int val, RBTNode* node);
	void remove(RBTNode* node);
	void insert(int val, RBTNode* node);
	void insertFixUp(RBTNode* node);
	void removeFixUp(RBTNode* node);
	RBTNode* leftRotate(RBTNode* node);
	RBTNode* rightRotate(RBTNode* node);
	RBTNode* afterNode(RBTNode* node);
	RBTNode* frontNode(RBTNode* node);


};

