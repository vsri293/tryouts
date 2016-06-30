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
		string str;
		cin>>str;
		int dp[n+5][n+5];
		int ans = 0;

		for (int i = 0 ; i < n+1 ; i++)
		{
			for (int j = 0 ; j < n+1 ; j++)
			{
				if (i == 0 || j == 0)
					dp[i][j] = 0;
				else if(str[i-1] == str[j-1])
					dp[i][j] = dp[i-1][j-1]+1;
				else
					dp[i][j] = 0;
			}
		}

		for (int i = 0 ; i < n+1 ; i++)
		{
			for (int j = i+1; j < n+1 ; j++)
			{
				int x;
				if (j-i > dp[i][j])
					x = dp[i][j];
				else 
					x = j-i;

				if (ans < x)
					ans = x;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}