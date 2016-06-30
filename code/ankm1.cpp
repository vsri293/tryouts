#include<iostream>
using namespace std;

long long int large_infipower(long long int x)
{
	int arr[20];
	int cnt = 19;
	for (int i = 0 ; i < 20 ; i++)
		arr[i] = 0;
	while(x)
	{
		int y = x%10;
		arr[cnt] = y;
		x = x/10;
		cnt--;
		//cout<<y<<" ";
	}
	//cout<<endl;
	for (int i = 0 ; i < 20 ; i++)
	{
		int y = arr[i];
		//cout<<i<<" "<<y<<endl;
		if (arr[i] % 2 == 1)
		{
			if (arr[i] == 9)
			{
				for (int j = i ; j < 20 ; j++)
					arr[j] = 0;
				for (int j = i-1 ; j >= 0 ; j--)
				{
					if (arr[j] == 8)
						continue;
					else 
						arr[j] = arr[j]+2;
				}
			}
			else
			{
				for (int j = i+1 ; j < 20 ; j++)
					arr[j] = 0;
				arr[i] = arr[i]+1;
			}
			break;
		}
	}
	int f = 0;
	long long int num = 0;
	for (int i = 0 ; i < 20 ; i++)
	{
		if (arr[i] != 0)
			f = 1;
		if (f==1)
		{
			num = num*10 + arr[i];
		}
	}
	return num;
}

long long int small_infipower(long long int x)
{
	int arr[20];
	int cnt = 19;
	for (int i = 0 ; i < 20 ; i++)
		arr[i] = 0;
	while(x)
	{
		int y = x%10;
		arr[cnt] = y;
		x = x/10;
		cnt--;
		//cout<<y<<" ";
	}
	//cout<<endl;
	for (int i = 0 ; i < 20 ; i++)
	{
		int y = arr[i];
		//cout<<i<<" "<<y<<endl;
		if (arr[i] % 2 == 1)
		{
			
			{
				for (int j = i+1 ; j < 20 ; j++)
					arr[j] = 8;
				arr[i] = arr[i]-1;
			}

			break;
		}
	}
	int f = 0;
	long long int num = 0;
	for (int i = 0 ; i < 20 ; i++)
	{
		if (arr[i] != 0)
			f = 1;
		if (f==1)
		{
			num = num*10 + arr[i];
		}
	}
	return num;
}

long long int gcd(long long int a,long long int b)
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
		long long int n,num,deno;
		cin>>n;
		num = large_infipower(n) - n;
		deno = n - small_infipower(n);
		cout<<large_infipower(n)<<" "<<small_infipower(n)<<endl;

		if (n == small_infipower(n))
		{
			cout<<"Unlimited Power"<<endl;
		}
		else
		{
			long long int x;
			x = gcd(num,deno);
			cout<<num/x<<"/"<<deno/x<<endl;
		}
	}
	return 0;
}