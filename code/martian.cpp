#include<iostream>
using namespace std;

int main()
{
	while (1)
	{
		int n,m;
		cin>>n;
		cin>>m;
		if (n==0 && m==0)
			break;
		for (int i = 0 ; i < n ; i++)
		{
			for (int j = 0 ; j < m ; j++)
				cin>>a[i][j];	//yeni
		}

		for (int i = 0 ; i < n ; i++)
		{
			for (int j = 0 ; j < m ; j++)
				cin>>b[i][j];	//blog
		}
		long long int dp2[n+1][m+1],dp1[m+1][n+1],ans[n+1][m+1];

		for (int i = 0 ; i <= n ; i++)
			for (int j = 0 ; j <= m ; j++)
			{	
				dp2[i][j]=0;
				dp1[j][i]=0;
				ans[i][j]=0;
			}

		for (int i = 1 ; i <= n ; i++)
		{
			long int cnt_tmp = 0;
			for (int j = 0 ; j <= m ; j++)
			{
				if (j>0){
					cnt_tmp+=b[i-1][j-1];
				}
				dp2[i][j]=cnt_tmp;
			}
		}

		for (int j = 1 ; j <= m ; j++)
		{
			long int cnt_tmp=0;
			for (int i = 0 ; i <= n ; i++)
			{
				if (i>0){
					cnt_tmp+=a[i-1][j-1];
				}
				dp1[j][i]=cnt_tmp;
			}
		}

		for(int i = 1 ; i <= n ; i++)
		{
			long int ans1,ans2;
			for (int j = 1 ; j <= m ; j++)
			{
				ans1 = dp1[j][i] + ans[i][j-1];
				ans2 = dp2[i][j] + ans[i-1][j];
				if (ans1 > ans2)
					ans[i][j] = ans1;
				else
					ans[i][j] = ans2;
			}
		}
		cout<<ans[n][m]<<endl;
	}
	return 0;
}