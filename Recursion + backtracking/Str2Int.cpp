#include <iostream>
using namespace std;
 
void s2i(string str, int x)
{
	if(str.size()==0)
	{
		cout<<x;
		return;
	}

	int ch = int(str[0] - '0');
	string ros = str.substr(1);
	s2i(ros,x*10+ch);
}


 int main()
 {
 	string str;
 	cin>>str;
 	if(str[0]!='-')
 	s2i(str,0);
 	else 
 	{
 		cout<<"-";
 		s2i(str.substr(1),0);
 	}
 	return 0;
 }