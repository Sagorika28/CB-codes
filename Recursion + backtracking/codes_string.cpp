#include <iostream>
#include <string>
using namespace std;

void code(string str, string osf)
{
	if (str.size()==0) //base case
	{	
		cout<<osf<<endl;
		return; }

	if (str.size()==1)
	{
		int ch = str[0] - '0';
		code(str.substr(1),osf + (char) (96+ch));
	}
	else
	{
		int one = str[0]-'0';
		int two = stoi(str.substr(0,2));
		if (two<=26)
		{
			code(str.substr(2),osf+(char) (96+two));
		}
		code(str.substr(1),osf+(char) (96+one));
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