#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;

struct stu
{
	string id;
	int gp, gm, gf, g;
	stu() :id(""), gp(-1), gm(-1), gf(-1), g(-1) {  }
	bool operator<(const stu& s) const
	{
		if (g != s.g) return g > s.g;
		else return id < s.id;
	}
	void calculate()
	{
		if (gm > gf) g = round(0.4*gm + (gf > 0 ? 0.6*gf : 0));
		else g = gf;
	}
	bool qualified()
	{
		return gp >= 200 && g >= 60;
	}
};

int p, m, n;
string s;
unordered_set<string> students;
unordered_map<string, stu> umap;
vector<stu> v;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> p >> m >> n;
	for (int i = 0; i < p; i++)
	{
		cin >> s;
		if (students.count(s)) cin >> umap[s].gp;
		else
		{
			umap[s] = stu();
			umap[s].id = s;
			cin >> umap[s].gp;
			students.insert(s);
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (students.count(s)) cin >> umap[s].gm;
		else
		{
			umap[s] = stu();
			umap[s].id = s;
			cin >> umap[s].gm;
			students.insert(s);
		}
	}
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (students.count(s)) cin >> umap[s].gf;
		else
		{
			umap[s] = stu();
			umap[s].id = s;
			cin >> umap[s].gf;
			students.insert(s);
		}
	}
	for (auto& a : umap)
	{
		if (!a.first.empty())
		{
			a.second.calculate();
			if (a.second.qualified()) v.emplace_back(a.second);
		}
	}
	sort(v.begin(), v.end());
	for (auto& a : v)
		cout << a.id << ' ' << a.gp << ' ' << a.gm << ' ' << a.gf << ' ' << a.g << '\n';
	return 0;
}
