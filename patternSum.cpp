#include <iostream>
#include <cmath>
using namespace std;

int sum(int n)
{
	int sum=0;
	for (int i = 1; i <= n; ++i)
	{
		sum += (pow(-1,i))*i;
	}
	return sum;
}

int main() 
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<sum(n);
		cout<<endl;
	}
	return 0;
}