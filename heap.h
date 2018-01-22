#pragma once
#ifndef HEAP_H
#define HEAP_H
#include<vector>
#include<iostream>
#include<cassert>

using namespace std;

//template<typename T>
class Maxheap
{
private:
	vector<int> Item;
	int capactiy;
	int count;
	void shiftup(int k)
	{
		while (k > 1)
		{
			if (Item[k] > Item[k / 2])
				swap(Item[k], Item[k / 2]);
			k /= 2;
		}
	}
	void shiftdown(int k)
	{
		while (k*2 <= count)
		{
			int j = 2 * k;
			if (j + 1 <= count && Item[j] < Item[j + 1])
			{
				j = j + 1;
			}
			if (Item[k] < Item[j])
				swap(Item[k], Item[j]);
			k = j;//k没有变化，j变了
		}
	}
public:
	Maxheap(int n)
	{
		this->Item = vector<int>(n + 1);
		this->capactiy = n;
		count = 0;
	};
	Maxheap(vector<int> arr,int n)
	{
		Item = vector<int>(n + 1);
		capactiy = n;
		for (int i = 0; i < n; i++)
		{
			Item[i+1] = arr[i];
		}
		count = n;
		int i = n / 2;
		for (i; i > 0; i--)
		{
			shiftdown(i);
		}
	}
	~Maxheap() {};
	void isEmpty()
	{
		if (count <= 0)
			cout << "is empty";
		else
			cout << "not empty";
	}
	int size()
	{
		return count;
	}
	void insert(int item)
	{
		assert(count < capactiy);
		Item[count + 1] = item;
		count++;
		shiftup(count);
	}
	int out()
	{
		assert(count > 0);
		int ret = Item[1];
		swap(Item[1], Item[count]);
		count--;
		shiftdown(1);
		return ret;
	}
};

void __shiftdown(vector<int> &arr, int n, int k)
{
	while (2 * k + 1 < n)
	{
		int j = 2 * k + 1;
		if (j + 1 < n&&arr[j] < arr[j + 1])
			j = j + 1;
		if (arr[k] < arr[j])
			swap(arr[k], arr[j]);
		k = j;
	}
}

void heapsort(vector<int> &arr, int n)
{
	//heapify
	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		__shiftdown(arr, n, i);
	}
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[i], arr[0]);
		__shiftdown(arr, n, 0);
	}
};

#endif // !HEAP_H

