#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//带路径记录的0-1背包问题，DP求解

int n, m, t;
int d[10005][101] = { 0 };
bool s[10005][101] = { 0 };
vector<int> a = { 0 };
vector<int> res;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		if (t <= 100) a.emplace_back(t);
	}
	sort(a.begin() + 1, a.end(), greater<int>());
	for (int i = 1; i < a.size(); i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j < a[i])
			{
				d[i][j] = d[i - 1][j];
				s[i][j] = 0;
			}
			else
			{
				if (d[i - 1][j - a[i]] + a[i] >= d[i - 1][j])
				{
					d[i][j] = d[i - 1][j - a[i]] + a[i];
					s[i][j] = 1;
				}
				else
				{
					d[i][j] = d[i - 1][j];
					s[i][j] = 0;
				}
			}
		}
	}
	if (d[a.size() - 1][m] != m)
	{
		cout << "No Solution";
		return 0;
	}
	int k = a.size() - 1, j = m;
	while (k)
	{
		if (s[k][j])
		{
			j -= a[k];
			res.emplace_back(a[k]);
		}
		k--;
	}
	for (int i = 0; i < res.size(); i++)
	{
		if (i) cout << ' ';
		cout << res[i];
	}
	return 0;
}
