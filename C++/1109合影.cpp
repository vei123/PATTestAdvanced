#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct people
{
	string name;
	int high;
	bool operator<(const people& p) const
	{
		if (high != p.high) return high > p.high;
		else return name < p.name;
	}
};

signed main()
{
	ios::sync_with_stdio(0);
	int n, k;
	vector<people> v;
	vector<vector<people>> t;
	cin >> n >> k;
	v.resize(n);
	t.resize(k);
	int l = n / k;
	for (int i = 0; i < k; i++)
	{
		if (i) t[i].resize(l);
		else t[i].resize(n - (k - 1)*l);
	}
	for (int i = 0; i < n; i++)
		cin >> v[i].name >> v[i].high;
	sort(v.begin(), v.end());
	int x = 0;
	for (auto& a : t)
	{
		int len = a.size();
		int m = len / 2;
		int l = m - 1, r = m + 1;
		a[m] = v[x++];
		len--;
		while (1)
		{
			if (!len) break;
			if (l >= 0)
			{
				a[l] = v[x++];
				l--, len--;
			}
			if (!len) break;
			if (r < a.size())
			{
				a[r] = v[x++];
				r++, len--;
			}
		}
	}
	for (auto& a : t)
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (i) cout << ' ';
			cout << a[i].name;
		}
		cout << '\n';
	}
	return 0;
}
