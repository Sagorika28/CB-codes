#include <iostream>
#include <ctype.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	int i=0;
	do
	{
		cout<<str[i];
		i++;
	}while(!(isupper(str[i])));
	int pos=i;
	for (int i = pos; i < str.size(); ++i)
	{
		if(isupper(str[i]))
			cout<<endl;
		cout<<str[i];
	}
	return 0;
}