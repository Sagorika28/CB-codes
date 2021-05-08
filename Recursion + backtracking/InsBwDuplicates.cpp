#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void print(string&str, int x)
{
    int n = str.size() ;
    char ch=str[n-1];
    
    for(int i=n;i>x+1;i--)
    {
        str[i]=str[i-1];
    }
    str[x+1]='*';
    str+=ch;
}

void dupi (string&str, int x)
{
    if(str[x]=='\0')
    {
        return;
    }

    else if (str[x]==str[x+1])
    {   
        print(str,x);
    }

    dupi(str,x+1);
}

int main() 
{
    string s;
    cin>>s;
    int x=0;
    dupi(s,x);
    cout<<s;
}
