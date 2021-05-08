#include <iostream>
#include <cmath>
using namespace std;

bool safe(int **mat, int i, int j, int n, int num)
{
	for(int x=0; x<n ; x++)
	{
		if(mat[x][j]==num or mat[i][x]==num)
			return false;
	}

	int rn=sqrt(n);
	int sx=(i/rn)*rn;
	int sy=(j/rn)*rn;

	for(int x=sx; x<sx+rn; x++)
	{
		for (int y = sy; y < sy+rn; ++y)
		{
			if(mat[x][y]==num)
				return false;
		}
	}
return true;
}

bool sudoku(int **mat, int i, int j, int n)
{
	if(i==n)
	{
		//print mat
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}

	if(j==n)
	{
		return sudoku(mat,i+1,0,n);
	}


	if (mat[i][j]!=0)
	 {
	 	return sudoku(mat,i,j+1,n);
	 } 

	for(int num=1; num<=n; num++)
	{
		if(safe(mat,i,j,n,num))
		{
			mat[i][j]=num;
			bool solved = sudoku(mat,i,j+1,n);
			if(solved==true)
				return true;
		}
	}

	//backtrack
	mat[i][j]=0;
	return false;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int **mat = new int*[n];
	for(int i=0; i<n; i++)
		mat[i]=new int [n];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>mat[i][j];
		}
	}
	sudoku(mat,0,0,n);
	return 0;
}