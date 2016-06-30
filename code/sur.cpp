#include <iostream>
using namespace std;

int main()
{
	double surge;
	for (int i = 1 ; i < 11 ; i++)
	{
		for (int j = i ; j < 11 ; j++)
		{
			surge = 3*(j-i)*j;
			surge = surge/9;
			surge = surge/(i+j);
			// surge = (j-i);
			// surge = surge/i;
			cout<<"cars "<<i<<" users "<<j<<" surge "<<surge<<endl;
		}
		cout<<endl;
	}
	return 0;
}