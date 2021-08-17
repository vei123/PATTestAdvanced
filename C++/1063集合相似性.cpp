#include<iostream>
#include<vector>
#include<unordered_set>
#include<iomanip>
using namespace std;

//注意：必须使用unordered_set，用unordered_map会超时

vector<unordered_set<int>> f;

signed main()
{
	ios::sync_with_stdio(0);
	int n, m, k, t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		f.emplace_back(unordered_set<int>());
		cin >> m;
		while (m--)
		{
			cin >> t;
			f[i].insert(t);
		}
	}
	cin >> k;
	while (k--)
	{
		int i, j, nc = 0;
		cin >> i >> j;
		for (auto& p : f[i - 1])
			if (f[j - 1].count(p)) nc++;
		for (auto& p : f[j - 1])
			if (f[i - 1].count(p)) nc++;
		cout << fixed << setprecision(1);
		cout << double(nc / 2) / double(f[i - 1].size() + f[j - 1].size() - nc / 2) * 100 << '%';
		if (k) cout << '\n';
	}
	return 0;
}
