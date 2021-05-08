#include<iostream>
using namespace std;
int count=0;

char table[][10] = {"abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wx", "yz" };

void keys(char*in, char*out, int i, int j)
{
	if(in[i]=='\0')
		{	out[j]='\0';
			cout<<out<<" ";
			count++;
			return;
		}

	int digit = (in[i] - '0')-1;

	for(int k=0; table[digit][k]!='\0'; k++)
	{
		out[j]=table[digit][k];
		keys(in,out,i+1,j+1);
}}

int main() 
{
	char in[100], out[100];
	cin>>in;
	keys(in,out,0,0);
	cout<<endl<<count;
	return 0;
}