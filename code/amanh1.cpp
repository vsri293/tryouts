#include <iostream>
using namespace std;

long long int lpow(int num, long long int powr)
{
	int ans = 1;
	while (powr--)
	{
		ans = ans * num;
	}
	return (ans%10);
}

long long int func(long long int x, long long int p)
{
	if (p == 0)
		return 1;
	if (x == 0 || x == 1 || x == 5 || x == 6)
		return x;
	if (x == 2 || x == 3 || x == 4 || x == 7 || x == 8 || x == 9) 
	{
		long long int y = p%4;
		if (y==0)
			y = 4;
		return lpow(x, y);
	}
	return 1;
}

int main()
{
	int t;
	cin>>t;

	while (t--)
	{
		long long int m;
		int k;
		cin>>m;
		cin>>k;
		string str;
		long long int ans = 0;
		for (int i = 0 ; i < k ; i++)
		{
			cin>>str;
			int len = str.length();
			long long int mul = 1;
			for (int i = 0 ; i < len ; i++)
			{
				char c = str[i];
				long long int x = c;
				long long int dig = x%10;
				mul = mul*func(dig , m);
				mul = mul%10;
				//cout<<c<<" "<<mul<<endl;
			}
			ans = ans + mul;
		}
		if (ans % 2 == 0)
			cout<<"EVEN"<<endl;
		else
			cout<<"ODD"<<endl;
	}
	return 0;
}