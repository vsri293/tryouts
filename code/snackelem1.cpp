#include<iostream>
#include<algorithm>
using namespace std;


int possible(long long int fst, long long int scd, long long int r, long long int c)
{
	if (r <= 0 || c <= 0)
		return 0;

	if (fst%c==0)
	{
		long long int row_taken = fst/c;
		long long int row_rem = r-row_taken;
		if (row_rem*c == scd)
			return 1;
	}
	if (fst%r==0)
	{
		long long int col_taken = fst/r;
		long long int col_rem = c-col_taken;
		if (col_rem*r == scd)
			return 1;
	}
	return 0;
}
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		long long int r,c,m,k,j;
		cin>>r;
		cin>>c;
		long long int parts[3];
		cin>>parts[0];
		cin>>parts[1];
		cin>>parts[2];
		long long int area = r*c;
		sort(parts,parts+3);
		long long int fst = parts[2];
		if (fst%c==0)
		{
			long long int row_taken = fst/c;
			long long int row_rem = r-row_taken;
			if (possible(parts[0], parts[1], row_rem, c)){
				cout<<"Yes"<<endl;
				continue;
			}
		}
		if (fst%r==0)
		{
			long long int col_taken = fst/r;
			long long int col_rem = c-col_taken;
			if (possible(parts[0], parts[1], col_rem, r)){
				cout<<"Yes"<<endl;
				continue;
			}
		}
		fst = parts[1];
		if (fst%c==0)
		{
			long long int row_taken = fst/c;
			long long int row_rem = r-row_taken;
			if (possible(parts[2], parts[0], row_rem, c)){
				cout<<"Yes"<<endl;
				continue;
			}
		}
		if (fst%r==0)
		{
			long long int col_taken = fst/r;
			long long int col_rem = c-col_taken;
			if (possible(parts[2], parts[0], col_rem, r)){
				cout<<"Yes"<<endl;
				continue;
			}
		}
		fst = parts[0];
		if (fst%c==0)
		{
			long long int row_taken = fst/c;
			long long int row_rem = r-row_taken;
			if (possible(parts[2], parts[1], row_rem, c)){
				cout<<"Yes"<<endl;
				continue;
			}
		}
		if (fst%r==0)
		{
			long long int col_taken = fst/r;
			long long int col_rem = c-col_taken;
			if (possible(parts[2], parts[1], col_rem, r)){
				cout<<"Yes"<<endl;
				continue;
			}
		}

		cout<<"No"<<endl;
	}	
}