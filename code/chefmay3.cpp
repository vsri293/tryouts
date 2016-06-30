#include<iostream>
using namespace std;
long long int mod = 1000000000000000007;
int main()
{
	int n;
	cin>>n;
	long long int w,l;
	cin>>w;
	cin>>l;
	long long int h[n],r[n],maxi = 0;
	for (int i = 0 ; i < n ; i++)
	{
		cin>>h[i];
		cin>>r[i];
		if (maxi < r[i]){
			maxi = r[i];
		}
	}

	long long int lo = 0,hi ,mid,prev=-1;
	hi = mod;
	hi = hi+5;
	int cnt = 0;
	while (lo < hi)
	{
		mid = (lo+hi)/2;
	
		long long int curr_wood=0,curr_val=0;
		for (int i = 0 ; i < n ; i++)
		{
			curr_val = h[i] + r[i]*mid;
			if (curr_val >= l)
				curr_wood += curr_val;
			if (curr_wood >= w)
				break;
		}
		if (curr_wood >= w)
			hi = mid;
		else
			lo = mid+1;
	}

	cout<<lo<<endl;

	return 0;
}