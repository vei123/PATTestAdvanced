#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
/*
一次遍历即可找出共同祖先，关键提示：
在二叉搜索树中，两个值的最低共同祖先的值，一定是前序遍历中第一个不小于u且不大于v，或者不小于v且不大于u的值
*/
int m, n, pre[10005];
unordered_set<int> allkeys;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> pre[i];
		allkeys.insert(pre[i]);
	}
	while (m--)
	{
		int u, v, i = 0;
		cin >> u >> v;
		if (!allkeys.count(u) && !allkeys.count(v))
			cout << "ERROR: " << u << " and " << v << " are not found.\n";
		else if (!allkeys.count(u))
			cout << "ERROR: " << u << " is not found.\n";
		else if (!allkeys.count(v))
			cout << "ERROR: " << v << " is not found.\n";
		else
		{
			while (pre[i]<min(u, v) || pre[i]>max(u, v)) i++;
			if (pre[i] == u) cout << u << " is an ancestor of " << v << ".\n";
			else if (pre[i] == v) cout << v << " is an ancestor of " << u << ".\n";
			else cout << "LCA of " << u << " and " << v << " is " << pre[i] << ".\n";
		}
	}
	return 0;
}
