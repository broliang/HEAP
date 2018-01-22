#include<ctime>
#include"heap.h"
#include"Indexsort.h"
int main()
{
	int n = 10;
	//vector<int> arr = { 1,2,3,4,5 };
	IndexMaxheap arr =  IndexMaxheap(n);
	//heapsort(arr,5);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr.insert(i,rand() % 100);
	for (int i = 0; i < n; i++)
		cout << arr.out()<<' ';
	return 0;
}