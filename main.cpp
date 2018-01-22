#include<ctime>
#include"heap.h"

int main()
{
	int n = 10;
	vector<int> arr = { 1,2,3,4,5 };
	Maxheap ar =  Maxheap(arr,5);
	heapsort(arr,5);
	//srand(time(NULL));
	//for (int i = 0; i < n; i++)
	//	arr.insert(rand() % 100);
	//for (int i = 0; i < n; i++)
	//	cout << arr.out()<<' ';
	return 0;
}