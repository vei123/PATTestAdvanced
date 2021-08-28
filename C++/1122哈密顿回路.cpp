#include<iostream>
#include<unordered_set>
using namespace std;

int n, m, q, k, t, d[205][205] = { 0 };

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
		int src, u, v, valid = 1;
		unordered_set<int> visited;
		cin >> k;
		if (k != n + 1)
		{
			valid = 0;
			while (k--) cin >> t;
		}
		else
		{
			for (int i = 0; i < k; i++)
			{
				cin >> t;
				if (i)
				{
					u = v;
					v = t;
					if (!d[u][v]) valid = 0;
					if (visited.count(t) && i != k - 1) valid = 0;
					if (i == k - 1 && t != src) valid = 0;
					visited.insert(t);
				}
				else
				{
					src = v = t;
					visited.insert(t);
				}
			}
		}
		if (valid) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
