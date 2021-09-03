#include<iostream>
using namespace std;
//卡点过AcWing的代码，注意这个暴力算法必须优化到极致才能AC
int n, m, k, s[1005], c = 0;
int e[1001][1001] = { 0 };
int ans[101];

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		e[v][u] = 1;
	}
	cin >> k;
	int a = 0;
	for (int i = 0; i < k; i++)
	{
		bool topo = 1;
		for (int j = 0; j < n; j++) cin >> s[j];
		for (int u = 0; u < n; u++)
		{
			for (int v = u + 1; v < n; v++)
			{
				if (e[s[u]][s[v]])
				{
					topo = 0;
					break;
				}
			}
			if (!topo) break;
		}
		if (!topo) ans[a++] = i;
	}
	for (int i = 0; i < a; i++)
	{
		if (i) cout << ' ';
		cout << ans[i];
	}
	return 0;
}
