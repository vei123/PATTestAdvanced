#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
using namespace std;

struct node
{
	int val;
	node* left;
	node* right;
	node(int val) :val(val), left(0), right(0) {  }
};

int n, a[35], b[35], unique = 1;
node* root;
vector<int> res;

node* buildtree(int al, int ar, int bl, int br)
{
	int len = ar - al;
	if (len < 0) return 0;
	node* t = new node(a[al]);
	if (!len) return t;
	unordered_set<int> useta, usetb;
	int i = al + 1, j = bl, k = 0, cnt = 0, k0 = -1;
	for (; k <= len; k++)
	{
		if (useta == usetb)
		{
			bool valid = 1;
			if (k && a[i] != b[j + k - 1]) valid = 0;
			if (k < len && a[i + k] != b[br - 1]) valid = 0;
			if (valid) cnt++, k0 = k;
		}
		useta.insert(a[i + k]);
		usetb.insert(b[j + k]);
	}
	if (cnt > 1) unique = 0;
	if (k0) t->left = buildtree(al + 1, al + k0, bl, bl + k0 - 1);
	if (k0 < len) t->right = buildtree(al + k0 + 1, ar, bl + k0, br - 1);
	return t;
}

void inordertraversal(node* t)
{
	if (!t) return;
	stack<node*> stk;
	while (t || !stk.empty())
	{
		if (t)
		{
			stk.push(t);
			t = t->left;
		}
		else
		{
			t = stk.top();
			stk.pop();
			res.emplace_back(t->val);
			t = t->right;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	root = buildtree(0, n - 1, 0, n - 1);
	if (unique) cout << "Yes\n";
	else cout << "No\n";
	inordertraversal(root);
	for (int i = 0; i < res.size(); i++)
	{
		if (i) cout << ' ';
		cout << res[i];
	}
	cout << '\n';
	return 0;
}
