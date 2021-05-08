#include <iostream>
#include <math.h>

using namespace std;
int k=0;
long long arr[1000000];

void rec(int n)
{	
	if(n==0 or n==1)
	{
		arr[k++]=n;
		return;
	}

	rec(floor(n/2));
	rec(n%2);
	rec(floor(n/2));
}



int main()
{
	int n,l,r,count=0;
	cin>>n>>l>>r;
	rec(n);

	if(n==0 or n==1)
{
	//nothing
}

		else
		{for(int i=0;i<k;i++)
			{if(i>=l and i<=r and arr[i]==1)
				count++; }
		}
	cout<<count;
	return 0;
}