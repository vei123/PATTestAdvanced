#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;

int n, minlevel = 0x7fffffff, number = 0;
long double p, r;
vector<vector<int>> v;

void dfs(int i = 0, int level = 0)
{
	if (v[i].empty())
	{
		if (level < minlevel)
		{
			minlevel = level;
			number = 1;
		}
		else if (level == minlevel) number++;
	}
	else
	{
		for (int& j : v[i])
			dfs(j, level + 1);
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> p >> r;
	v.resize(n);
	r = 1 + r / 100;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		if (k)
		{
			v[i].resize(k);
			for (int j = 0; j < k; j++) cin >> v[i][j];
		}
	}
	dfs();
	cout << fixed << setprecision(4);
	cout << p * pow(r, minlevel) << ' ' << number;
	return 0;
}
