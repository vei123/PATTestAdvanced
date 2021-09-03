#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
//注意事项：考场号以及时间等输出需要保留固定位数，直接cout或者%d会出错
struct testee
{
	string card;
	char level;
	int site, date, id, score;
	testee(string card, int score) : card(card), score(score) 
	{
		level = card[0];
		site = stoi(card.substr(1, 3));
		date = stoi(card.substr(4, 6));
		id = stoi(card.substr(10, 3));
	}
	bool operator<(const testee& t) const
	{
		if (score != t.score) return score > t.score;
		else return card < t.card;
	}
};

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2)
{
	if (p1.first != p2.first) return p1.first > p2.first;
	else return p1.second < p2.second;
}

int n, m;
vector<testee> v;

signed main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string card;
		int score;
		cin >> card >> score;
		v.emplace_back(testee(card, score));
	}
	for (int k = 1; k <= m; k++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			char level;
			vector<testee> a;
			cin >> level;
			printf("Case %d: 1 %c\n", k, level);
			for (auto& t : v) if (t.level == level) a.emplace_back(t);
			sort(a.begin(), a.end());
			if (a.empty()) cout << "NA\n";
			else for (auto& t : a) cout << t.card << ' ' << t.score << '\n';
		}
		else if (type == 2)
		{
			int site, nt = 0, ns = 0;
			cin >> site;
			printf("Case %d: 2 %03d\n", k, site);
			for (auto& t : v) if (t.site == site) nt++, ns += t.score;
			if (nt) cout << nt << ' ' << ns << '\n';
			else cout << "NA\n";
		}
		else
		{
			int date;
			unordered_map<int, int> umap;
			vector<pair<int, int>> a;
			cin >> date;
			printf("Case %d: 3 %06d\n", k, date);
			for (auto& t : v) if (t.date == date) umap[t.site]++;
			for (auto& p : umap) if (p.second) a.emplace_back(pair<int, int>{p.second, p.first});
			sort(a.begin(), a.end(), cmp);
			if (a.empty()) cout << "NA\n";
			else for (auto& p : a) printf("%03d %d\n", p.second, p.first);
		}
	}
	return 0;
}
