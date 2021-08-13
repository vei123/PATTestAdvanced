#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//线性复杂度的贪心算法

int n;
string s, res;
vector<string> v;

bool cmp(const string& s1, const string& s2)
{
	return s1 + s2 < s2 + s1;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	for (auto str : v) res += str;
	while (res.size() && res[0] == '0') res.erase(0, 1);
	if (res.empty()) cout << 0;
	else cout << res;
	return 0;
}
