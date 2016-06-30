#include <iostream>

using namespace std;

long long int gcd(long long int a, long long int b)
{
	if (a == 0)
		return b;
	else
		return gcd(b%a, a);
}

int main()
{
	int t;
	cin>>t;
	long long int dp[10][10][19],tmp, sum[10], cnt = 1, rcnt[19]; //dp[secret digit][starting digit][length]
	for (int i = 0 ; i < 10 ; i++)
		sum[i] = 0;
	rcnt[0] = 0;
	for (int k = 1 ; k < 19 ; k++)
	{	
		rcnt[k] = 0;
		for (int i = 0 ; i <= 9 ; i++) //Secret digit
		{
			
			tmp = 0;
			for (int j = 0 ; j <= 9 ; j++) //Start
			{
				if (i==j)
				{
					dp[i][j][k] = cnt+sum[i];
				}
				else
				{
					dp[i][j][k] = sum[i];
				}
				if (i == 0)
				{
					if (j==0)
					{
						rcnt[k] += rcnt[k-1];
					}
					else
					{
						rcnt[k] += dp[i][j][k];
					}
				}
				tmp += dp[i][j][k];
			}
			sum[i] = tmp;		
		}
		cnt = 10*cnt;
	}

	// for (int k = 1 ; k < 3 ; k++)
	// {
	// 	for (int i = 0 ; i <= 9 ; i++) //Secret digit
	// 	{
	// 		for (int j = 0 ; j <= 9 ; j++) //Start
	// 		{
	// 			cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
	// 		}
	// 		cout<<"-----"<<endl;
	// 	}
	// 	cout<<"========"<<endl;
	// }
	while (t--)
	{
		string str;
		cin>>str;
		int len = str.length();
		long long int ans[10],vis[10];
		long long int tot_sum = 0;
		long long int nume,deno=0;
		if (len == 1)
		{
			tot_sum = str[0] - '0';
			nume = tot_sum;
			deno = tot_sum*10;
			cout<<"1/10"<<endl;
		}
		else{
		for (int i = 0 ; i < 10 ; i++)
		{
			ans[i] = 0;
			vis[i] = 0;
		}
		int x = str[0]-'0';
		int len1 = len;
		long long int num;
		ans[0] += rcnt[len1-1];
		deno = deno*10 +x;
		for (int k = 1 ; k < x ; k++)
		{
			ans[0] += dp[0][k][len1];
		}
		for (int j = 1 ; j < 10 ; j++)
		{
			for (int k = 0 ; k < x ; k++)
			{
				ans[j] += dp[j][k][len1];
			}
		}
		int st;
		num = 0;
		st = 1;
		for (int ind = st ; ind < len ; ind++)
		{
			num = num*10 + (str[ind]-'0' + 1);
		}
		ans[x] += num;
		vis[x] = 1;
		for (int i = 0 ; i < 10 ; i++)
		{
			cout<<i<<" "<<ans[i]<<endl;
		}
		for (int i = 1 ; i < len ; i++)
		{
			x = str[i]-'0';
			len1 = len-i;
			deno = deno*10 +x;
			for (int j = 0 ; j < 10 ; j++)
			{
				for (int k = 0 ; k < x ; k++)
				{
					if (vis[j] == 0)
						ans[j] += dp[j][k][len1];
				}
			}
			num = 0;
			st = i+1;
			for (int ind = st ; ind < len ; ind++)
			{
				num = num*10 + (str[ind]-'0' + 1);
			}
			if (vis[x] == 0){
				ans[x] += num;
				vis[x] = 1;
			}
		}
		for (int i = 0 ; i < 10 ; i++)
		{
			cout<<i<<" "<<ans[i]<<endl;
		}
		for (int i = 0 ; i < 10 ; i++)
		{
			tot_sum += ans[i];
			
		}
		nume = tot_sum;
		long long int gc = gcd(nume,10*deno);
		cout<<nume/gc<<"/"<<(10*deno)/gc<<endl;
		}

		//cout<<tot_sum<<endl;
	}
	return 0;
}