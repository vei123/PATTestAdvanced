#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

struct node
{
	int val;
	node* left;
	node* right;
	node() :val(0), left(0), right(0) {  }
	node(int val) :val(val), left(0), right(0) {  }
};

int n, a[100];
node* s[105] = { 0 };
queue<node*> q;
queue<int> res;

void inordertraversal(node*& t)
{
	if (!t) return;
	node* cur = t;
	stack<node*> stk;
	while (cur || !stk.empty())
	{
		if (cur)
		{
			stk.push(cur);
			cur = cur->left;
		}
		else
		{
			cur = stk.top();
			stk.pop();
			q.push(cur);
			cur = cur->right;
		}
	}
}

void levelordertraversal(node* t)
{
	if (!t) return;
	queue<node*> que;
	que.push(t);
	while (!que.empty())
	{
		int len = que.size();
		while (len--)
		{
			t = que.front();
			que.pop();
			res.push(t->val);
			if (t->left) que.push(t->left);
			if (t->right) que.push(t->right);
		}
	}
	while (!res.empty())
	{
		cout << res.front();
		res.pop();
		if (!res.empty()) cout << ' ';
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		if(!s[i]) s[i] = new node();
		int l, r;
		cin >> l >> r;
		if (l != -1)
		{
			if (!s[l]) s[l] = new node();
			s[i]->left = s[l];
		}
		if (r != -1)
		{
			if (!s[r]) s[r] = new node();
			s[i]->right = s[r];
		}
	}
	inordertraversal(s[0]);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		q.front()->val = a[i];
		q.pop();
	}
	levelordertraversal(s[0]);
	return 0;
}
