#pragma GCC optimize(2)
#include<iostream>
#include<cstring>
#define inf 0x3fffffff
using namespace std;

//可以在PAT上以超过1000ms的时长勉强通过(对比于BFS的200ms)
//如果开启O2优化，可以在AcWing上通过，否则不能

int n, l, k, m, t, cnt = 0;
int d[1005][1005];

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> l;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) d[i][j] = inf;
	for (int i = 1; i <= n; i++)
	{
		cin >> m;
		while (m--)
		{
			cin >> t;
			d[t][i] = 1;
		}
	}
	for (int p = 1; p <= n; p++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				d[i][j] = d[i][p] + d[p][j] < d[i][j] ? d[i][p] + d[p][j] : d[i][j];
			}
		}
	}
	cin >> k;
	while (k--)
	{
		cnt = 0;
		cin >> t;
		for (int i = 1; i <= n; i++)
			if (d[t][i] <= l) cnt++;
		cout << (d[t][t] <= l ? cnt - 1 : cnt);
		if (k) cout << '\n';
	}
	return 0;
}
