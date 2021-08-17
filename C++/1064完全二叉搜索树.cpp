#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int n, a[1005];
vector<int> res;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(0), right(0) {  }
	TreeNode(int val) :val(val), left(0), right(0) {  }
};

TreeNode* buildtree(int l, int r)
{
	TreeNode* t = 0;
	if (l > r) return t;
	int m, x, d = (int)log2(r - l + 1);
	//最后一层结点数
	x = r - l + 2 - (int)pow(2, d);
	if (x >= (int)pow(2, d) / 2)
		m = l + (int)pow(2, d) - 1;
	else
		m = l + ((int)pow(2, d) - 2) / 2 + x;
	t = new TreeNode(a[m]);
	t->left = buildtree(l, m - 1);
	t->right = buildtree(m + 1, r);
	return t;
}

void levelordertraversal(TreeNode* t)
{
	if (!t) return;
	TreeNode* cur;
	queue<TreeNode*> q;
	q.push(t);
	while (q.size())
	{
		int len = q.size();
		while (len--)
		{
			cur = q.front();
			q.pop();
			res.push_back(cur->val);
			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	levelordertraversal(buildtree(0, n - 1));
	for (int i = 0; i < res.size(); i++)
	{
		if (i) cout << ' ';
		cout << res[i];
	}
	return 0;
}
