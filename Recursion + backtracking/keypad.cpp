#include<iostream>
using namespace std;

char table[][10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void keys(char*in, char*out, int i, int j)
{
	if(in[i]=='\0')
		{	out[j]='\0';
			cout<<out<<endl;
			return;
		}

	int digit = in[i] - '0';

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
	return 0;
}