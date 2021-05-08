#include <iostream>
using namespace std;
int memo[100];
int maxprofit(int arr[], int totallen)
{
	if (totallen==0)
	return 0;

	if (memo[totallen]!=-1)
	{
		return memo[totallen];
	}

	int best = 0;
	for (int i = 1; i < totallen; ++i)
	{
		int netProfit = arr[i] + maxprofit(arr,totallen-1);
		best = max(best,netProfit); 
	}
	
	memo[totallen] = best;
	return best;
}

int maxprofitBU(int arr[], int totallen)
{
	int dp[100] = {};

	for (int len = 1; len <= totallen; ++len)
	{
		int best = 0;
		for (int cut = 1 ; cut <= len; ++cut)
		{
			best = max(best,arr[cut]+dp[len-cut]);
		}
		dp[len]=best;
	}
return dp[totallen];
}

int main(int argc, char const *argv[])
{
	int priceOfEachLen[100], totallen;
	cin>>totallen;
	for (int i = 1; i <= totallen; ++i)
	{
		cin>>priceOfEachLen[i];
	}
	for (int i = 0; i <=totallen; ++i)
	{
		memo[i]=-1;
	}
    cout << maxprofit(priceOfEachLen,totallen)<<endl;
    cout << maxprofitBU(priceOfEachLen,totallen);
	return 0;
}