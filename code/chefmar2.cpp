#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		long long int k;
		cin>>n;
		cin>>k;
		long long int a[n+1],b[n+1],sum,maxa,maxb,f = 0;
		sum = 0;
		for (int i = 0 ; i < n ; i++)
		{
			cin>>a[i];
		}
		for (int i = 0 ; i < n ; i++)
		{
			cin>>b[i];
			sum += a[i]*b[i];
			if (a[i] > 0 && b[i] < 0)
			{
				b[i] = -b[i];
			}
			else if (a[i] < 0 && b[i] < 0)
			{
				a[i] = -a[i];
				b[i] = -b[i];
			}
			long long int tmp;
			tmp = b[i];
			if (f== 0)
			{
				f = 1;
				maxb = b[i];
				maxa = a[i];
			}
			else if (maxb < tmp)
			{
				maxb = tmp;
				maxa = a[i];
			}
			
		}
		if (f == 1)
			sum += maxb*k;
			
		cout<<sum<<endl;
	}
	return 0;
}