#include <iostream>
using namespace std;

void print(string&str, int x, char c)
{
    int n = str.size() ;
    char ch=str[n-1];
    
    for(int i=n;i>x+1;i--)
    {
        str[i]=str[i-1];
    }
    str[x+1]=c;
    str+=ch;
}

string replace(string str)
{
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i]=='p' and str[i+1]=='i')
        {
            str[i]='3';
            str[i+1]='.';
            print(str,i+1,'1');
            print(str,i+2,'4');
        }
    }  
    return str;
}

int main() 
{
    int n;
    cin>>n;
    string str[n],s[n];
    for(int i=0; i<n; i++)
    {
        
    cin>>str[i];
    s[i]=replace(str[i]);
    cout<<s[i]<<endl;
    }
    return 0;
}
