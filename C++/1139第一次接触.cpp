#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#define int long long
using namespace std;
/*
有很多坑点的题，在PAT上比较简单，在AcWing上坑点很多...
*/
int n, m, k;
vector<vector<int>> ans;
unordered_set<int> rels;
unordered_map<int, vector<int>> fris;

bool cmp(const vector<int>& a, const vector<int>& b)
{
	if (a[0] != b[0]) return a[0] < b[0];
	else return a[1] < b[1];
}

inline bool find(int i, int j)
{
	return rels.count(100000 * i + j);
}

inline bool samesymbol(int i, int j)
{
	return (i / 10000) == (j / 10000);
}

signed main()
{
	scanf("%lld%lld", &n, &m);
	for (int i = 0; i < m; i++)
	{
		string s, t;
		cin >> s >> t;
		int u = abs(stoi(s)), v = abs(stoi(t));
		if (s[0] != '-') u += 10000;
		if (t[0] != '-') v += 10000;
		rels.insert(100000 * u + v);
		rels.insert(100000 * v + u);
		if (!fris.count(u)) fris[u] = vector<int>();
		fris[u].emplace_back(v);
		if (!fris.count(v)) fris[v] = vector<int>();
		fris[v].emplace_back(u);
	}
	scanf("%lld", &k);
	while (k--)
	{
		string s, t;
		cin >> s >> t;
		int u = abs(stoi(s)), v = abs(stoi(t));
		if (s[0] != '-') u += 10000;
		if (t[0] != '-') v += 10000;
		ans.clear();
		for (int i : fris[u])
		{
			if (!samesymbol(i, u) || i == v || i == u) continue;
			for (int j : fris[i])
			{
				if (samesymbol(j, v) && find(j, v) && j != u && j != v)
					ans.emplace_back(vector<int>{i, j});
			}
		}
		sort(ans.begin(), ans.end(), cmp);
		printf("%lld\n", ans.size());
		for (auto& p : ans) printf("%04lld %04lld\n", p[0] % 10000, p[1] % 10000);
	}
	return 0;
}
