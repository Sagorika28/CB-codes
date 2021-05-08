#include <iostream>
using namespace std;

long tiles(int n, int m, long **dp)
{   
    long result;
	//base case
	if(n<m)
		return 1;

	if(n==m)
		return 2;

    if(dp[n][m] != 0)
    {
        return dp[n][m];
    }

	//rec case
	if (n>m)
	{
	     result = tiles(n-1,m,dp)+tiles(n-m,m,dp);
	}
	dp[n][m] = result;
    return result;
}

int main()
{
	int t;
	cin>>t;
	long n,m;
	while(t)
	{
        cin>>n>>m;
        long **dp=new long*[n+1];
		for (int i = 0; i <=n; ++i)
		dp[i]= new long [m+1]();
        
		cout<<tiles(n,m,dp)<<endl;
		t--;
	}
return 0;
}