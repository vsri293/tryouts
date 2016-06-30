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
		int arr[n];
		for (int i = 0 ; i < n ; i++)
		{
			cin>>arr[i];
		}
		int prev = -1;
		int cnt = 0;
		for (int i = 0 ; i < n ; i++)
		{
			if (arr[i] == prev)
				cnt++;
			else
			{
				prev = arr[i];
				cnt = 0;
			}
			if (cnt == 2)
				break;
		}
		if (cnt >= 2)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}