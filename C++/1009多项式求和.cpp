#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<iomanip>
#define term pair<int,double>
using namespace std;

bool cmp(const term& a, const term& b)
{
	return a.first > b.first;
}

int main()
{
	ios::sync_with_stdio(0);
	int k1, k2, n;
	double a;
	vector<term> v1, v2, v3;
	unordered_map<int, double> umap;
	cin >> k1;
	for (int i = 0; i < k1; i++)
	{
		cin >> n >> a;
		v1.push_back({ n,a });
	}
	cin >> k2;
	for (int i = 0; i < k2; i++)
	{
		cin >> n >> a;
		v2.push_back({ n,a });
	}
	for (term t1 : v1)
	{
		for (term t2 : v2)
		{
			n = t1.first+t2.first;
			a = t1.second*t2.second;
			umap[n] += a;
		}
	}
	for (auto p : umap)
	{
		if (abs(p.second) > 0.000001)
			v3.push_back(p);
	}
	sort(v3.begin(), v3.end(), cmp);
	int len = v3.size();
	cout << len;
	if (len) cout << " ";
	for (int i = 0; i < len; i++)
	{
		cout << v3[i].first << " ";
		cout << fixed << setprecision(1) << v3[i].second;
		if (i < len - 1) cout << " ";
	}
	return 0;
}
