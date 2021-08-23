#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;
/*
有点繁琐的模拟题，思路：
先把出入记录读进来，按时间顺序排序后，再做如下处理：
一、如果这条记录是进入的记录，就把它的进入时间放入它所对应的车结构体的一个栈里，
	否则是出的记录，就从车结构体的栈里取出最近一个进入时间，然后将栈清空；
	将这两个时间点分别在num[]数组中作标记，表示两个时刻下停车场中车数量分别减1、加1；
	顺便更新统计此车的总共停车时间total
二、对之前得到的num[]数组做一次遍历，得到每时每刻停车场中车的数量
三、对询问依次访问num[]直接给出结果
四、对所有车按停车时间排序，打印所有有着最长停车时间的车的车牌号
*/
struct car
{
	string id;
	int total = 0;
	stack<int> stk;
	bool operator<(const car& c) const
	{
		if (total != c.total) return total > c.total;
		else return id < c.id;
	}
};

struct record
{
	string id;
	int time;
	bool in;
	bool operator<(const record& rec) const { return time < rec.time; }
};

int n, k, num[100005] = { 0 }, maxtime = 0;
record r[10005];
unordered_map<string, car> cars;
vector<car> v;

signed main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		string status;
		int hh, mm, ss;
		cin >> r[i].id;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		cin >> status;
		r[i].time = 3600 * hh + 60 * mm + ss;
		r[i].in = status == "in";
	}
	sort(r, r + n);
#define tcar cars[r[i].id]
	for (int i = 0; i < n; i++)
	{
		if (r[i].in) tcar.stk.push({ r[i].time });
		else
		{
			if (tcar.stk.size())
			{
				int c = tcar.stk.top();
				num[c]++;
				num[r[i].time]--;
				while(tcar.stk.size())
					tcar.stk.pop();
				tcar.total += r[i].time - c;
			}
		}
	}
#undef tcar
	for (int i = 1; i <= 3600 * 24; i++)
		num[i] += num[i - 1];
	while (k--)
	{
		int hh, mm, ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		cout << num[hh * 3600 + mm * 60 + ss] << '\n';
	}
	for (auto& p : cars)
	{
		v.emplace_back(p.second);
		v.back().id = p.first;
	}
	sort(v.begin(), v.end());
	maxtime = v[0].total;
	for (int i = 0; i < v.size(); i++)
		if (v[i].total == maxtime) cout << v[i].id << ' ';
	printf("%02d:%02d:%02d", maxtime / 3600, maxtime % 3600 / 60, maxtime % 60);
	return 0;
}
