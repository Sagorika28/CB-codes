#include <iostream>
using namespace std;

int bitonic(int *arr, int n)
{
	if(n==0)
		return 0;
	int *dp1 = new int [n];
	for(int i=0; i<n; i++)
		dp1[i]=i;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if(arr[j]<arr[i])
				{ 
					dp1[i]=(dp1[i]+dp1[j]);
						
				}
		}
	}

	int *dp2 = new int [n];
	for(int i=0; i<n; i++)
		dp2[i]=i;
	for (int i = n-2; i >=0; --i)
	{
		for (int j = n-1; j > i; --j)
		{
			if(arr[j]<arr[i])
				dp2[i]=(dp2[i]+dp2[j]);
		}
	}

	int *dp=new int [n];
	for(int i=0; i<n; i++)
		dp[i] = dp1[i] + dp2[i] - i;

	int result=0;
	for (int i = 0; i < n; ++i)
	{
		if(dp[i]>result)
			result=dp[i];
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *arr=new int [n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	cout<<bitonic(arr,n);
	return 0;
}