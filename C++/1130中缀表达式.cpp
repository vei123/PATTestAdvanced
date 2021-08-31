#include<iostream>
#include<string>
#define OP 1
#define VAR 2
using namespace std;
//很坑的一点：运算符可以是除了字母和数字外的任何单字符,所以判断是不是
//运算符要根据其有没有孩子结点来判断，没有就是变量，有就是运算符
struct node
{
	int type;
	string val;
	node* left;
	node* right;
	node(int type, string val) :
		type(type), val(val), left(0), right(0) {  }
};

int n, root, notroot[25] = { 0 }, child[25][2];
node* s[25] = { 0 };

void printnode(node* c)
{
	if (!c) return;
	if (c->type == VAR) cout << c->val;
	else
	{
		if (c->left && c->left->type == OP) cout << '(';
		if (c->left) printnode(c->left);
		if (c->left && c->left->type == OP) cout << ')';
		cout << c->val;
		if (c->right && c->right->type == OP) cout << '(';
		if (c->right) printnode(c->right);
		if (c->right && c->right->type == OP) cout << ')';
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string val;
		int l, r;
		cin >> val >> l >> r;
		if (l == -1 && r == -1) s[i] = new node(VAR, val);
		else s[i] = new node(OP, val);
		child[i][0] = l;
		child[i][1] = r;
	}
	for (int i = 1; i <= n; i++)
	{
		if (child[i][0] != -1)
		{
			s[i]->left = s[child[i][0]];
			notroot[child[i][0]] = 1;
		}
		if (child[i][1] != -1)
		{
			s[i]->right = s[child[i][1]];
			notroot[child[i][1]] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!notroot[i])
		{
			root = i;
			break;
		}
	}
	printnode(s[root]);
	return 0;
}
