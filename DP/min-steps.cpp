#include <iostream>
#include <climits>
using namespace  std;

int msBU(int n)
{
	int *dp=new int [n+1];
	dp[0]=INT_MAX;
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	for(int i=4; i<=n; i++)
	{
		int div_by_3=INT_MAX;
		int div_by_2=INT_MAX;
		int sub_by_1=INT_MAX;

	if(i%3==0)
		div_by_3 = 1+dp[i/3];
	if(i%2==0)
		div_by_2 = 1+dp[i/2];
	sub_by_1 = 1+dp[i-1];
	dp[i] = min(sub_by_1, min(div_by_3, div_by_3));
	}
	return dp[n];
}

int msTD(int n, int*dp)
{
	if(n==1 or n==2 or n==3)
		return 1;
	if(n==0)
		return INT_MAX;
	if(dp[n]!=0)
		return dp[n];

	int div_by_3=INT_MAX;
	int div_by_2=INT_MAX;
	int sub_by_1=INT_MAX;
	if(n%3==0)
		div_by_3 = 1+msTD(n/3,dp);
	if(n%2==0)
		div_by_2 = 1+msTD(n/2,dp);

	sub_by_1= 1+msTD(n-1,dp);
	int result = min(sub_by_1, min(div_by_3, div_by_2));
	dp[n]=result;
	return result;	

}

int ms(int n)
{
	if(n==1 or n==2 or n==3)
		return 1;
	if(n==0)
		return INT_MAX;

	int div_by_3=INT_MAX;
	int div_by_2=INT_MAX;
	int sub_by_1=INT_MAX;
	if(n%3==0)
		div_by_3 = 1+ms(n/3);
	if(n%2==0)
		div_by_2 = 1+ms(n/2);

	sub_by_1= 1+ms(n-1);
	int result = min(sub_by_1, min(div_by_3, div_by_2));
	return result;	

}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *dp = new int [n+1];
	cout<<msTD(n,dp)<<endl;
	cout<<msBU(n);
	return 0;
}