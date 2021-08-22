#include<cstdio>
#include<stack>
using namespace std;

//两种做法，这里是建树，然后对建成的树用非递归后序遍历得到答案
//也可以不建树：入栈序列是前序遍历，出栈序列是后序遍历，根据两序列直接得出后序遍历序列

struct node
{
	int val;
	node* left;
	node* right;
	node() :val(0), left(0), right(0) {  }
	node(int val) :val(val), left(0), right(0) {  }
};

void postordertraversal(node* r)
{
	if (!r) return;
	node* t;
	stack<node*> s1, s2;
	s1.push(r);
	while (s1.size())
	{
		t = s1.top();
		s1.pop();
		s2.push(t);
		if (t->left) s1.push(t->left);
		if (t->right) s1.push(t->right);
	}
	while (s2.size())
	{
		printf("%d", s2.top()->val);
		s2.pop();
		if (s2.size()) printf(" ");
	}
}

signed main()
{
	int n;
	char c[5];
	stack<node*> stk;
	scanf("%d", &n);
	n *= 2;
	node* t = new node(0);
	node* root = t;
	while (n--)
	{
		int x;
		scanf("%s", c);
		if (c[1] == 'u')
		{
			scanf("%d", &x);
			if (t->left)
			{
				t->right = new node(x);
				t = t->right;
			}
			else
			{
				t->left = new node(x);
				t = t->left;
			}
			stk.push(t);
		}
		else
		{
			t = stk.top();
			stk.pop();
		}
	}
	postordertraversal(root->left);
	return 0;
}
