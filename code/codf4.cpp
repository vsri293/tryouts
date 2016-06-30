#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;
 
int main()
{
	int n;
	long long int k;
	cin>>n;
	cin>>k;
	long long int a[n],b[n];
	for (int i = 0 ; i < n ; i++)
	{
		cin>>a[i];
	}
	for (int i = 0 ; i < n ; i++)
	{
		cin>>b[i];
	}

	long long int ans,lo,hi,mid;
	lo = 0;
	hi = 2000000005;
	//cout<<lo<<" "<<hi<<endl;
	while (hi- lo >1)
	{
		mid = (lo+hi)/2;
		long long int tmp_k;
		tmp_k = k;
		//cout<<mid<<endl;
		for (int i = 0 ; i < n ; i++)
		{
			long long int need;
			need = mid*a[i];
			if (need < b[i])
				continue;
			else if(need > b[i])
			{
				tmp_k = tmp_k-(need-b[i]);
			}

			if (tmp_k < 0)
				break;
		}

		if(tmp_k < 0)
			hi = mid;
		else
			lo = mid;
	}

	cout<<lo<<endl;


	return 0;
}