#include <iostream>
using namespace std;

int kadane(int *arr, int n)
{
	int global_max = INT_MIN;
	int curr_sum=0;
	for(int i=0; i<=n; i++){
		curr_sum+=arr[i];
		global_max = max(global_max,curr_sum);
		if(curr_sum<0)
			curr_sum=0;
	}
	return global_max;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	kadane(arr,n);
	return 0;
}