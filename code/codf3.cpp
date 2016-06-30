#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;
 
int main()
{
	long long int n,k,m;
	cin>>n;
	long long int a[n];
	map<long long int,long long int> mp;
	map<long long int, int> mpi;
	for (int i = 0 ; i < n ; i++){
		cin>>a[i];
		if (mp.count(a[i]) == 0)
			mp[a[i]] = 1;
		else
			mp[a[i]] = mp[a[i]]+1;
	}
	cin>>m;
	long long int b[m],c[m],score0[m],score1[m],maxs=0;
	for (int i = 0 ; i < m ; i++)
	{
		cin>>b[i];
		score0[i] = mp[b[i]];
		if (score0[maxs] < score0[i])
			maxs = i;
	}
	for (int i = 0 ; i < m ; i++)
	{
		cin>>c[i];
		score1[i] = mp[c[i]];
	}

	for (int i = 0 ; i < m ; i++)
	{
		if (score0[i] == score0[maxs])
		{
			if (score1[i] > score1[maxs])
				maxs = i;
		}	
	}
	cout<<maxs+1<<endl;
	return 0;


}