#include<iostream>
#include<vector>
using namespace std;

int n, h[1005];
bool maxheap = 1, minheap = 1;
vector<int> t;
vector<vector<int>> p;

void dfs(int i = 0)
{
	int a;
	if (i) a = t.back();
	t.emplace_back(h[i]);
	if (i)
	{
		if (a < t.back()) maxheap = 0;
		if (a > t.back()) minheap = 0;
	}
	if (2 * i + 2 < n) dfs(2 * i + 2);
	if (2 * i + 1 < n) dfs(2 * i + 1);
	else p.emplace_back(t);
	t.pop_back();
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> h[i];
	dfs();
	for (auto& v : p)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (i) cout << ' ';
			cout << v[i];
		}
		cout << '\n';
	}
	if (maxheap) cout << "Max Heap\n";
	else if (minheap) cout << "Min Heap\n";
	else cout << "Not Heap\n";
	return 0;
}
