#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

signed main()
{
	ios::sync_with_stdio(0);
	int n, k;
	unordered_map<int, vector<string>> courselist;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		string s;
		int c;
		cin >> s >> c;
		for (int j = 0; j < c; j++)
		{
			int t;
			cin >> t;
			if (!courselist.count(t))
				courselist[t] = vector<string>();
			courselist[t].emplace_back(s);
		}
	}
	for (int i = 1; i <= k; i++)
	{
		int len = courselist[i].size();
		cout << i << ' ' << len;
		if (i < k || len) cout << '\n';
		if (len)
		{
			sort(courselist[i].begin(), courselist[i].end());
			for (int j = 0; j < len; j++)
			{
				cout << courselist[i][j];
				if (i < k || j < len - 1) cout << '\n';
			}
		}
	}
	return 0;
}
