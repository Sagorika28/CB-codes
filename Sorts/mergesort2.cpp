#include <iostream>
using namespace std;

void merges(int a[], int n, int b[], int m)
{
	int c[m+n];
	int i=0, j=0, k=0;
	
		while(i<n and j<m)
		{
			if(a[i]<=b[j])
			{
				c[k]=a[i];
				i++;
				k++;
			}
			else 
			{
				c[k]=b[j];
				j++;
				k++;
			}
		}
	
		while (j<m)
		{
			
					c[k]=b[j]; 
					j++;
					k++;
				
		}
		while (i<n)
		{
			
					c[k]=a[i]; 
					i++;
					k++;
		}		

		for(k=0;k<m+n;k++)
			cout<<c[k]<<" ";
		return; 
		
	}

int *mergesortHelp(int *arr, int start , int end)
{
	if(start == end)
	{
		int *base = new int [1];
		base[0]= arr[start];
		return base;
	}

	int mid = (start+end)/2;
	int *left = mergesortHelp(arr, start, mid);
	int *right = mergesortHelp(arr, mid+1, end);
	int *result = merges (left, mid-start+1, right, end-mid);
	return result;
}

void mergesort(int *arr, int n)
{
	int *result = mergesortHelp(arr, 0, n-1);
	for(int i=0; i<n; i++)
		arr[i]=result[i];
	return;
}

int main()
{
	int n,m;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	mergesort(a,n);

	

	return 0;
}