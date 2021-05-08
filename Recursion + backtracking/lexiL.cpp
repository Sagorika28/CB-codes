#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void sort(string &str)
{
    sort(str.begin(),str.end());
}

void lexw(string str,string osf, string s)
{
	if(str.size()==0 && osf>s)
	{
		cout<<osf<<endl;
		return;
	}

	bool vis[26]={0};

	for (int i = 0; i < str.size(); ++i)
	{
		char ch = str[i];
		if(vis[ch - 'a']==false)
		{
			string ros = str.substr(0,i)+str.substr(i+1,str.size());
			lexw(ros,osf+ch,s);
			vis[ch-'a']=true;
		}
	}
}

void lexn(string str,string osf, string s)
{
	if(str.size()==0 && osf>s)
	{
		cout<<osf<<endl;
		return;
	}

	bool vis[26]={0};

	for (int i = 0; i < str.size(); ++i)
	{
		char ch = str[i];
		if(vis[ch - '0']==false)
		{
			string ros = str.substr(0,i)+str.substr(i+1,str.size());
			lexn(ros,osf+ch,s);
			vis[ch-'0']=true;
		}
	}
}

int main()
{
	string str,s;
	cin>>str;
	s=str;
    sort(str);
    if(isalpha(str[0]))
		lexw(str,"",s);
	else
		lexn(str,"",s);
	return 0;
}