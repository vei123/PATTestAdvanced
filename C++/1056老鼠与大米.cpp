#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//非常无聊的一道题，跟算法和数学没有任何关系，倒像是在考英文阅读能力，
//但是题意也没说清楚，从字里行间完全看不出来第三行输入是在表达什么，
//数字x表示第x号老鼠入场顺序是这个数字的输入顺序数i，很容易
//理解反了，理解成第i号老鼠入场顺序是x，模棱两可，还得从样例去试题意

struct mice
{
	int index, order, weight;
	bool operator<(const mice& m) { return this->weight > m.weight; }
};

bool cmp(const mice& m1, const mice& m2)
{
	return m1.order < m2.order;
}

signed main()
{
	ios::sync_with_stdio(0);
	int np, ng, cnt, level = 1, r[10005], c[1005] = { 0 };
	vector<vector<mice>> t;
	vector<mice> v;
	cin >> np >> ng;
	cnt = np;
	for (int i = 0; i < np; i++)
	{
		mice m;
		m.index = i;
		cin >> m.weight;
		v.push_back(m);
	}
	//tmp号老鼠的参赛顺序是i
	for (int i = 0; i < np; i++)
	{
		int tmp;
		cin >> tmp;
		v[tmp].order = i;
	}
	while (cnt > 1)
	{
		sort(v.begin(), v.end(), cmp);
		t.clear();
		for (int i = 0; i < v.size(); i++)
		{
			if (i % ng == 0)
				t.emplace_back(vector<mice>());
			t.back().emplace_back(v[i]);
		}
		v.clear();
		for (auto& vec : t)
		{
			sort(vec.begin(), vec.end());
			while (vec.size() > 1)
			{
				r[vec.back().index] = level;
				vec.pop_back();
				cnt--;
			}
			v.emplace_back(vec[0]);
		}
		level++;
	}
	r[v[0].index] = level;
	for (int i = 0; i < np; i++)
		c[r[i]]++;
	int res[1005];
	res[level] = 1;
	for (int i = level - 1; i >=1; i--)
		res[i] = res[i + 1] + c[i + 1];
	for (int i = 0; i < np; i++)
	{
		if (i) cout << ' ';
		cout << res[r[i]];
	}
	return 0;
}
