#include<iostream>
#include<queue>
#include<unordered_set>
#include<unordered_map>
using namespace std;

struct node
{
	int val, level;
	node* left;
	node* right;
	node* parent;
	node(int val) :val(val), level(-1), left(0), right(0), parent(0) {  }
};

int n, m, u, v, in[10005], pre[10005];
unordered_set<int> allkeys;
unordered_map<int, int> indexof;
unordered_map<int, node*> nodeof;
node* root;

node* buildtree(int il, int ir, int pl, int pr)
{
	node* t = 0;
	if (il > ir) return t;
	t = new node(pre[pl]);
	if (il == ir) return t;
	int k = indexof[pre[pl]];
	t->left = buildtree(il, k - 1, pl + 1, pl + k - il);
	if (t->left) t->left->parent = t;
	t->right = buildtree(k + 1, ir, pl + k - il + 1, pr);
	if (t->right) t->right->parent = t;
	return t;
}

void preprocess()
{
	if (!root) return;
	node* t;
	queue<node*> q;
	q.push(root);
	int level = 0;
	while (!q.empty())
	{
		int len = q.size();
		while (len--)
		{
			t = q.front();
			q.pop();
			t->level = level;
			nodeof[t->val] = t;
			if (t->left) q.push(t->left);
			if (t->right) q.push(t->right);
		}
		level++;
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> in[i];
		indexof[in[i]] = i;
		allkeys.insert(in[i]);
	}
	for (int i = 0; i < n; i++) cin >> pre[i];
	root = buildtree(0, n - 1, 0, n - 1);
	preprocess();
	while (m--)
	{
		cin >> u >> v;
		if (!allkeys.count(u) && !allkeys.count(v))
			cout << "ERROR: " << u << " and " << v << " are not found.\n";
		else if (!allkeys.count(u))
			cout << "ERROR: " << u << " is not found.\n";
		else if (!allkeys.count(v))
			cout << "ERROR: " << v << " is not found.\n";
		else
		{
			node* nu = nodeof[u], *nv = nodeof[v];
			int lu = nu->level, lv = nv->level;
			while (nu->val != nv->val)
			{
				if (lu < lv)
				{
					nv = nv->parent;
					lv--;
				}
				else if (lu > lv)
				{
					nu = nu->parent;
					lu--;
				}
				else
				{
					nu = nu->parent, nv = nv->parent;
					lu--, lv--;
				}
			}
			if (nu->val == u)
				cout << u << " is an ancestor of " << v << ".\n";
			else if (nv->val == v)
				cout << v << " is an ancestor of " << u << ".\n";
			else
				cout << "LCA of " << u << " and " << v << " is " << nu->val << ".\n";
		}
	}
	return 0;
}
