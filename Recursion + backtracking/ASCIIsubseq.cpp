#include <iostream>
#include <string> 
#include <stdlib.h>
using namespace std;
void recsub(string str, string osf)
{
	if (str.size()==0)
	{	
		cout<<osf<<endl;
		return; }
	
	char ch=str[0];
	string ros = str.substr(1);
	recsub(ros,osf+ch);
	recsub(ros,osf);
	recsub(ros,osf+ to_string ((int)ch));
	
}

int main()
{
	string str;
	cin>>str;
	// cout<<str;
	fflush(stdin);
	recsub(str,"");
	
	return 0;
}