#include <iostream>
#include <string>
#include <math.h>
#include <stack>
#include <stdlib.h>

using namespace std;

bool balanced(string str)
{
	stack <char> st;
	int n=str.size();

	for(int i=0; i<n; i++)
	{
		if(str[i]=='(')
			st.push(str[i]);

		else if(str[i]==')')
		{
			if(st.empty())
				return false;
			st.pop();
		}
	}
	return st.empty();
}


void recper(string str, string osf)
{	if (str.size()==0)
	{	if(balanced(osf))
        cout<<osf<<endl;
		return; }

		bool arr[2]={0};
	for(int i=0; i<str.size(); i++)
{	
	char ch=str[i];
	if(arr[ch-'(']==false)
	{
		arr[ch-'(']=true;
		string ros = str.substr(0,i)+str.substr(i+1,str.size());
		recper(ros,osf+ch);
	}
}
}

int main()
{
	int n;
    cin>>n;
    string str;
    for(int i=0;i<2*n;i+=2)
    {
        str= str+'('+')';
        
    }
    str[2*n] = '\0';
	
	recper(str,"");
    

	return 0;
}
