#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode
{
	int val, height;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), height(1), left(0), right(0) {  }
	TreeNode(int val) : val(val), height(1), left(0), right(0) {  }
};

int getheight(TreeNode* root)
{
	if (!root) return 0;
	else return root->height;
}

int getfactor(TreeNode* root)
{
	return getheight(root->left) - getheight(root->right);
}

void updateheight(TreeNode* root)
{
	root->height = max(getheight(root->left), getheight(root->right)) + 1;
}

//注意由于根结点改变了，需要取引用，如果没有引用只会对拷贝的指针进行改变
void LRotate(TreeNode*& root)
{
	TreeNode* t = root->right;
	root->right = t->left;
	t->left = root;
	updateheight(root);
	updateheight(t);
	root = t;
}

void RRotate(TreeNode*& root)
{
	TreeNode* t = root->left;
	root->left = t->right;
	t->right = root;
	updateheight(root);
	updateheight(t);
	root = t;
}

//将x值插入到以root为根的平衡二叉树中
void insert(TreeNode*& root, int x)
{
	if (!root)
	{
		root = new TreeNode(x);
		return;
	}
	if (x < root->val)
	{
		insert(root->left, x);
		updateheight(root);
		if (getfactor(root) == 2)
		{
			if (getfactor(root->left) == 1)
				RRotate(root);
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
			if (getfactor(root->right) == -1)
				LRotate(root);
			else if (getfactor(root->right) == 1)
			{
				RRotate(root->right);
				LRotate(root);
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	int n, x;
	cin >> n;
	TreeNode* t = 0;
	while (n--)
	{
		cin >> x;
		insert(t, x);
	}
	if (t) cout << t->val;
	return 0;
}
