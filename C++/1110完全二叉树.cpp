#include<iostream>
#include<string>
#include<queue>
using namespace std;
/*
完全二叉树的充要条件：按照层序遍历，任何两个结点之间没有空结点
所以人为地为二叉树创建一些空结点助于判断
*/
struct node
{
	int val;
	node* left;
	node* right;
	node() : val(0), left(0), right(0) {  }
	node(int val) :val(val), left(0), right(0) {  }
};

int n, root, notroot[20] = { 0 };
node* s[20];
queue<node*> q;
vector<node*> v;

bool iscompletebinarytree(node* c)
{
	if (!c) return 1;
	bool mode = 0, res = 1;
	queue<node*> q;
	q.push(c);
	while (!q.empty())
	{
		int len = q.size();
		while (len--)
		{
			c = q.front();
			q.pop();
			v.emplace_back(c);
			if (!mode)
			{
				if (c->val < 0) mode = 1;
			}
			else
			{
				if (c->val >= 0) res = 0;
			}
			if (c->left) q.push(c->left);
			else if(!mode) q.push(new node(-1));
			if (c->right) q.push(c->right);
			else if(!mode) q.push(new node(-1));
		}
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		if (!s[i]) s[i] = new node(i);
		string sl, sr;
		cin >> sl >> sr;
		if (sl[0] != '-')
		{
			int l = stoi(sl);
			if (!s[l]) s[l] = new node(l);
			s[i]->left = s[l];
			notroot[l] = 1;
		}
		if (sr[0] != '-')
		{
			int r = stoi(sr);
			if (!s[r]) s[r] = new node(r);
			s[i]->right = s[r];
			notroot[r] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (!notroot[i])
		{
			root = i;
			break;
		}
	}
	if (iscompletebinarytree(s[root]))
	{
		cout << "YES ";
		for (int i = v.size() - 1; i >= 0; i--)
		{
			if (v[i]->val >= 0)
			{
				cout << v[i]->val;
				return 0;
			}
		}
	}
	else cout << "NO " << root;
	return 0;
}
