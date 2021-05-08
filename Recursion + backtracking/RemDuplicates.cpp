#include <iostream>
#include <stdio.h>
using namespace std;

void dupr (char* str)
{
    if(str[0]=='\0')
    {
        return;
    }

    else if (str[0]==str[1])
    {   int i=0;
        while(str[i]!='\0')
        {
            str[i]=str[i+1];
            i++;
        }
        dupr(str);

    }

    else
    dupr(str+1);
}

int main() 
{
    char s[1000];
    cin>>s;
    dupr(s);
    cout<<s;
}
