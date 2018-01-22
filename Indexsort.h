#pragma once
#ifndef INDEXHEAP_H
#define INDEXHEAP_H

class IndexMaxheap
{
private:
	vector<int> Index;
	vector<int> Item;
	int capactiy;
	int count;
	void shiftup(int k)
	{
		while (k > 1)
		{
			if (Item[Index[k]] > Item[Index[k / 2]])
				swap(Index[k], Index[k / 2]);
			k /= 2;
		}
	}
	void shiftdown(int k)
	{
		while (k * 2 <= count)
		{
			int j = 2 * k;
			if (j + 1 <= count && Item[Index[j]] < Item[Index[j + 1]])
			{
				j = j + 1;
			}
			if (Item[Index[k]] < Item[Index[j]])
				swap(Item[Index[k]], Item[Index[j]]);
			k = j;//k没有变化，j变了
		}
	}
public:
	IndexMaxheap(int n)
	{
		this->Item = vector<int>(n + 1);
		this->Index = vector<int>(n + 1);
		this->capactiy = n;
		count = 0;
	};
	IndexMaxheap(vector<int> arr, int n)
	{
		Item = vector<int>(n + 1);
		capactiy = n;
		for (int i = 0; i < n; i++)
		{
			Item[i + 1] = arr[i];
		}
		count = n;
		int i = n / 2;
		for (i; i > 0; i--)
		{
			shiftdown(i);
		}
	}
	~IndexMaxheap() {};
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
	void insert(int i,int item)
	{
		assert(count+1 <= capactiy);
		assert(i + 1 >= 1 && i + 1 <= capactiy);
		count++;
		i = i+1;
		Item[i] = item;
		Index[count] = i;
		shiftup(count);
	}
	int out()
	{
		assert(count > 0);
		int ret = Item[Index[1]];
		swap(Item[Index[1]], Item[Index[count]]);
		count--;
		shiftdown(1);
		return ret;
	}
	//int out()
	//{
	//	assert(count > 0);
	//	int ret = Item[1];
	//	swap(Item[1], Item[count]);
	//	count--;
	//	shiftdown(1);
	//	return ret;
	//}
};


#endif // !INDEXHEAP_H

