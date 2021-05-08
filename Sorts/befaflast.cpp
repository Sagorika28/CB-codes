#include <iostream>
using namespace std;

int partition(int *arr, int start, int end)
{
	int i= start -1;
	int j = start;
	int pivot = arr[end];
	while(j<end)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
		j++;
	}
	swap(arr[i+1], arr[end]);
	return i+1;
}

void quickSortHelper( int *arr, int start, int end)
{
	if(start>=end)
		return;
	partition(arr, 0,  )
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	qs(a,n);
	return 0;
}