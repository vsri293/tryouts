#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		string str1,str2;
		cin>>str1;
		cin>>str2;
		int len1,len2;
		len1 = str1.length();
		len2 = str2.length();
		int arr[26];
		int flag = 0;
		for (int i = 0 ; i < 26 ; i++)
			arr[i] = 0;

		for (int i = 0 ; i < len1 ; i++)
		{
			char c;
			c = str1[i];
			arr[c-'a'] = 1;
		}
		for (int i = 0 ; i < len2 ; i++)
		{
			char c;
			c = str2[i];
			if (arr[c-'a'] == 1)
				flag = 1;
		}

		if (flag == 1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}