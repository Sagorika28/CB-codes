#include <iostream>

using namespace std;

int result = 0;

void print (char **maze, bool **visited, int n, int m)
{	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if (visited[i][j]==true)
			{
				cout<<" 1 ";
			}
			else 
				cout<<" 0 ";	}
		cout<<endl;
	}
}

bool isitsafe (int i,int j, int n, int m)
{
	return i>=0 and j>=0 and i<n and j<m;
}

void ratinmaze (char **maze, bool **visited, int i, int j, int n, int m)
{
	if(maze[i][j]=='X')
		return;
	if(i==n-1 and j==m-1)
	{
		result++;
		print (maze,visited,n,m);
		cout<<endl;
		return;
	}



if(isitsafe(i,j+1,n,m) and maze[i][j+1]=='O')
{
    visited[i][j]=true;
	ratinmaze(maze,visited,i,j+1,n,m);
}

if(isitsafe(i+1,j,n,m) and maze[i+1][j]=='O')
{
    visited[i][j]=true;
	ratinmaze(maze,visited,i+1,j,n,m);
}

//visited[i][j]=false;
}

int main()
{  	int n,m;
	cin>>n>>m;
	//creating a dynamic 2D array
	char**arr=new char*[n];
	for(int i=0;i<n;i++)
	{
		arr[i]= new char [m];
	}

	//marking array
	bool**vis=new bool*[n];
	for(int i=0;i<n;i++)
	{
		vis[i]= new bool [m]();//initialiing array elements with 0
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cin>>arr[i][j];

	}
	if(arr[n-1][n-1]=='X')
		cout<<"-1";
		else
		{	ratinmaze(arr,vis,0,0,n,m);
			}
		if(result==0)
			cout<<"-1";
	
	return 0;
}