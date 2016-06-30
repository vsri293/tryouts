#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;
int main()
{
	vector <string> str;
	string str1;
	for (int i = 0 ; i < 5 ; i++)
	{
		cin>>str1;
		str.push_back(str1);
	}

	int n;
	n = str.size();
	string tmp = str[0];
	int m;
	m = tmp.length(); 
	int arr[n+1][m+1];
	int stroke1=0,stroke2=0;
	for (int i = 0 ; i < n ; i++)
	{
		tmp = str[i];
		char c;
		for (int j = 0 ; j < m ; j++)
		{
			c = tmp[j];

			if (c == 'B')
			{
				arr[i][j] = 1;
				if (i == 0)
				{
					stroke1++;
				}
				else
				{
					if (arr[i-1][j] == 2 || arr[i-1][j] == 0)
					{
						stroke1++;
					}	
				}
			}
			else if (c == 'G')
			{
				arr[i][j] = 3;
				if (i == 0)
				{
					stroke1++;
				}
				else
				{
					if (arr[i-1][j] == 1 || arr[i-1][j] == 3)
					{
						//stroke1++;
					}	
					else if (arr[i-1][j] == 2 || arr[i-1][j] == 0)
					{
						stroke1++;
					}
				}
				if (j == 0)
				{
						stroke2++;
				}
				else
				{
						if(arr[i][j-1] == 2 || arr[i][j-1] == 3)
						{

							//stroke2++;
						}
						else if (arr[i][j-1] == 1 || arr[i][j-1] == 0)
						{
							stroke2++;
						}
				}
			}
			else if (c == 'R')
			{
				arr[i][j] = 2;
				if (j == 0)
				{
					stroke2++;
				}
				else
				{
					if (arr[i][j-1] == 1 || arr[i][j-1] == 0)
					{
						stroke2++;
					}	
				}
			}
			else
			{
				arr[i][j] = 0;
			}
		}
	}

	cout<<stroke1+stroke2<<endl;
	//return stroke1+stroke2;
	return 0;

}