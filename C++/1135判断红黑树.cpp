#include<iostream>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
/*
一道看似难但实际上很简单的题，坑人的点在于题目中没说清楚：
可能有人疑惑为什么图1中有叶子节点为红色但也是合法红黑树？其实是
题目中漏说了，在图中的红黑树中叶子结点都是空结点，即我们认为的叶子结点
的孩子节点，它一定是空值。规定这个空结点的颜色为黑。
所以性质3没有什么用处，因为它不会打破任何其它性质。
所以实际上只需判断题目中的性质2、4、5即可，对于性质2直接判断，
对于性质4，5，遍历二叉树，对每个结点进行一次判断即可
注：代码中的illegal变量是用来判断所给前序序列是否非法，PAT的用例
不会给非法前序序列，所以可以忽略，但是AcWing中会给非法前序序列，所以
为了两个测评都通过，才加上这一部分判断
*/
struct node
{
	int val;
	node* left;
	node* right;
	node(int val) :val(val), left(0), right(0) {  }
};

bool cmp(const int& a, const int& b) { return abs(a) < abs(b); }

int n, m, pre[30], in[30];

//根据前序、中序序列构建树
bool illegal = 0;
node* buildtree(int pl, int pr, int il, int ir)
{
	if (illegal) return 0;
	node* t = 0;
	if (pl > pr) return t;
	t = new node(pre[pl]);
	if (pl == pr) return t;
	int k = il;
	while (k <= ir && in[k] != pre[pl]) k++;
	if (k == ir + 1)
	{
		illegal = 1;
		return 0;
	}
	t->left = buildtree(pl + 1, pl + k - il, il, k - 1);
	t->right = buildtree(pl + k - il + 1, pr, k + 1, ir);
	return t;
}

//判断性质4
bool rule4(node* t)
{
	if (!t) return 1;
	if (t->val < 0)
	{
		if (t->left && t->left->val < 0) return 0;
		if (t->right && t->right->val < 0) return 0;
	}
	return 1;
}

//判断性质5
int cnt = -1;
bool rule5(node* t, int c = 0)
{
	if (!t)
	{
		if (cnt == -1)
		{
			cnt = c;
			return 1;
		}
		else return c == cnt;
	}
	else
	{
		if (t->val > 0) c++;
		return rule5(t->left, c) && rule5(t->right, c);
	}
}

//非递归前序遍历并判断性质4、5是否满足
bool isRBT(node* t)
{
	if (!t) return 1;
	if (t->val < 0) return 0;
	stack<node*> stk;
	while (t || !stk.empty())
	{
		if (t)
		{
			stk.push(t);
			if (!rule4(t)) return 0;
			cnt = -1;
			if (!rule5(t)) return 0;
			t = t->left;
		}
		else
		{
			t = stk.top();
			stk.pop();
			t = t->right;
		}
	}
	return 1;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	while (n--)
	{
		cin >> m;
		node* r = 0;
		illegal = 0;
		for (int i = 0; i < m; i++)
		{
			cin >> pre[i];
			in[i] = pre[i];
		}
		sort(in, in + m, cmp);
		r = buildtree(0, m - 1, 0, m - 1);
		if (illegal) cout << "No\n";
		else
		{
			if (isRBT(r)) cout << "Yes\n";
			else cout << "No\n";
		}
	}
	return 0;
}
