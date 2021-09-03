#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
//一个稍有优化的双重循环，复杂度仍然比较高
int n, m, k, t, u, v;
unordered_map<int, vector<int>> umap;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> u >> v;
		if (!umap.count(u)) umap[u] = vector<int>();
		if (!umap.count(v)) umap[v] = vector<int>();
		umap[u].emplace_back(i);
		umap[v].emplace_back(i);
	}
	while (m--)
	{
		bool yes = 1;
		unordered_set<int> uset;
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> t;
			for (int j : umap[t])
			{
				if (uset.count(j))
				{
					yes = 0;
					break;
				}
				uset.insert(j);
			}
		}
		if (yes) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
