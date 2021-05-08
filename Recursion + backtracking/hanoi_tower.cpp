#include <iostream>
using namespace  std;

void hanoi(int n, char s, char d, char h)
{
	if(n==0)
		return;

	hanoi(n-1,s,h,d);
	cout<<"Moving ring "<<n<<" from "<<s<<" to "<<d<<endl;
	hanoi(n-1,h,d,s);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	hanoi(n,'A','B','C');
	return 0;
}