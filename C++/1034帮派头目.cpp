#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
#define iipair pair<int, int>
using namespace std;

int n, k, cnt = 1;
int f[5005];
//存储从人名到数字的映射
unordered_map<string, int> ref1;
//存储从数字到人名的反向映射
unordered_map<int, string> ref2;
//存储每个人的通话时长
unordered_map<int, int> timetable;
//存储每个帮派的代表人物(即并查集的根节点)
unordered_map<int, int> roots;
//存储帮派通话时间
unordered_map<int, int> gangtime;
//存储每个帮派的人物
unordered_map<int, vector<iipair>> gangs;
//存储返回结果
vector<string> res;

int getroot(int i)
{
	return f[i] == i ? i : f[i] = getroot(f[i]);
}

bool cmp(const iipair& a, const iipair& b)
{
	return a.second > b.second;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 0; i < 5005; i++) f[i] = i;
	for (int i = 0; i < n; i++)
	{
		string a, b;
		int time;
		cin >> a >> b >> time;
		//建立人名与数字之间的映射ref1, ref2，方便并查集
		if (!ref1.count(a))
		{
			ref1[a] = cnt++;
			ref2[cnt - 1] = a;
		}
		if (!ref1.count(b))
		{
			ref1[b] = cnt++;
			ref2[cnt - 1] = b;
		}
		//计数通话时间
		timetable[ref1[a]] += time;
		timetable[ref1[b]] += time;
		//合并关系
		f[getroot(ref1[a])] = getroot(ref1[b]);
	}
	//统计各个帮派的代表人物(不一定是头目),并计数帮派通话时间
	for (int i = 1; i <= n; i++)
	{
		roots[getroot(i)] = 1;
		gangtime[getroot(i)] += timetable[i];
	}
	//根据帮派代表人物抓取帮派成员
	for (int i = 1; i <= n; i++)
	{
		int root = getroot(i);
		if (!gangs.count(root))
			gangs[root] = vector<iipair>();
		gangs[root].push_back({ i, timetable[i] });
	}
	for (auto p : gangs)
	{
		//筛出没超过2人的帮派
		if (p.second.size() <= 2) continue;
		//筛出总通话时间没超过k的帮派，注意gangtime[]存储了实际通话时长的2倍
		if (gangtime[p.first] <= 2 * k) continue;
		//按通话时间降序排列并统计结果
		sort(p.second.begin(), p.second.end(), cmp);
		res.push_back(ref2[p.second[0].first]);
	}
	//字母顺序排序结果
	sort(res.begin(), res.end());
	int m = res.size();
	cout << m << '\n';
	for (int i = 0; i < m; i++)
	{
		cout << res[i] << ' ';
		cout << gangs[getroot(ref1[res[i]])].size();
		if (i != m - 1) cout << '\n';
	}
	return 0;
}
