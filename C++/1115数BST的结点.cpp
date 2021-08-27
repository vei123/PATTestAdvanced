#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node
{
	int val;
	node* left;
	node* right;
	node(int val) :val(val), left(0), right(0) {  }
};

int n, key, n1 = 0, n2 = 0;
node* r;
vector<int> level;

void insert(node*& c, int key)
{
	if (key <= c->val)
	{
		if (c->left) insert(c->left, key);
		else c->left = new node(key);
	}
	else
	{
		if (c->right) insert(c->right, key);
		else c->right = new node(key);
	}
}

void levelordertraversal(node* c)
{
	if (!c) return;
	node* t = c;
	queue<node*> q;
	q.push(t);
	while (!q.empty())
	{
		int len = q.size();
		level.emplace_back(len);
		while (len--)
		{
			c = q.front();
			q.pop();
			if (c->left) q.push(c->left);
			if (c->right) q.push(c->right);
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> key;
		if (i) insert(r, key);
		else r = new node(key);
	}
	levelordertraversal(r);
	if (level.size()) n1 = level.back();
	if (level.size() > 1) n2 = level[(int)level.size() - 2];
	cout << n1 << " + " << n2 << " = " << n1 + n2;
	return 0;
}
