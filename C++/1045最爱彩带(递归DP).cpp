#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

//递归DP(记忆化搜索)

int n, m, l, t;
int o[205];
vector<int> v;
unordered_set<int> colors;
int d[10005][205];

int count(int i, int vn, int c)
{
	if (c >= m || i >= vn) return 0;
	if (d[i][c] < 0)
	{
		if (o[c] == v[i])
			d[i][c] = 1 + count(i + 1, vn, c);
		else
			d[i][c] = max(count(i + 1, vn, c), count(i, vn, c + 1));
	}
	return d[i][c];
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> m;
	memset(d, -1, sizeof(d));
	for (int i = 0; i < m; i++)
	{
		cin >> o[i];
		colors.insert(o[i]);
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		cin >> t;
		if (colors.count(t)) v.emplace_back(t);
	}
	cout << count(0, v.size(), 0);
	return 0;
}
