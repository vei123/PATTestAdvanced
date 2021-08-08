#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int val) :val(val), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(int* a, int* b, int al, int ar, int bl, int br)
{
	if (al > ar) return nullptr;
	TreeNode* root = new TreeNode(a[ar]);
	int p = -1;
	for (int i = 0; i <= br - bl; i++)
	{
		if (b[i + bl] == a[ar])
		{
			p = i;
			break;
		}
	}
	root->left = 
		buildTree(a, b, al, al + p - 1, bl, bl + p - 1);
	root->right = 
		buildTree(a, b, al + p, ar - 1, bl + p + 1, br);
	return root;
}

void levelorderTraversal(TreeNode* root)
{
	if (!root) return;
	TreeNode* cur;
	vector<int> res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		int len = q.size();
		for (int i = 0; i < len; i++)
		{
			cur = q.front();
			q.pop();
			res.push_back(cur->val);
			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
		}
	}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
		if (i != res.size() - 1) cout << ' ';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	int n, t;
	int a[35], b[35];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)	cin >> b[i];
	levelorderTraversal(buildTree(a, b, 0, n - 1, 0, n - 1));
	return 0;
}
