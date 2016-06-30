# include <iostream>
# include <vector>
# include <cstdlib>
using namespace std;

struct node
{
	int info;
	struct node *left;
	struct node *right;
	vector<int> l;
}*root;


class TRIE
{
	public:
		void insert(node *root,int x[],int ind);
		void set_root();
		void print(node *root);
		int search_xor(node *root , int l , int r , int x[]);
		int found(int x,int l,int r,vector<int> tmp);

		TRIE()
		{
			root = NULL;
		}
};


int main()
{
	TRIE trie;
	int n,q;
	cin>>n;
	cin>>q;
	trie.set_root();
	int arr[n];
	for (int j = 0 ; j < n ; j++)
	{
		int num;
		cin>>num;
		arr[j] = num;
		int x[21];
		for (int i = 0 ; i < 21 ; i++)
		{
			x[i] = 0;
		}
		int tmp = num;
		int cnt = 20;
		while (1)
		{
			if (tmp%2 == 0)
				x[cnt] = 0;
			else
				x[cnt] = 1;
			tmp = tmp/2;
			if (tmp == 0)
				break;
			cnt--;
		}
		trie.insert(root,x,j+1);
		//trie.print(root);
	}

	while (q--)
	{
		int l,r;
		int num;
		cin>>l;
		cin>>r;
		cin>>num;

		int x[21];
		for (int i = 0 ; i < 21 ; i++)
		{
			x[i] = 0;
		}
		int tmp = num;
		int cnt = 20;
		while (1)
		{
			if (tmp%2 == 0)
				x[cnt] = 0;
			else
				x[cnt] = 1;
			tmp = tmp/2;
			if (tmp == 0)
				break;
			cnt--;
		}
		int ans;
		ans = trie.search_xor(root,l,r,x);
		cout<<(arr[ans-1]^num)<<endl;
	}
}

void TRIE::set_root()
{
	if (root == NULL)
	{
		//cout<<"YEs"<<endl;
		root = new node;
		root->info = 9;
		root->left = NULL;
		root->right = NULL;		
	}
}

void TRIE::insert(node *tree,int x[],int ind)
{
	for (int i = 0 ; i < 21 ; i++)
	{
		int tmp;
		tmp = x[i];
		node *temp;
		//cout<<tree->info<<" ";
		if (tmp == 0)
		{
			if (tree->left == NULL)
			{
				//cout<<"left "<<endl;
				temp = new node;
				temp->info = tmp;
				temp->left = NULL;
				temp->right = NULL;
				tree->left = temp;
			}
			tree = tree->left;
			tree->l.push_back(ind);
			//v<int>::iterator it;
			/*for (it = tree->l.begin() ; it != tree->l.end() ; it++)
				cout<<*it<<" ";
			
			cout<<endl;
			*/
		}
		else
		{
			if (tree->right == NULL)
			{
				//cout<<"right " <<endl; 
				temp = new node;
				temp->info = tmp;
				temp->left = NULL;
				temp->right = NULL;
				tree->right = temp;
			}
			tree = tree->right;
			tree->l.push_back(ind);
			//list<int>::iterator it;
			/*for (it = tree->l.begin() ; it != tree->l.end() ; it++)
				cout<<*it<<" ";

			cout<<endl;
			*/
		}
	}
}

void TRIE::print(node *tree)
{
	if (tree == NULL)
	{
		cout<<"empty"<<" ";
	}
	else
	{
		cout<<tree->info<<" ";

		print(tree->left);
		print(tree->right);
		cout<<endl;
	}
}

int TRIE::search_xor(node *tree,int l,int r,int x[])
{
	for (int i = 0 ; i < 21 ; i++)
	{
		int tmp;
		//cout<<x[i]<<" ";
		tmp = 1-x[i];
		
		//cout<<tmp<<" ";
		//cout<<tree->info<<" ";
		if (tmp == 0)
		{
			if (tree->left == NULL || found(tmp,l,r,tree->l))
			{

				tree = tree->right;
				if (tree == NULL)
				{
					//cout<<"not found";
					return 0;
				}
			}
			else
				tree = tree->left;
		}
		else
		{
			if (tree->right == NULL || found(tmp,l,r,tree->right->l))
			{
				tree = tree->left;
				if (tree == NULL)
				{
					//cout<<"not found";
					return 0;
				}
			}
			else
				tree = tree->right;			
		}
	}
	vector<int>::iterator it;
	int tmp;
	for (it = tree->l.begin() ; it != tree->l.end() ; it++)
		tmp = (*it);

	return tmp;
	//cout<<endl;
}

int TRIE::found(int x,int l,int r,vector<int> tmp)
{
	vector<int>::iterator it;
	for (it = tmp.begin() ; it != tmp.end() ; it++)
		if ((*it) >= l && (*it) <= r)
			return 0;

	return 1;
}


