#include<iostream>

using namespace std;

long long int gcd(long long int x, long long int y)
{
	if (y == 0)
		return x;
	else
		return gcd(y, x%y);
}

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		long long int n,c;
		cin>>n;
		cin>>c;
		
		long long int s = (2*c);
		if (s%n == 0)
		{
			
		}
		else
			cout<<"No"<<endl;
	}
	return 0;
}