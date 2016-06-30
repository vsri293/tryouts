#include<iostream>
using namespace std;


int check(int arr[], int st, int end)
{
	int root = arr[st];
	int f = 1;
	if (st >= end)
		return f;
	if (arr[st+1] >= arr[st])
	{
		for (int i = st+1 ; i <= end ; i++)
		{
			if (arr[i] < arr[st])
				f = 0;
		}
		f = f*check(arr, st+1, end);
	}
	else
	{	
		int left_end=end;
		for (int i = st+1 ; i <= end ; i++)
		{
			if (arr[i] > arr[st])
			{
				left_end = i-1;
				break;
			}	

		}
		for (int i = left_end+1 ; i <= end ; i++)
		{
			if (arr[i] < arr[st])
				f = 0;
		}
		if (f == 0)
			return f;
		
		int left_check = check(arr,st+1, left_end);
		int right_check = check(arr, left_end+1, end);
		f = left_check*right_check;
		
		return f;
	}
	return f;
}

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
		cout<<check (arr,0 ,n-1)<<endl;
	}
}