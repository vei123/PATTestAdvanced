#include<iostream>
#include<unordered_set>
using namespace std;

int n, m, k, e[10005][2], f[10005];

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> e[i][0] >> e[i][1];
	cin >> k;
	while (k--)
	{
		int t, k_coloring = 1;
		unordered_set<int> c;
		for (int i = 0; i < n; i++)
		{
			cin >> f[i];
			c.insert(f[i]);
		}
		for (int i = 1; i <= m; i++)
		{
			if (f[e[i][0]] == f[e[i][1]])
			{
				k_coloring = 0;
				break;
			}
		}
		if (k_coloring) cout << c.size() << "-coloring\n";
		else cout << "No\n";
	}
	return 0;
}
