#include <iostream>

using namespace std;

int mp(int cr, int cc, int  er, int ec, string osf)
{
	if (cr==er and cc==ec)
	{
		cout<<osf<<endl;
		return 1;
	}
	if(cr>er or cc>ec)
	{
		return 0;
	}
	int hval = mp(cr, cc+1, er, ec, osf+"H");
	int vval = mp(cr+1, cc, er, ec, osf+"V");
	return hval+vval;
}

int main()
{  	int cr,cc,er,ec;
	cin>>cr>>cc>>er>>ec;
	cout<<mp(cr,cc,er,ec,"");
	return 0;
}