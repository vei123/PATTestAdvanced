#include<iostream>
#include<vector>
#include<unordered_set>
#define inf 0x3fffffff
using namespace std;

int n, m, k, c, d[205][205], mindist = inf, minindex = -1;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < 205; i++)
	{
		for (int j = 0; j < 205; j++)
			d[i][j] = inf;
	}
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		d[u][v] = d[v][u] = w;
	}
	cin >> k;
	for (int x = 1; x <= k; x++)
	{
		cin >> c;
		bool notacycle = 0, simplecycle = 1;
		int dist = 0;
		vector<int> p(c, 0);
		unordered_set<int> uset;
		for (int i = 0; i < c; i++)
		{
			cin >> p[i];
			if (uset.count(p[i]) && uset.size() != n) simplecycle = 0;
			uset.insert(p[i]);
			if (i)
			{
				if (d[p[i]][p[i - 1]] == inf)
				{
					notacycle = 1;
					dist = 0 - inf;
				}
				else dist += d[p[i]][p[i - 1]];
			}
		}
		if (p[0] != p.back()) notacycle = 1;
		if (uset.size() != n) notacycle = 1;
		cout << "Path " << x << ": ";
		if (dist > 0) cout << dist << " ";
		else cout << "NA ";
		if (notacycle) cout << "(Not a TS cycle)\n";
		else
		{
			if (simplecycle) cout << "(TS simple cycle)\n";
			else cout << "(TS cycle)\n";
		}
		if (!notacycle && dist > 0 && dist < mindist)
		{
			mindist = dist;
			minindex = x;
		}
	}
	cout << "Shortest Dist(" << minindex << ") = " << mindist;
	return 0;
}
