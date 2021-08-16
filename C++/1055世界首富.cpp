#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct person
{
	string name;
	int age, worth;
};

bool cmp(const person& p1, const person& p2)
{
	if (p1.worth != p2.worth) return p1.worth > p2.worth;
	else
	{
		if (p1.age != p2.age) return p1.age < p2.age;
		else return p1.name < p2.name;
	}
}

int n, k, m, amin, amax;
vector<person> tmp, v;

signed main()
{
	ios::sync_with_stdio(0);
	int n, k, cnt[201] = { 0 };
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		person p;
		cin >> p.name >> p.age >> p.worth;
		tmp.emplace_back(p);
	}
	sort(tmp.begin(), tmp.end(), cmp);
	for (auto& it : tmp)
	{
		if (cnt[it.age] < 100)
		{
			v.emplace_back(it);
			cnt[it.age]++;
		}
	}
	for (int l = 1; l <= k; l++)
	{
		cin >> m >> amin >> amax;
		cout << "Case #" << l << ":\n";
		vector<person> t;
		int c = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].age >= amin && v[i].age <= amax)
			{
				t.emplace_back(v[i]);
				c++;
				if (c == m) break;
			}
		}
		if (t.size())
		{
			sort(t.begin(), t.end(), cmp);
			for (int i = 0; i < t.size(); i++)
			{
				if (i) cout << '\n';
				cout << t[i].name << ' ';
				cout << t[i].age << ' ';
				cout << t[i].worth;
			}
		}
		else
			cout << "None";
		if (l != k) cout << '\n';
	}
	return 0;
}
