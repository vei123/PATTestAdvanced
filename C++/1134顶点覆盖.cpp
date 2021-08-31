#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

int n, m, k, c, t, u, v;
unordered_set<int> e;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		e.insert(10000 * u + v);
		e.insert(10000 * v + u);
	}
	cin >> k;
	while (k--)
	{
		cin >> c;
		unordered_set<int> uset;
		bool yes = 1;
		while (c--)
		{
			cin >> t;
			uset.insert(t);
		}
		for (int i : e)
		{
			if (!uset.count(i / 10000) && !uset.count(i % 10000))
			{
				yes = 0;
				break;
			}
		}
		if (yes) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
