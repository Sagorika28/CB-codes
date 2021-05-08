#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;
void recsub(string str, string osf)
{
	if (str.size()==0)
	{	cout<<osf<<" ";
		return; }

	char ch=str[0];
	string ros = str.substr(1);
	recsub(ros,osf+ch);
	recsub(ros,osf);

}

int main()
{
	string str;
	cin>>str;
    int n=str.size();
	//fflush(stdin);
	cout<<" ";
	recsub(str,"");
    cout<<endl<<pow(2,n);

	return 0;
}
