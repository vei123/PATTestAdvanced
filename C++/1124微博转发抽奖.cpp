#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

int m, n, s;
string t;
vector<string> v, w;
unordered_set<string> uset;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> m >> n >> s;
	v.emplace_back("");
	for (int i = 0; i < m; i++)
	{
		cin >> t;
		v.emplace_back(t);
	}
	for (int i = s; i < v.size();)
	{
		if (uset.count(v[i])) i++;
		else
		{
			uset.insert(v[i]);
			w.emplace_back(v[i]);
			i += n;
		}
	}
	if (w.size()) for (auto& str : w) cout << str << '\n';
	else cout << "Keep going...";
	return 0;
}
