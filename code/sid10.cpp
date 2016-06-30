#include<iostream>
#include<vector>
using namespace std;

int get_parent(int par[],int x)
{
	if (par[x] == -1)
		return x;
	else if (par[par[x]] == -1)
		return get_parent(par,par[x]);
	else
		return get_parent(par, par[par[x]]);
}

int zombieCluster(vector<string> zombies)
{
	int n = zombies.size();
	int par[n];
	int size[n];
	for (int i = 0 ; i < n ; i++)
	{
		par[i]=-1;
		size[i]=1;
	}
	int cnt = 0;
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = i+1 ; j < n ;j++)
		{
			int x = zombies[i][j]-'0';
			if (x==1)
			{
				if (par[i] == -1 && par[j] == -1)
				{
					par[j] = i;
					size[i]++;
				}
				else if(par[i] == -1)
				{
					int x = get_parent(par,j);
					par[i] = x;
					size[x]++;
				}
				else if (par[j] == -1)
				{
					int x = get_parent(par,i);
					par[j] = x;
					size[x]++;
				}
				else
				{
					int x = get_parent(par,i);
					int y = get_parent(par,j);
					if (size[x] > size[y])
					{
						par[y] = x;
						size[x]++;
					}
					else
					{
						par[x] = y;
						size[y]++;
					}
				}
			}
		}
	}
	for (int i = 0 ; i < n ; i++)
	{
		if (par[i] == -1)
			cnt++;
	}

	return cnt;
	
}
int main()
{
	int n;
	cin>>n;
	vector<string> zombies;
	string str;
	for (int i = 0 ; i < n ; i++)
	{
		cin>>str;
		zombies.push_back(str);
	}
	cout<<zombieCluster(zombies)<<endl;
	return 0;
}