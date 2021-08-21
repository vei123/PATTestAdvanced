#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct stu
{
	string name, id;
	int grade;
	bool operator<(const stu& s) const { return grade > s.grade; }
};

signed main()
{
	ios::sync_with_stdio(0);
	int n, g1, g2;
	vector<stu> t, v;
	cin >> n;
	while (n--)
	{
		stu s;
		cin >> s.name >> s.id >> s.grade;
		t.emplace_back(s);
	}
	cin >> g1 >> g2;
	for (auto& s : t)
		if (s.grade >= g1 && s.grade <= g2) v.emplace_back(s);
	sort(v.begin(), v.end());
	if (v.size())
	{
		for (auto& s : v)
			cout << s.name << ' ' << s.id << '\n';
	}
	else cout << "NONE";
	return 0;
}
