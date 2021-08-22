#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

int n, t, s, retailers = 0;
double p, r, maxprice = 0.0;
vector<vector<int>> v;

void dfs(int x, int level = 0)
{
	if (v[x].size())
		for (int i : v[x]) dfs(i, level + 1);
	else
	{
		double price = pow(r, level) * p;
		if (price > maxprice)
		{
			maxprice = price;
			retailers = 1;
		}
		else if (price == maxprice) retailers++;
	}
}

signed main()
{
	cin >> n >> p >> r;
	v.resize(n);
	r = 1 + r / 100;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		if (t != -1) v[t].emplace_back(i);
		else s = i;
	}
	dfs(s);
	cout << fixed << setprecision(2);
	cout << maxprice << ' ' << retailers;
	return 0;
}
