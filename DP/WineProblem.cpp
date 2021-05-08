#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int dp[100][100];

int maxprofitTD(int *arr, int beg, int end, int year)
{
	if(beg>end)
		return 0;

	if(dp[beg][end]!=-1)
		return dp[beg][end];

	//sell from beginning
	int q1 = arr[beg]*year + maxprofitTD(arr, beg+1, end, year+1);
	//sell from end
	int q2 = arr[end]*year + maxprofitTD(arr, beg, end-1, year+1);
	int ans = max(q1, q2);
	dp[beg][end]=ans;  // answer for range beg to end
	return ans;
}

int maxprofitBU(int *arr, int n)
{
	int dp[100][100] = {};
	int year = n;

	for (int i = 0; i < n; ++i)
	{
		dp[i][i] = year * arr[i];
	}
	--year;

	for (int len = 2; len<=n; ++len)
	{
		int start = 0;
		int end = n - len;
		while(start<=end)
		{
			int endwindow = start + len -1;
			dp[start][endwindow]  = max(arr[start]*year+dp[start+1][endwindow], arr[endwindow]*year+dp[start][endwindow-1]);
			++start;
		}
		year--;
	}

    for(int i=0; i<n ;i++)
    {
        for(int j=0; j<n ; j++)
        cout<<setw(3)<<dp[i][j]<<" ";
        cout<<endl;
    }

	return dp[0][n-1];
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n; //no. of bottles kept on the shelf
	int *arr = new int [n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i]; //prices of bottles
	}
	
	memset(dp,-1, sizeof(dp));
	int ans = maxprofitTD(arr,0,n-1,1);
	cout<<ans<<endl;
	cout<<maxprofitBU(arr,n);
	return 0;
}