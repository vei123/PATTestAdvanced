#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//用二维数组存储层序遍历结果，然后根据索引的奇偶选择正序或倒序
struct node
{
	int val;
	node* left;
	node* right;
	node(int val) :val(val), left(0), right(0) {  }
};

int n, in[35], post[35];
node* root;
vector<vector<int>> v;
vector<int> res;

node* buildtree(int il, int ir, int pl, int pr)
{
	if (il > ir) return 0;
	if (il == ir) return new node(in[il]);
	int j = il;
	while (in[j] != post[pr]) j++;
	node* t = new node(in[j]);
	t->left = buildtree(il, j - 1, pl, pl + (j - il) - 1);
	t->right = buildtree(j + 1, ir, pl + (j - il), pr - 1);
	return t;
}

void levelordertraversal(node* c)
{
	if (!c) return;
	queue<node*> q;
	q.push(c);
	while (!q.empty())
	{
		v.emplace_back(vector<int>());
		int len = q.size();
		while (len--)
		{
			c = q.front();
			q.pop();
			v.back().emplace_back(c->val);
			if (c->left) q.push(c->left);
			if (c->right) q.push(c->right);
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> in[i];
	for (int i = 0; i < n; i++) cin >> post[i];
	root = buildtree(0, n - 1, 0, n - 1);
	levelordertraversal(root);
	for (int i = 0; i < v.size(); i++)
	{
		if (!(i & 1)) reverse(v[i].begin(), v[i].end());
		for (int j = 0; j < v[i].size(); j++) res.emplace_back(v[i][j]);
	}
	for (int i = 0; i < res.size(); i++)
	{
		if (i) cout << ' ';
		cout << res[i];
	}
	return 0;
}
