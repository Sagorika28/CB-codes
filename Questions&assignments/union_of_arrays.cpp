#include <iostream>
using namespace std;

void change(int c[],int&l,int j)
{
    for(int i=j;i<l;i++)
    {
        c[i]=c[i+1];
    }
    l--;
}

int main(int argc, char const *argv[])
{
	int n,m; //sizes of arrays
	cin>>n>>m;
	int a[m],b[n];
	int i,j,k;
	int c[100];
	for (i = 0; i < m; ++i)
		cin>>a[i];
	for (j = 0; j < n; ++j)
		cin>>b[j];
    int l=m+n;

    i=j=k=0;
	while(m--)
		{
			c[k]=a[i];
			i++;
			k++;
		}
	while(n--)
		{
			c[k]=b[j];
			j++;
			k++;
		}
  
    for(i=0;i<l;i++)
    {
        for(j=i+1;j<l;j++)
        {
            if(c[i]==c[j])
            {
               change(c,l,j);
            }
        }
    }

	for (k = 0; k < l; ++k)
		cout<<c[k]<<" "; 
	return 0;
}