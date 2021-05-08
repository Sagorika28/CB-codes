#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
    cin>>str;
	int arr[26]={0};
 	for (int i = 0; i < str.size(); ++i)
 	{
 		char ch=str[i];
 		arr[ch-'a']++;
 	}
 	int pos=0,max=0;
 	for (int i = 0; i < 26; ++i)
 	{
 		if(arr[i]>max)
 			{
 				max=arr[i];
 				pos=i;
 			}
 	}
 	cout<<pos<<endl;
     cout<<str[pos];
	return 0;
}