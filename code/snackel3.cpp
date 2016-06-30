#include<iostream>

using namespace std;

long long int gcd(long long int a, long long int b)
{
	if (a == 0)
		return b;

	return gcd(b%a, a);
}

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		long long int a,b,c,d,x,diff,y;
		cin>>a;
		cin>>b;
		cin>>c;
		cin>>d;

		diff = b-a;
		if (diff < 0)
			diff = -diff;

		x = gcd(c,d);
		//cout<<x<<endl;
		y = diff%x;

		cout<<min(y,x-y)<<endl;
	}
	return 0;
}