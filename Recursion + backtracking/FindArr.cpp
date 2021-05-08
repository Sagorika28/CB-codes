#include <iostream>
using namespace std;

void index(int*a,int n,int m,int k)
{	
	int x=0;
	
	if(n==0)
	  {
	  	return;
	  }	

	if(a[k]==m)
	{
		cout<<k<<" ";
	}
	index(a,n-1,m,k+1);
}

int main()
{
	int n,m;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>m;
	index(arr,n,m,0);
}