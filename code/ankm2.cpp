#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	int arr1[n];
	for (int j = 0 ; j < n ; j++)
	{
		cin>>arr[j];
	}
	sort(arr,arr+n);
	int cnt1=0,cnt2=n-1;
	long long int diff1=0,diff2=0;
	int i = 0;
	while(cnt1 < cnt2)
	{
		arr1[i] = arr[cnt1];
		arr1[i+1] = arr[cnt2];
		//cout<<arr1[i]<<" "<<arr1[i+1]<<endl;
		cnt1++;
		cnt2--;
		i+=2;
	}
	//cout<<cnt1<<" "<<cnt2<<" "<<i<<endl;
	if (cnt1 == cnt2)
	{
		
		arr1[i] = arr[cnt1];
		//cout<<x<<endl;
	}
	diff1 = 0;
	for(int i = 1 ; i < n ; i++)
	{
		long long int x;
		x = arr1[i] - arr1[i-1];
		if (x < 0)
			x = -x;
		diff1 += x;
	}
	//cout<<diff1<<endl;
	cnt1 = 0,cnt2 = n-1;
	i = 0;
	//int i=0;
	diff2=0;
	while (cnt1 < cnt2)
	{
		arr1[i] = arr[cnt2];
		arr1[i+1] = arr[cnt1];
		cnt1++;
		cnt2--;
		i+=2;
	}
	if (cnt1 == cnt2)
	{
		arr1[i] = arr[cnt1];
	}
	for(int i = 1 ; i < n ; i++)
	{
		long long int x;
		x = arr1[i] - arr1[i-1];
		if (x < 0)
			x = -x;
		diff2 += x;
	}
	cout<<max(diff1,diff2)<<endl;
	return 0;
}