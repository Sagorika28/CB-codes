#include <iostream>
#include <stack>

using namespace std;

/*int atTop(){
		if(isempty()){
			cout<<"stack is empty"<<endl;
			return NULL;
		}
		
			return arr[top-1];
		
		
	}*/

void rev(int data[], int n)
{
	stack <int> st, sth;
	for (int i = 0; i < n; ++i)
	{
		st.push(data[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		cout<<st.top()<<endl;
	}
return;
}

int main(int argc, char const *argv[])
{
	int i, helper,n;
	cin>>n;
	int data[n];

	for (int i = 0; i < n; ++i)
	{
		cin>>data[i];
	}

	rev(data,n);
	return 0;
} 