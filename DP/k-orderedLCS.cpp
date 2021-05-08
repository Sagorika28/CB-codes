#include <iostream>
#include <cstring>

#define ll long long
ll dp[2005][2005][8] , a[2005], b[2005], n ,m;
using namespace std;

ll f(ll i, ll j, ll k)
{
	if(i==n || j==m) //if any string is finished then ans is 0
		return 0;
	if(dp[i][j][k] != -1) //if current state has already been occupied
		return dp[i][j][k];

	ll res =0;
	if(a[i]==b[j])
		res = 1 + f(i+1,j+1,k);
	else
	{
		if(k>0)
			res = 1 + f(i+1,j+1,k-1); // we have converted a single char to match with the jth of string b
		res = max(res,f(i,j+1,k));
		res = max(res,f(i+1,j,k));
	}
	return dp[i][j][k] = res;
}

int main(int argc, char const *argv[])
{
	memset(dp,-1,sizeof(dp));
    ll k;
	cin>>n>>m>>k;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin>>b[i];
	}
	cout<<f(0,0,k);
	return 0;
}