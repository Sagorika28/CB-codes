#include <iostream>
using namespace std;

void endx(string str, string osf, string csf, int pos)
{
    if(pos==str.size())
    {
        cout<<osf+csf;
        return;
    }
    if(str[pos]=='x')
    {
        endx(str,osf,csf+'x',pos+1);
    }
    else
    endx (str,osf+str[pos],csf,pos+1);

return;
}

int main() 
{
    string str;
    cin>>str;
    endx(str,"","",0);
    return 0;
}
