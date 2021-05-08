#include <iostream>
#include <string>
using namespace std;

char strings[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void code(string str, string osf)
{
	if (str.size()==0) //base case
	{	
		cout<<osf<<endl;
		return; }

	if (str.size()==1)
	{
		int ch = str[0] - '0';
		code(str.substr(1),osf + strings[ch-1]);
	}
	else
	{
		int one = str[0]-'0';
		int t=str[1]-'0';
		int two = one*10 + t;
		code(str.substr(1),osf+strings[one-1]);
		if (two<=26)
		{
			code(str.substr(2),osf+strings[two-1]);
		}
	}

}

int main()
{
	string str;
	cin>>str;
	fflush(stdin);
	code(str,"");
	return 0;

}