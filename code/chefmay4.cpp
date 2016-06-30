#include<iostream>
using namespace std;
long long int mod = 1000000007;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n,m,s;
		cin>>n;
		cin>>m;
		cin>>s;
		int pass[m];
		for (int i = 0 ; i < m; i++)
		{
			cin>>pass[i];
		}
		long long int dp[n+1][m+1];
		for (int i = 0 ; i <= n ; i++)
			for (int j = 0 ; j <= m ; j++)
				dp[i][j] = 0;
		dp[s][0]=1;
		for (int i = 0 ; i < m ; i++)
		{
			int pv = pass[i];
			//cout<<i<<" "<<pv<<endl;
			for (int j = 0 ; j < n ; j++)
			{
				int dog1,dog2,dog_curr;
				long long int val = 0;
				dog_curr = j+1;
				dog1 = dog_curr-pv;
				dog2 = dog_curr+pv;
				//cout<<j<<" "<<dog1<<" "<<dog2<<endl;
				if (dog1 > 0 && dog1 < n+1)
				{
					val = dp[dog1][i]%mod;
				}
				if (dog2 > 0 && dog2 < n+1)
				{
					val = (val + (dp[dog2][i]%mod))%mod;
				}

				dp[dog_curr][i+1] = (dp[dog_curr][i+1] + val)%mod;
			}
		}

		for (int i = 0 ; i < n ; i++)
			cout<<dp[i+1][m]<<" ";
		cout<<endl;

	}
	return 0;
}