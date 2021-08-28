#include<iostream>
using namespace std;
/*
统计结点度数然后看奇数度数结点个数即可，当然注意题目中说了
连通图才有这种判断依据，如果不是连通图，显然不可能有欧拉道路
更不可能有欧拉回路，所以对于非连通图，直接输出非欧拉图。
判断是不是连通图用并查集，计数连通分支，如果分支个数为1则为连通
*/
int n, m, u, v, cnt = 0, odd = 0, d[505] = { 0 }, f[505];

int getroot(int i)
{
	return f[i] == i ? i : f[i] = getroot(f[i]);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		f[getroot(v)] = getroot(u);
		d[u]++, d[v]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (i > 1) cout << ' ';
		cout << d[i];
		if (d[i] & 1) odd++;
		if (f[i] == i) cnt++;
	}
	if (cnt > 1) cout << "\nNon-Eulerian";
	else if (!odd) cout << "\nEulerian";
	else if (odd == 2) cout << "\nSemi-Eulerian";
	else cout << "\nNon-Eulerian";
	return 0;
}
