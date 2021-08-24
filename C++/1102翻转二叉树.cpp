#include<cstdio>
#include<queue>
#include<stack>
using namespace std;
//输入字符变量时，注意用getchar抵消多余的回车
struct node
{
	int val;
	node* left;
	node* right;
	node() :val(0), left(0), right(0) {  }
	node(int val) :val(val), left(0), right(0) {  }
};

int n, notroot[10] = { 0 }, root = -1;
node* s[10] = { 0 };

void invert(node* t)
{
	if (!t) return;
	invert(t->left);
	invert(t->right);
	swap(t->left, t->right);
}

void levelordertraversal(node* t)
{
	if (!t) return;
	node* c = t;
	queue<node*> q;
	q.push(t);
	while (!q.empty())
	{
		int len = q.size();
		while (len--)
		{
			c = q.front();
			q.pop();
			printf("%d", c->val);
			if (c->left) q.push(c->left);
			if (c->right) q.push(c->right);
			if (!q.empty()) printf(" ");
		}
	}
}

void inordertraversal(node* t)
{
	if (!t) return;
	node* c = t;
	stack<node*> stk;
	while (c || !stk.empty())
	{
		if (c)
		{
			stk.push(c);
			c = c->left;
		}
		else
		{
			c = stk.top();
			stk.pop();
			printf("%d", c->val);
			c = c->right;
			if (c || !stk.empty()) printf(" ");
		}
	}
}

signed main()
{
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		if (!s[i]) s[i] = new node(i);
		char left, right;
		int l = -1, r = -1;
		scanf("%c %c", &left, &right);
		getchar();
		if (left != '-')
		{
			l = int(left - '0');
			notroot[l] = 1;
			if (!s[l]) s[l] = new node(l);
			s[i]->left = s[l];
		}
		if (right != '-')
		{
			r = int(right - '0');
			notroot[r] = 1;
			if (!s[r]) s[r] = new node(r);
			s[i]->right = s[r];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (!notroot[i])
		{
			root = i;
			break;
		}
	}
	invert(s[root]);
	levelordertraversal(s[root]);
	printf("\n");
	inordertraversal(s[root]);
	return 0;
}
