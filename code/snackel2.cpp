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
		char c;
		string ans="";
		for (int i = 0 ; i < n ; i++)
		{
			c = i%26 + 'a';
			ans+=c;
		}
		cout<<ans<<endl;
	}
}