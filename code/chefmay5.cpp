#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

map<long int, long int> mp[10][50],ms;
long int mod = 1000000007;
int cnt;
long int arr[100];
	
long long int solve(long int x, long int k,int st)
{
	//cout<<x<<" "<<k<<" "<<st<<endl;
	if (k==1)
	{
		if (x >= arr[st])
			return ms[x];
		else
			return 0;
		
	}
	if (x < 0 || k <= 0)
	{
		return 0;
	}
	long long int ans1 = 0,ans=1;
	for (int i = st ; i < cnt ; i++)
	{
		ans = 1;
		if (mp[k-1][i].count(x-arr[i]) > 0){
			ans = (ans * mp[k-1][i][x-arr[i]])%mod;
		}
		else{
			mp[k-1][i][x-arr[i]] = solve(x-arr[i],k-1,i)%mod;
			ans = (ans * mp[k-1][i][x-arr[i]])%mod;
		}
		// ans = (ans * solve(x-arr[i],k-1,i))%mod;
		ans1 = (ans1+ans)%mod;
	}
	//cout<<x<<" "<<k<<" "<<st<<" "<<ans1<<endl;
	return ans1;
}

int main()
{
	arr[0] = 1;
	arr[1] = 2;
	mp[0][0][arr[0]] = 1;
	mp[0][1][arr[1]] = 1;
	ms[arr[0]]=1;
	ms[arr[1]]=1;
	cnt = 2;
	while (1)
	{	
		arr[cnt] = arr[cnt-1] + arr[cnt-2];
		mp[0][cnt][arr[cnt]] = 1;
		ms[arr[cnt]] = 1;
		if (arr[cnt] > mod)
			break;
		cnt++;
	}
	
	int t;
	cin>>t;

	while (t--)
	{
		long int x;
		long int k;
		cin>>x;
		cin>>k;		
		// for (int i = 1 ; i<10 ; i++)
		// 	mp[i].clear();
		cout<<solve(x,k,0)<<endl;
	}

	return 0;
}