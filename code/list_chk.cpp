#include <list>
#include <iostream>

using namespace std;

int main()
{
	list<int> l;
	list<int>::iterator it;


	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	
	for (it = l.begin() ; it != l.end() ; it++)
	{
		cout<<*it<<" ";
	}

	return 0;
}