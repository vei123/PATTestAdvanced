#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int N, m, n, a[10005] = { 0 }, level[10005][3] = { 0 }, f[10005];
vector<vector<int>> b;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N, greater<int>());
	n = int(sqrt(N));
	while (N%n) n--;
	m = N / n;
	b.resize(m);
	for (auto& v : b) v.resize(n);
	for (int i = 0, m0 = m, n0 = n;; i++, m0 -= 2, n0 -= 2)
	{
		if (m0 <= 0 || n0 <= 0) break;
		level[i][0] = n0 > 1 ? 2 * (m0 + n0) - 4 : m0;
		level[i][1] = m0;
		level[i][2] = n0;
		if (i)
		{
			level[i][0] += level[i - 1][0];
			for (int j = level[i - 1][0]; j < level[i][0]; j++)
				f[j] = i;
		}
		else
		{
			for (int j = 0; j < level[0][0]; j++)
				f[j] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		int l = f[i], seq = i;
		int m0 = level[l][1], n0 = level[l][2];
		if (l) seq = i - level[l - 1][0];
		if (seq < n0)
			b[l][l + seq] = a[i];
		else if (seq >= n0 && seq < m0 + n0 - 1)
			b[l + seq - n0 + 1][n - l - 1] = a[i];
		else if (seq >= m0 + n0 - 1 && seq < m0 + 2 * n0 - 2)
			b[m - l - 1][l + m0 + 2 * n0 - 3 - seq] = a[i];
		else
			b[l + 2 * (m0 + n0) - 4 - seq][l] = a[i];	
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j) cout << ' ';
			cout << b[i][j];
		}
		cout << '\n';
	}
	return 0;
}
