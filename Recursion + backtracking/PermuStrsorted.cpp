#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

void sortString(string &str) 
{ 
   sort(str.begin(), str.end()); 

} 
void recper(string str, string osf)
{	if (str.size()==0)
	{   
        cout<<osf<<endl;
		return; }

		bool arr[26]={0};
	for(int i=0; i<str.size(); i++)
{	
	char ch=str[i];
	if(arr[ch-'A']==false)
	{
		arr[ch-'A']=true;
		string ros = str.substr(0,i)+str.substr(i+1,str.size());
		recper(ros,osf+ch);
}	}
}

int main()
{
	string str;
	cin>>str;
	sortString(str);
    recper(str,"");
    

	return 0;
}