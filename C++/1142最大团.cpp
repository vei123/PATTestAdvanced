#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
暴力枚举算法
*/
int n, m, q, k, d[205][205] = { 0 };

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		d[u][v] = d[v][u] = 1;
	}
	cin >> q;
	while (q--)
	{
		int k, mode = 1;
		cin >> k;
		vector<int> t(k, 0);
		unordered_set<int> uset;
		for (int i = 0; i < k; i++)
		{
			cin >> t[i];
			uset.insert(t[i]);
		}
		for (int i : t)
		{
			for (int j : uset)
			{
				if (i == j) continue;
				if (!d[i][j])
				{
					mode = 0;
					break;
				}
			}
			if (!mode) break;
		}
		if (mode)
		{
			bool allconnected = 0;
			for (int i = 1; i <= n; i++)
			{
				if (uset.count(i)) continue;
				allconnected = 1;
				for (int j : uset)
				{
					if (!d[i][j])
					{
						allconnected = 0;
						break;
					}
				}
				if (allconnected) break;
			}
			if (allconnected) cout << "Not Maximal\n";
			else cout << "Yes\n";
		}
		else cout << "Not a Clique\n";
	}
	return 0;
}
