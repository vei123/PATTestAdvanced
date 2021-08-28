#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<iomanip>
using namespace std;

int n, m;
unordered_map<int, int> couples;
unordered_set<int> guests;
vector<int> dogs;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		couples[a] = b;
		couples[b] = a;
	}
	cin >> m;
	while (m--)
	{
		int t;
		cin >> t;
		guests.insert(t);
	}
	for (int i : guests)
		if (!guests.count(couples[i])) dogs.emplace_back(i);
	sort(dogs.begin(), dogs.end());
	cout << dogs.size();
	if (dogs.size()) cout << '\n';
	for (int i = 0; i < dogs.size(); i++)
	{
		if (i) cout << ' ';
		cout << setfill('0') << setw(5) << dogs[i];
	}
	cout << '\n';
	return 0;
}
