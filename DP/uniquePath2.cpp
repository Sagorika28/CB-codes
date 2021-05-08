#include <iostream>
using namespace std;

int paths(int **arr, int n, int m)
{
	if(arr[0][0]==1)
		return 0;
	if(arr[n-1][m-1]==1)
		return 0;
	if(m==1 and n==1)
		return 1;
	long long int dp[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			dp[i][j]=0;
		}
	}
	for (int i = n-1; i >=0 ; --i)
	{
		if(arr[i][m-1] == 1)
			break;
		dp[i][m-1] = 1;
	}

	for (int i = m-1; i >=0 ; --i)
	{
		if(arr[n-1][i] == 1)
			break;
		dp[n-1][i] = 1;
	}

	for (int i = n-2; i >=0 ; --i)
	{
		for (int j = m-2; j >=0 ; --j)
		{
			if(arr[i][j] ==1)
				continue;
			dp[i][j] = (unsigned long long int) (dp[i+1][j] + dp[i][j+1]);
		}
	}
	return (int) dp[0][0];
}

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	int **arr = new int *[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i]= new int [m];
	}
	for (int i = 0; i < n; ++i)
	{
		for(int j=0; j<m; j++)
			cin>>arr[i][j];
	}
	cout<<paths(arr,n,m);
	return 0;
}