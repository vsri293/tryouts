#include<iostream>
#include<list>
#include<math.h>
#include<vector>
#include <stdio.h>
using namespace std;


int DFS(list<int> l[], int st, int vis[])
{
	if (vis[st] == 1)
		return 0;
	vis[st] = 1;
	list<int>::iterator it;
	int cnt = 1;
	for (it = l[st].begin() ; it != l[st].end() ; it++)
	{
		if (vis[*it] == 0)
		{
			cnt += DFS(l, (*it), vis);
		}
	}
	return cnt;
}

int main()
{
	int n;
	cin>>n;
	vector<string> pairs;
	
	for (int i = 0 ; i < 5 ; i++)
	{
		string str;
		getline(cin,str);
		cout<<str<<endl;
		pairs.push_back(str);
	}

	int vis[n];
	for (int i = 0 ; i < n ; i++)
		vis[i] = 0;

	list<int> *l = new list<int>[n];
	for (int i = 0 ; i < pairs.size() ; i++)
	{
		// cout<<pairs[i]<<endl;
		string str = pairs[i];
		int len = str.length();
		int p=0,q=0;
		int f = 0;
		for (int j = 0 ; j < len ; j++)
		{
			char c;
			c = str[j];
			int x = c-'0';
			if (c == ' ')
			{
				f = 1;
				continue;
			}
			if (f == 0)
			{	
				p = p*10 + x;
			}
			else
			{
				q = q*10 + x;
			}
			// cou
		}
		l[p-1].push_back(q-1);
		l[q-1].push_back(p-1);
	}
	int score = 0;
	for (int i = 0 ; i < n ; i++)
	{
		if (!vis[i])
		{
			score += ceil(sqrt(DFS(l,i,vis)));
		}
	}
	return score;
	return 0;
}
