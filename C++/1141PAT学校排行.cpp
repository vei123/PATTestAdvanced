#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

void tolower(string& s)
{
	for (char& c : s)
		if (c < 'a') c += char(0x20);
}

struct school
{
	int rank, sb, sa, st, tws, ns;
	string code;
	school() :rank(0), sb(0), sa(0), st(0), tws(0), ns(0), code("") {  }
	bool operator<(const school& s) const
	{
		if (tws != s.tws) return tws > s.tws;
		else
		{
			if (ns != s.ns) return ns < s.ns;
			else return code < s.code;
		}
	}
	void calculate()
	{
		tws = sb / 1.5 + sa + st * 1.5;
	}
	void print()
	{
		cout << rank << ' ' << code << ' ' << tws << ' ' << ns << '\n';
	}
};

int n;
unordered_map<string, school> umap;
vector<school> v;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	while (n--)
	{
		string id, code;
		int score;
		cin >> id >> score >> code;
		tolower(code);
		if (!umap.count(code))
		{
			umap[code] = school();
			umap[code].code = code;
		}
		umap[code].ns++;
		if (id[0] == 'B') umap[code].sb += score;
		else if (id[0] == 'A') umap[code].sa += score;
		else umap[code].st += score;
	}
	for (auto& p : umap)
	{
		if (p.second.ns)
		{
			p.second.calculate();
			v.emplace_back(p.second);
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	if (v.size()) v[0].rank = 1;
	for (int i = 0; i < v.size(); i++)
	{
		if (i)
		{
			if (v[i].tws == v[i - 1].tws)
				v[i].rank = v[i - 1].rank;
			else
				v[i].rank = i + 1;
		}
		v[i].print();
	}
	return 0;
}
