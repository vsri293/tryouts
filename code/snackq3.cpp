#include<iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		string str;
		cin>>str;
		int k;
		cin>>k;
		int len = str.length();
		int arr[30],mx = len;
		for (int i = 0 ; i < 30 ; i++)
			arr[i] = 0;
		for (int i = 0 ; i < len ; i++)
		{
			char c;
			c = str[i];
			int x = c-'a';
			arr[x]++;

		}
		long long int ans=len+1,score,diff;
		for (int i = 0 ; i < 30 ; i++)
		{
			score = 0;
			if (arr[i] > 0) 
			{
				//cout<<"i- "<<i<<" "<<arr[i]<<endl;
				for (int j = 0 ; j < 30 ; j++)
				{
					if (arr[j] > 0)
					{
						//cout<<"j- "<<j<<" "<<arr[j]<<endl;
						if (arr[j] >= arr[i])
						{
							diff = arr[j] - arr[i];
							if (diff > k)
							{
								score += diff-k;
							}
						}
						else
						{
							score += arr[j];
						}
						//cout<<score<<endl;
					}
				}

				if (ans > score)
				{
					ans = score;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}