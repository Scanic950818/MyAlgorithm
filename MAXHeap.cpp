#include "MAXHeap.h"


MAXHeap::MAXHeap()
{
}


MAXHeap::~MAXHeap()
{
}

void MAXHeap::filterUp(int start)
{
	int n = start;
	int p = (n - 1) / 2;
	int tmp = data[n];
	while (n > 0)
	{
		if (data[p] < tmp)
		{
			//int tmp = data[n];

			data[n] = data[p];
			//data[p] = tmp;
			n = p;
			p = (n - 1) / 2;
		}
		else{
			break;
		}
	}
	data[n] = tmp;
}
void MAXHeap::filterDown(int start, int end)
{
	int n = start;
	int son = 2 * n + 1;
	int tmp = data[n];
	while (son <= end)
	{
		if (son + 1 <= end && data[son + 1] > data[son])
			son++;
		if (data[son] > tmp)
		{
			data[n] = data[son];
			n = son;
			son = 2 * n + 1;
		}
		else{
			break;
		}
	}
	data[n] = tmp;
}
void MAXHeap::insert(int val)
{
	int size = data.size();
	data.push_back(val);
	filterUp(size);
}
int MAXHeap::removeMax()
{
	int size = data.size();
	if (size == 0)
		return NULL;
	if (size == 1)
	{
		int tmp = data[0];
		data.pop_back();
		return tmp;
	}
	int tmp = data[0];
	data[0] = data[size - 1];
	data.pop_back();
	filterDown(0, size - 2);
	return tmp;
}

void MAXHeap::filterDown(int data[], int start, int end)
{
	int n = start;
	int son = 2 * n + 1;
	int tmp = data[n];
	while (son <= end)
	{
		if (son + 1 <= end && data[son + 1] > data[son])
			son++;
		if (data[son] > tmp)
		{
			data[n] = data[son];
			n = son;
			son = 2 * n + 1;
		}
		else{
			break;
		}
	}
	data[n] = tmp;
}

void  MAXHeap::Order(int a[], int len)
{
	createHeap(a, len);
	for (int i = len - 1; i >= 0; i--)
	{
		int tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		if (i > 0)
			filterDown(a, 0, i - 1);
	}
}

void  MAXHeap::createHeap(int a[], int len)
{
	int firstP = len / 2 - 1;
	for (int i = firstP; i >= 0; i--)
	{
		filterDown(a, i, len - 1);
	}
}