#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

signed main()
{
	ios::sync_with_stdio(0);
	int n, t, id;
	unordered_set<int> uset;
	vector<int> v;
	cin >> n;
	while (n--)
	{
		cin >> t;
		id = 0;
		while (t)
		{
			id += t % 10;
			t /= 10;
		}
		uset.insert(id);
	}
	for (int i : uset) v.emplace_back(i);
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
	{
		if (i) cout << ' ';
		cout << v[i];
	}
	cout << '\n';
	return 0;
}
