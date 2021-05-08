#include <iostream>
using namespace std;
int config=0;

void print (bool **vis, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n;j++)
		{	if(vis[i][j]==false)
				cout<<" . ";
			else
				cout<<" K ";  }
			cout<<endl; 
	}
}

bool safe (bool**vis, int i, int j, int n) 
{
	if( i-2>=0 and j-1>=0 and vis[i-2][j-1]==true )
		return false;

	if( i-2>=0 and j+1<n and vis[i-2][j+1]==true )
		return false;

	if( i-1>=0 and j-2>=0 and vis[i-1][j-2]==true )
		return false;

	if( i-1>=0 and j+2<n and vis[i-1][j+2]==true )
		return false;

	return true;	
}

void nknight(int n, bool**vis, int sr, int sc, int placed)
{
	if(placed==n)
	{
		config++;
		print(vis,n);
		cout<<"\n********************\n\n";
		return;
	}



	for (int i = sr; i < n; ++i)
	{
		for(int j=(i==sr)?sc:0 ; j<n ; j++)
		if(safe(vis,i,j,n))
		{
			vis[i][j]=true;
			nknight(n,vis,i,j+1,placed+1);
			vis[i][j]=false;

		}	
	}
	return;
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
	
	nknight(n,vis,0,0,0);
	cout<<config;
}