#include<iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		long long int arr[n];
		long long int dp[2][n+1];
		int f = 0;
		long long int am;
		for (int i = 0 ; i < n ; i++)
		{
			cin>>arr[i];
			if (i==0)
				am = arr[i];
			dp[0][i] = 0;
			dp[1][i] = 0;
			if (arr[i] >= 0)
			{
				f = 1;
			}
			am = max (am,arr[i]);
		}
		if (f==0)
		{
			cout<<am<<endl;
			continue;
		}
		dp[0][n] = 0;  	// 0 - one number ignored
		dp[1][n] = 0;	// 1 - no ignore yet
		long long int val,ans=arr[0];
		for (int i = 0 ; i < n ; i++)
		{
			if (arr[i] >= 0)
			{
				dp[0][i+1] = dp[0][i] + arr[i];
				dp[1][i+1] = max(dp[1][i] + arr[i], arr[i]);
			}
			else
			{
				dp[0][i+1] = max (dp[0][i] + arr[i], dp[1][i]);
				dp[1][i+1] = max(dp[1][i] + arr[i], arr[i]);
			}
			val = max (dp[0][i+1], dp[1][i+1]);
			if (val > ans)
				ans = val;
		}
		cout<<ans<<endl;
	}
}