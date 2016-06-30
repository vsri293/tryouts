#include<stdio.h>
#include<iostream>

using namespace std;
 
int main()
{
	long long int n,k;

	cin>>n;
	cin>>k;
	long long int arr[n],ans=-1,prev,curr,ans1,ind1;
	for (int i = 0 ; i < n ; i++)
		cin>>arr[i];

	for (int i = 0 ; i <= n+1 ; i++)
	{
		curr = i * (i+1);
		curr = curr/2;
		if (k < curr){
			ans = i-1;
			break;
		}

		prev = curr;
	}

	ans1 = ans*(ans+1);
	ans1 = ans1/2;
	//cout<<ans<<" "<<ans<<endl;
	ind1 = k-ans1;
	//cout<<ind1<<endl;
	if (ind1 > 0)
	{
		cout<<arr[ind1-1]<<endl;
	}

	else if(ind1 == 0)
	{
		cout<<arr[ans-1]<<endl;
	}

	return 0;


}