#include<iostream>
#include<vector>
using namespace std;

void add_arr(vector<int> &arr, int pos, int cntr, int &prev)
{
	while (cntr--)
	{		
		arr.insert(arr.begin()+pos, prev);
		prev++;
		pos++;
	}
}


void print(vector<int> v)
{
	for (int i = 0 ; i < v.size() ; i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	cout<<"---------"<<endl;
}


void make_arr(vector<int> &arr, int k)
{
	int cnt = 0,cntr=0;
	int num = k;
	int nump = 1;
	int rem;
	int bit[20];
	for (int i = 0 ; i < 20 ; i++)
		bit[i] = -1;
	while (num)
	{
		bit[cnt++] = num%2;
		nump = nump*2;
		num = num/2;
	}
	nump = nump/2;
	rem = k-nump;
	int prev = 1;
	int lislen = 0;
	while (nump>1)
	{
		arr.push_back(prev+1);
		arr.push_back(prev);
		prev += 2;
		nump = nump/2;
		lislen++;
		//cout<<nump<<endl;
	}
	//cout<<prev<<" "<<lislen<<endl;
	//print(arr);
	int chg = 0,pos=0;
	for (int i = 0 ; i < cnt-1 ; i++)
	{
		//cout<<i<<" "<<bit[i]<<endl;
		if (bit[i] == 1)
		{
			int x = i,grt=0,req;
			req = lislen-x;
			for (int j = i+1 ; j < cnt-1 ; j++){
				if (bit[j] == 1)
				{
					grt += lislen-j;
					break;
				}
			}
			pos = 2*x;
			cntr = req-grt;
			//cout<<cntr<<" "<<req<<" "<<grt<<endl;
			add_arr(arr, pos+chg, cntr, prev);
			chg += cntr;
		}
	}
	//print(arr);
}

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int k;
		cin>>k;
		vector<int> arr;
		if (k==1)
			arr.push_back(1);
		else
			make_arr(arr,k);

		cout<<arr.size()<<endl;
		for (int i = 0 ; i < arr.size() ; i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	return 0;
}