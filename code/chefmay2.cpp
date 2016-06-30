#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int x;
	int arr[5];
	
	for (int i = 0 ; i < 5 ; i++)
		arr[i] = i+1;
		
	cout<<1<<endl;
	fflush(stdout);
	cout<<3<<" "<<1<<" "<<1<<" "<<2<<endl;
	fflush(stdout);
	cout<<3<<" "<<3<<" "<<3<<" "<<4<<endl;
	fflush(stdout);
	cin>>x;
	if (x == 0)
	{
		cout<<2<<endl;
		fflush(stdout);
		cout<<5<<endl;
		fflush(stdout);
	}
	else if (x > 0) 
	{
		if (x==1)
		{
			cout<<2<<endl;
			fflush(stdout);
			cout<<2<<endl;
			fflush(stdout);
		}
		else {
			cout<<2<<endl;
			fflush(stdout);
			cout<<1<<endl;
			fflush(stdout);
		}
	}
	else
	{
		x = -x;
		if (x==1)
		{
			cout<<2<<endl;
			fflush(stdout);
			cout<<4<<endl;
			fflush(stdout);
		}
		else {
			cout<<2<<endl;
			fflush(stdout);
			cout<<3<<endl;
			fflush(stdout);
		}
	}
	return 0;
} 
