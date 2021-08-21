#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct app
{
	int id, ge, gi, total, choice[5];
	bool operator<(const app& a) const
	{
		if (total != a.total) return total > a.total;
		else
		{
			if (ge != a.ge) return ge > a.ge;
			else return 0;
		}
	}
};

bool cmp(const app& a, const app& b)
{
	return a.id < b.id;
}

signed main()
{
	ios::sync_with_stdio(0);
	int n, m, k, q[105];
	vector<app> v;
	vector<vector<app>> adm;
	cin >> n >> m >> k;
	adm.resize(m);
	for (int i = 0; i < m; i++) cin >> q[i];
	for (int i = 0; i < n; i++)
	{
		app a;
		cin >> a.ge >> a.gi;
		a.id = i;
		a.total = a.ge + a.gi;
		for (int j = 0; j < k; j++) cin >> a.choice[j];
		v.emplace_back(a);
	}
	sort(v.begin(), v.end());
	for (auto& a : v)
	{
		for (int i = 0; i < k; i++)
		{
			int s = a.choice[i];
			if (adm[s].size() < q[s])
			{
				adm[s].emplace_back(a);
				break;
			}
			else if (!(a < adm[s].back()) && !(adm[s].back() < a))
			{
				adm[s].emplace_back(a);
				break;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		sort(adm[i].begin(), adm[i].end(), cmp);
		for (int j = 0; j < adm[i].size(); j++)
		{
			if (j) cout << " ";
			cout << adm[i][j].id;
		}
		//if (i < m - 1) cout << '\n';
		cout << '\n';
	}
	return 0;
}
