#include <iostream>
#include <map>
#include <vector>
#define ll long long int
using namespace std;

int numberOfArithmeticSlices(vector <int> &arr)
{
	int n = arr.size();
	if(n==0)
		return 0;
	unordered_map<ll,ll> dp[n];
	ll result = 0;
	for (int i = 1; i < n; ++i)
	{
		for(int j= i-1; j>=0; j--)
		{
			ll diff = (ll)((ll)arr[i]-(ll)arr[j]);
			if(dp[j].find(diff) != dp[j].end())
			{
				dp[i][diff] += (dp[j][diff] +1);
				result += (dp[j][diff]);
			}
			else
				dp[i][diff]++;
		}
	}
	return (int) result;
}

int main(int argc, char const *argv[])
{
	vector <int> arr;
	for (int i = 0; i < arr.size(); ++i)
	{
		cin>>arr[i];
	}
	cout<<numberOfArithmeticSlices(arr);
	return 0;
}