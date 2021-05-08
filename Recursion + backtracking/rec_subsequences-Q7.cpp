#include <iostream>
#include <cstring> 
#include <stdlib.h>

using namespace std;
string recsub(string str, string osf)
{
	if (str.size()==0)
	{	cout<<osf<<endl<<num;
		return; }
	
	char ch=str[0];
	string ros = str.substr(1);
	int num=recsub(ros,osf+ch)+recsub(ros,osf);
	
}

int main()
{
	string str;
	cin>>str;
	fflush(stdin);
	
	recsub(str,"");
	
	return 0;
}