#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int n;
int a[1005];

inline int max(int a, int b, int c)
{ return a > b ? (a > c ? a : c) : (b > c ? b : c); }

inline int min(int a, int b, int c)
{ return a < b ? (a < c ? a : c) : (b < c ? b : c); }

//树结点结构体
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(0), right(0) {  }
	TreeNode(int val) :val(val), left(0), right(0) {  }
};

//mode=1试图建立正常BST，mode=0试图建立镜像BST
TreeNode* buildtree(int* a, int l, int r, bool mode)
{
	if (l > r) return 0;
	TreeNode* t = new TreeNode(a[l]);
	int i = l + 1;
	if (mode) while (i <= r && a[i] < a[l]) i++;
	else while (i <= r && a[i] >= a[l]) i++;
	t->left = buildtree(a, l + 1, i - 1, mode);
	t->right = buildtree(a, i, r, mode);
	return t;
}

//获取某棵树最大结点值
int getmax(TreeNode* r)
{
	if (!r) return 0x80000000;
	int lx = getmax(r->left), rx = getmax(r->right);
	return max(lx, r->val, rx);
}

//获取某棵树最小节点值
int getmin(TreeNode* r)
{
	if (!r) return 0x7fffffff;
	int lx = getmin(r->left), rx = getmin(r->right);
	return min(lx, r->val, rx);
}

//判断是不是普通二叉搜索树
bool isBST(TreeNode* r)
{
	if (!r) return 1;
	if (r->left && getmax(r->left) >= r->val) return 0;
	if (r->right && getmin(r->right) < r->val) return 0;
	return isBST(r->left) && isBST(r->right);
}

//判断是不是镜像二叉搜索树
bool ismirrorBST(TreeNode* r)
{
	if (!r) return 1;
	if (r->left && getmin(r->left) < r->val) return 0;
	if (r->right && getmax(r->right) >= r->val) return 0;
	return ismirrorBST(r->left) && ismirrorBST(r->right);
}

//后序非递归遍历
void postordertraversal(TreeNode* r)
{
	if (!r) return;
	TreeNode* t;
	stack<TreeNode*> stk1, stk2;
	stk1.push(r);
	while (stk1.size())
	{
		t = stk1.top();
		stk1.pop();
		stk2.push(t);
		if (t->left) stk1.push(t->left);
		if (t->right) stk1.push(t->right);
	}
	while (stk2.size())
	{
		cout << stk2.top()->val;
		stk2.pop();
		if (stk2.size()) cout << ' ';
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	TreeNode* t1 = buildtree(a, 0, n - 1, 1);
	TreeNode* t2 = buildtree(a, 0, n - 1, 0);
	bool b1 = isBST(t1);
	bool b2 = ismirrorBST(t2);
	if (b1 || b2)
	{
		cout << "YES\n";
		if (b1) postordertraversal(t1);
		else postordertraversal(t2);
	}
	else cout << "NO";
	return 0;
}
