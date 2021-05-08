#include <iostream>
using namespace std;
int result =0;

void print (bool **vis, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n;j++)
		{	if(vis[i][j]==false)
				cout<<" . ";
			else
				cout<<" Q ";  }
			cout<<endl; 
	}
}

bool safe (bool**vis, int row, int col, int n) 
{
	for(int i=row-1;i>=0;i--)
	{
		if(vis[i][col]==true)
			return false;
	}

	for(int i=row-1, j=col-1;i>=0 and j>=0;i--, j--)
	{
		if(vis[i][j]==true)
			return false;
	}

	for(int i=row-1, j=col+1;i>=0 and j<n;i--, j++)
	{
		if(vis[i][j]==true)
			return false;
	}
	return true;	
}

void nqueen(int n, bool**vis, int row)
{
	if(row==n)
	{
		result++;
		print(vis,n);
		cout<<"\n********************\n\n";
		return;
	}



	for (int i = 0; i < n; ++i)
	{
		if(safe(vis,row,i,n))
		{
			vis[row][i]=true;
			nqueen(n,vis,row+1);
			vis[row][i]=false;

		}	
	}
}

int main()
{
	int n;
	cin>>n;
	
	
	bool**vis=new bool*[n];
	for(int i=0;i<n;i++)
	{
		vis[i]= new bool [n]();
	}
	
	nqueen(n,vis,0);
	cout<<result;
}