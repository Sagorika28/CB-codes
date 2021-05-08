#include <iostream>
using namespace std;
void lex(int n, int x)
{	
	
	if (x>n)
		return;

	else if (x==n)
	{
		cout<<x<<endl;
		return;
	}

	else 
	{
		cout<<x<<endl;
		for (int i = ((x==0)?1:0); i <= 9; ++i)
		{
			lex(n,10*x+i);
		}
	}
}

int main ()
{
	int x=0, n;
	cin>>n;
	lex(n,x);
	return 0;
}