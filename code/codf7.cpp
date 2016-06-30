#include <stdio.h>
#include <iostream>
#include <string> 

using namespace std;
 
int possible(int remlen, int origlenlen, int cnt[], string str, string substr)
{
	string sremlen = to_string(remlen);
	int flag = 0;
	//cout<<sremlen<<endl;

	for (int i = 0 ; i < sremlen.length() ; i++)
	{
		char c;
		c = sremlen[i];
		origlenlen--;
		
		int x = c-'0';

		if (cnt[x] <= 0){
			flag = 1;
			break;
		}
		else
			cnt[x]--;
	}

	if (flag == 1)
		return -1;

	if (origlenlen != 0)
		return -1;

	return 1;
}

string call_func(int i, int cnt[])
{
	string ans = "";
	char c = i +'0';
	//cout<<cnt[i]<<endl;
	while (1)
	{
		if (cnt[i] == 0)
			break;
		cnt[i]--;
		//cout<<cnt[i]<<" "<<i<<" "<<ans<<endl;
		ans = ans + c;
		
	}

	//cout<<ans<<endl;
	return ans;
}

int inc_substr(string substr)
{
	int len = substr.length();
	int prev = substr[0]-'0';
	int flag = 0;
	for (int i = 1 ; i < len ; i++)
	{
		char c;
		c = substr[i];
		int x = c-'0';

		if (x > prev)
		{
			flag = 1;
			break;
		}
		else if (x < prev)
		{
			flag = 0;
			break;
		}
		else
			prev = x;
	}

	return flag;
} 

int main()
{
	string str;
	cin>>str;
	int len = str.length();
	string substr;
	cin>>substr;
	int slen = substr.length();
	int cnt[10];

	for (int i = 0 ; i < 10 ; i++)
		cnt[i] = 0;

	for (int i = 0 ; i < len ; i++)
	{
		char c;
		c = str[i];
		int x;
		x = c-'0';
		cnt[x]++;
		//cout<<x<<" "<<cnt[x]<<endl;
	}

	for (int i = 0 ; i < slen ; i++)
	{
		char c;
		c = substr[i];
		int x;
		x = c-'0';
		cnt[x]--;
	}
	int origlen;
	for (int i = 6 ; i > 0 ; i--)
	{
		int origlenlen = i;
		int remlen = len-origlenlen;
		int x;
		//cout<<remlen<<endl;
		int tcnt[10];
		for (int i = 0 ; i < 10 ; i++)
			tcnt[i] = cnt[i];
		x = possible(remlen, origlenlen, tcnt, str, substr);
		//cout<<i<<" "<<x<<endl;
		if (x == 1)
		{
			while(remlen)
			{
				int rx = remlen%10;
				remlen = remlen/10;

				cnt[rx]--;
			}
			break;
		}

	}
	string ans = "";
		char c;
		c = substr[0];
		int x = c-'0';
		//cout<<x<<endl;
		if (x==0)
		{
			for (int i = 1 ; i < 10 ; i++)
			{
				char c;
				c = i+'0';
				if (cnt[i] > 0)
				{
					ans = ans + c;
					cnt[i]--;
					break;
				}
			}

			if (inc_substr(substr))
			{
				ans = ans + call_func(x, cnt);
				ans = ans + substr;
			}
			else
			{
				ans = ans + substr;
				ans = ans + call_func(x, cnt);
			}
			//cout<<i<<" "<<ans<<endl;
			
			for (int i = x+1 ; i < 10 ; i++)
			{
				ans = ans + call_func(i, cnt);
			}
			//cout<<i<<" "<<ans<<endl;
		}
		else{
			int anslen = 0;
			for (int i = 0 ; i < x ; i++)
			{
				if (anslen==0){
				for (int i = 1 ; i < 10 ; i++)
				{
					char c;
					c = i+'0';
					if (cnt[i] > 0)
					{
						ans = ans + c;
						cnt[i]--;
						anslen = 1;
						break;

					}
				}
				
				}
				//cout<<i<<" "<<cnt[i]<<endl;
				if (anslen == 1)
					ans = ans + call_func(i, cnt);
				else
					x = 0;
			}
			//cout<<i<<" "<<ans<<endl;
			if (inc_substr(substr))
			{
				ans = ans + call_func(x, cnt);
				ans = ans + substr;
			}
			else
			{
				ans = ans + substr;
				ans = ans + call_func(x, cnt);
			}
			//cout<<i<<" "<<ans<<endl;
			
			for (int i = x+1 ; i < 10 ; i++)
			{
				ans = ans + call_func(i, cnt);
			}
			//cout<<i<<" "<<ans<<endl;
		}

	cout<<ans<<endl;

	return 0;
}