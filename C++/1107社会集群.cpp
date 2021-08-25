#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//用并查集将有共同爱好的人联系到同一个集合中
int n, f[1005], num = 0;
vector<vector<int>> h;
vector<int> r;
unordered_map<int, int> u, v;

int getroot(int i) { return f[i] == i ? i : f[i] = getroot(f[i]); }

signed main()
{
	cin >> n;
	h.resize(n + 1);
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d: ", &k);
		h[i].resize(k);
		for (int j = 0; j < k; j++)
		{
			cin >> h[i][j];
			if (!u[h[i][j]]) u[h[i][j]] = i;
			else f[getroot(i)] = getroot(u[h[i][j]]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (f[i] == i) num++;
		v[getroot(i)]++;
	}
	for (auto& p : v)
		if (p.second) r.emplace_back(p.second);
	sort(r.begin(), r.end(), greater<int>());
	cout << num << '\n';
	for (int i = 0; i < num; i++)
	{
		if (i) cout << ' ';
		cout << r[i];
	}
	return 0;
}
