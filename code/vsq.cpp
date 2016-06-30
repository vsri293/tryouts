#include<iostream>
#include<algorithm>
using namespace std;

int bs1(long long int arr[],long long int x,int len)
{
	int lo = 0;
	int hi = len;
	int mid;
	cout<<"here"<<endl;
	while (lo<hi)
	{
		mid = (lo+hi)/2;
		cout<<mid<<" "<<arr[mid]<<endl;
		if (arr[mid] >= x)
			hi = mid;
		else
			lo = mid+1;

		cout<<lo;
	}
	return hi;
}
int bs2(long long int arr[],long long int x,int len)
{
	int lo = 0;
	int hi = len;
	int mid;
	while (lo<hi)
	{
		mid = (lo+hi)/2;
		if (arr[mid] <= x)
			lo = mid;
		else
			hi = mid;
		cout<<lo;
	}
	return lo;
}
int main()
{
	int n;
	cin>>n;
	long long int arr[n];
	for (int i = 0 ; i < n ; i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	cout<<"here"<<endl;
	int q;
	cin>>q;
	for (int i = 0 ; i < q ; i++)
	{
		long long int a,b;
		int ind1,ind2;
		cin>>a;
		cin>>b;
		ind1 = bs1(arr,a,n);
		cout<<"here1"<<endl;
		ind2 = bs2(arr,b,n);
		cout<<ind1<<" "<<ind2<<endl;
		cout<<n-ind1-ind2<<endl;
	}

}