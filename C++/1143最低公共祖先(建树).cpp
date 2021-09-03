#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;
/*
建树方案，代码复杂度较高，容易出现细节错误，不推荐使用：
步骤：
一、根据输入数据，排序后获取中序遍历序列
二、根据前序、中序序列建树
三、层次遍历树结构，获取每一个节点的层次
四、根据层次大小关系向上递推直到两个结点值相等，这个结点就是共同祖先
关键点：
题目的前序序列中一定不会出现两个相同的节点值，因为这样可能答案会不唯一，
所以建树过程中可以对代码进行哈希优化，能够提升速度(从50、60ms提升到20、30ms这样)
*/
struct node
{
	int val, level;
	node* left;
	node* right;
	node* parent;
	node(int val) :val(val), level(-1), left(0), right(0), parent(0) {  }
};

int m, n, pre[10005], in[10005];
node* root;
unordered_set<int> allkeys;
unordered_map<int, node*> nodeof;

node* buildtree(int pl, int pr, int il, int ir)
{
	node* t = 0;
	if (pl > pr) return t;
	t = new node(pre[pl]);
	if (pl == pr) return t;
	int k = il;
	while (in[k] != pre[pl]) k++;
	t->left = buildtree(pl + 1, pl + k - il, il, k - 1);
	if (t->left) t->left->parent = t;
	t->right = buildtree(pl + k - il + 1, pr, k + 1, ir);
	if (t->right) t->right->parent = t;
	return t;
}

void getlevel()
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
		cin >> pre[i];
		in[i] = pre[i];
		allkeys.insert(pre[i]);
	}
	sort(in, in + n);
	root = buildtree(0, n - 1, 0, n - 1);
	getlevel();
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		if (!allkeys.count(u) && !allkeys.count(v))
			cout << "ERROR: " << u << " and " << v << " are not found.\n";
		else if (!allkeys.count(u))
			cout << "ERROR: " << u << " is not found.\n";
		else if (!allkeys.count(v))
			cout << "ERROR: " << v << " is not found.\n";
		else
		{
			node *nu = nodeof[u], *nv = nodeof[v];
			int lu = nu->level, lv = nv->level;
			while (nu->val != nv->val)
			{
				if (nu->val == nv->val) break;
				if (lu > lv)
				{
					lu--;
					nu = nu->parent;
				}
				else if (lu < lv)
				{
					lv--;
					nv = nv->parent;
				}
				else
				{
					lu--, lv--;
					nu = nu->parent, nv = nv->parent;
				}
			}
			if (nu == nodeof[u])
				cout << u << " is an ancestor of " << v << ".\n";
			else if (nv == nodeof[v])
				cout << v << " is an ancestor of " << u << ".\n";
			else
				cout << "LCA of " << u << " and " << v << " is " << nu->val << ".\n";
		}
	}
	return 0;
}
