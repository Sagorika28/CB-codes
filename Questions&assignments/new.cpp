#include <iostream>

using namespace std;

int issort(int a[],int n)
{
    if (n==1 or n==0)
    return true;
    else if(a[n-1]>a[n-2])
    return issort(a,n-1);
    else
    return false;
}
int main()
{
int n,i,p;
cin>>n;
int a[n];
for (i=0;i<n;i++)
cin>>a[i];
p=issort(a,n);
if(p)
cout<<"true";
else
    cout<<"false";
	return 0;
}
