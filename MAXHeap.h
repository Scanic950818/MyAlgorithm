#pragma once
#include "vector"

using std::vector;

class MAXHeap
{
public:
	MAXHeap();
	~MAXHeap();
	void insert(int val);
	int removeMax();
	void Order(int a[], int len);
private:
	vector<int> data;
	void filterUp(int start);
	void filterDown(int start, int end);
	void filterDown(int a[], int start, int end);
	void createHeap(int a[], int len);
};

