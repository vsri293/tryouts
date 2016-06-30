#include<iostream>
using namespace std;

string chg_str(string str, int conv[],int curr)
{
	int len = str.length();
	int tmp[len];

	for (int i = 0 ; i < len ; i++)
	{
		char c = str[i];
		tmp[i] = c-'0';
		int x;
		x = c-'0';
		if (conv[x] > 0 && x >= curr)
		{
			tmp[i] = curr;
			conv[c-'0']--;
		}
	}
	for (int i = len-1 ; i >= 0 ; i--)
	{
		char c = str[i];
		int x;
		x = c-'0';
		if (conv[x] > 0 && x < curr)
		{
			tmp[i] = curr;
			conv[c-'0']--;
		}
	}
	string str1 = "";
	for (int i = 0 ; i < len ; i++)
	{
		char c;
		int x = tmp[i];
		c = x+'0';
		str1 += c;
	}
	return str1;
}

string cmp_str(string str1,string str2)
{
	int len = str1.length();

	for (int i = 0 ; i < len ; i++)
	{
		char b,c;
		b = str1[i];
		c = str2[i];
		int bx,cx;
		bx = b-'0';
		cx = c-'0';
		if (bx > cx)
			return str2;
		else if (bx < cx)
			return str1;
		else
			continue;
	}
	return str1;
}
int main()
{
	int n,k;
	cin>>n;
	cin>>k;
	string str;
	cin>>str;
	int len;
	len = str.length();
	int cnt[10];
	string num_min = "";
	int cost_min = len*10;
	for (int i = 0 ; i < 10 ; i++)
		cnt[i] = 0;
	for (int i = 0 ; i < len ; i++)
	{
		char c;
		c = str[i];
		cnt[c-'0']++;
		//cout<<c-'0'<<endl;
	}

	for (int i = 0 ; i < 10 ; i++)
	{
		int tmp;
		tmp = k;
		tmp = tmp-cnt[i];
		int cost = 0;
		int conv[10];
		//cout<<i<<" "<<"tmp"<<" "<<tmp<<endl;
		for (int j = 0 ; j < 10 ; j++)
		{
			conv[j] = 0;
		}
		for (int diff = 1 ; diff < 10 ; diff++)
		{
			if (tmp == 0)
				break;
			int fst,scd;
			fst = i+diff;
			scd = i-diff;
			//cout<<fst<<" "<<scd<<" "<<cnt[fst]<<" "<<cnt[scd]<<endl;
			if (fst > -1 && fst < 10)
			{
				if (tmp >= cnt[fst])
				{
					//cout<<tmp<<" "<<cnt[fst]<<" ";
					tmp = tmp-cnt[fst];
					conv[fst] += cnt[fst];
					cost += conv[fst]*diff;
					//cout<<conv[fst]<<endl;
				}
				else
				{
					conv[fst] += tmp;
					tmp = 0;
					cost += conv[fst]*diff;
				}
				
			}
			if (scd > -1 && scd < 10)
			{
				if (tmp >= cnt[scd])
				{
					tmp = tmp-cnt[scd];
					conv[scd] += cnt[scd];
					cost += conv[scd]*diff;
				}
				else
				{
					conv[scd] += tmp;
					tmp = 0;
					cost += conv[scd]*diff;
				}
			}
		}
		//for (int j = 0 ; j < 10 ; j++)
		//{
		//	cout<<j<<" "<<conv[j]<<endl;
		//}
		if (cost < cost_min && tmp == 0)
		{
			num_min = chg_str(str,conv,i);
			cost_min = cost;
		}
		else if (cost == cost_min && tmp == 0)
		{
			num_min = cmp_str(num_min,chg_str(str,conv,i));
		}
		//cout<<num_min<<" "<<cost_min<<endl;
	}
	cout<<cost_min<<endl;
	cout<<num_min<<endl;
	return 0;
}