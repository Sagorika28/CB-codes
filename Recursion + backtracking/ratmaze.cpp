#include <iostream>

using namespace std;

int result = 0;

void print (int **maze, bool **visited, int n)
{	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if (visited[i][j]==true)
			{
				cout<<" P ";
			}
			else 
				cout<<" . ";	}
		cout<<endl;
	}
}

bool isitsafe (int i,int j, int n)
{
	return i>=0 and j>=0 and i<n and j<n;
}

void ratinmaze (int **maze, bool **visited, int i, int j, int n)
{
	if(maze[i][j]==1)
		return;
	if(i==n-1 and j==n-1)
	{
		result++;
		print (maze,visited,n);
		cout<<endl;
		return;
	}

visited[i][j]=true;

if(isitsafe(i-1,j,n) and maze[i-1][j]==0 and visited[i-1][j]==false)
	ratinmaze(maze,visited,i-1,j,n);
if(isitsafe(i,j-1,n) and maze[i][j-1]==0 and visited[i][j-1]==false)
	ratinmaze(maze,visited,i,j-1,n);
if(isitsafe(i,j+1,n) and maze[i][j+1]==0 and visited[i][j+1]==false)
	ratinmaze(maze,visited,i,j+1,n);
if(isitsafe(i+1,j,n) and maze[i+1][j]==0 and visited[i+1][j]==false)
	ratinmaze(maze,visited,i+1,j,n);

visited[i][j]=false;
}

int main()
{  	int n;
	cin>>n;
	//creating a dynamic 2D array
	int**arr=new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i]= new int [n];
	}

	//marking array
	bool**vis=new bool*[n];
	for(int i=0;i<n;i++)
	{
		vis[i]= new bool [n]();//initialiing array elements with 0
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>arr[i][j];

	}
	if(arr[n-1][n-1]==1)
		cout<<0;
		else
		{	ratinmaze(arr,vis,0,0,n);
			cout<<result; }
	
	return 0;
}