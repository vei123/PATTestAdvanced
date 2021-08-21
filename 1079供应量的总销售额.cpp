#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

int n, k, t;
double p, r, sum = 0.0;
vector<vector<int>> net;

void dfs(int s, int level = 0)
{
	if (!net[s][0])
	{
		sum += net[s][1] * p * pow(r, level);
		return;
	}
	else
	{
		for (int i = 1; i < net[s].size(); i++)
			dfs(net[s][i], level + 1);
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> p >> r;
	r = 1 + r / 100;
	net.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		net[i].emplace_back(k);
		if (!k)
		{
			cin >> t;
			net[i].emplace_back(t);
		}
		else
		{
			while (k--)
			{
				cin >> t;
				net[i].emplace_back(t);
			}
		}
	}
	dfs(0);
	cout << fixed << setprecision(1);
	cout << sum + 1e-8;
	return 0;
}
