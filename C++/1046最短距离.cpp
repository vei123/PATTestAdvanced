#include<iostream>
#include<algorithm>
using namespace std;

int n, m, t = 0, d[100005], l[100005], r[100005];

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	l[1] = r[1] = 0;
	//输入，并计算以1号结点为起点逆时针依次到各结点距离
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i];
		t += d[i];
		//从2号结点到n号结点
		if (i < n) l[i + 1] = t;
	}
	t = r[n] = d[n];
	//计算以1号结点为起点顺时针依次到各结点距离
	for (int i = n - 1; i >= 2; i--)
	{
		t += d[i];
		//从n-1号结点到2号结点
		r[i] = t;
	}
	cin >> m;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		if (u == 1) cout << min(l[v], r[v]);
		else cout << min(l[v] - l[u], l[u] + r[v]);
		if (m) cout << '\n';
	}
	return 0;
}
