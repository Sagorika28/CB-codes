#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

void ss(int *a, int n, int x, int&count)
{
	if (n==0)
	{	
		if(x==0)
		    count++; 
        return;
	}
	int ch=a[0];
	ss(a+1,n-1,x+ch,count);
	ss(a+1,n-1,x,count);

}

int main()
{
	int t,n;
	cin>>t;
	while(t)
	{
        int count = 0;
		cin>>n;
		int *a=new int[n];
		for(int i=0;i<n;i++)
			{
				cin>>a[i];
			}
		ss(a,n,0,count);

        if(count>1)
            cout<<"Yes"<<endl;
        
        else
            cout<<"No"<<endl;

		t--;
	}
	
	return 0;
}
