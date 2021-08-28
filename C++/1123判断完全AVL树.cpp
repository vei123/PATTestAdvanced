#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define nan 0x7fffffff
using namespace std;
//PAT1066和PAT1110的结合，模板题
struct node
{
	int val, height;
	node* left;
	node* right;
	node(int val) :val(val), height(1), left(0), right(0) {  }
};

int getheight(node* root)
{
	if (!root) return 0;
	else return root->height;
}

int getfactor(node* root)
{
	return getheight(root->left) - getheight(root->right);
}

void updateheight(node* root)
{
	root->height = 1 + max(getheight(root->left), getheight(root->right));
}

void LRotate(node*& root)
{
	node* t = root->right;
	root->right = t->left;
	t->left = root;
	updateheight(root);
	updateheight(t);
	root = t;
}

void RRotate(node*& root)
{
	node* t = root->left;
	root->left = t->right;
	t->right = root;
	updateheight(root);
	updateheight(t);
	root = t;
}

void insert(node*& root, int x)
{
	if (!root)
	{
		root = new node(x);
		return;
	}
	if (x < root->val)
	{
		insert(root->left, x);
		updateheight(root);
		if (getfactor(root) == 2)
		{
			if (getfactor(root->left) == 1) RRotate(root);
			else if (getfactor(root->left) == -1)
			{
				LRotate(root->left);
				RRotate(root);
			}
		}
	}
	else
	{
		insert(root->right, x);
		updateheight(root);
		if (getfactor(root) == -2)
		{
			if (getfactor(root->right) == -1) LRotate(root);
			else if (getfactor(root->right) == 1)
			{
				RRotate(root->right);
				LRotate(root);
			}
		}
	}
}

int n, t;
node* r;
vector<int> levelorder;

bool iscompleteBST(node* c)
{
	if (!c) return 1;
	bool mode = 0, yes = 1;
	queue<node*> q;
	q.push(c);
	while (!q.empty())
	{
		int len = q.size();
		for (int i = 0; i < len; i++)
		{
			c = q.front();
			q.pop();
			if (c->val != nan) levelorder.emplace_back(c->val);
			if (!mode)
			{
				if (c->val == nan) mode = 1;
			}
			else
			{
				if (c->val != nan) yes = 0;
			}
			if (c->left) q.push(c->left);
			else if (!mode) q.push(new node(nan));
			if (c->right) q.push(c->right);
			else if (!mode) q.push(new node(nan));
		}
	}
	return yes;
}

void printresult()
{
	for (int i = 0; i < levelorder.size(); i++)
	{
		if (i) cout << ' ';
		cout << levelorder[i];
	}
	cout << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	while (n--)
	{
		cin >> t;
		insert(r, t);
	}
	if (iscompleteBST(r))
	{
		printresult();
		cout << "YES";
	}
	else
	{
		printresult();
		cout << "NO";
	}
	return 0;
}
