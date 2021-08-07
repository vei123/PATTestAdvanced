#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<iomanip>
using namespace std;

struct mytime
{
	int hh, mm, ss;
	mytime() :hh(0), mm(0), ss(0) {}
	mytime(int hh, int mm, int ss):
		hh(hh), mm(mm), ss(ss) {}
	bool operator<(const mytime& t) const
	{
		if (this->hh != t.hh) return this->hh < t.hh;
		else
		{
			if (this->mm != t.mm) return this->mm < t.mm;
			else return this->ss < t.ss;
		}
	}
	int operator-(const mytime& t) const
	{
		return 
			(double)(this->hh - t.hh) * 3600 +
			(double)(this->mm - t.mm) * 60 + 
			(double)(this->ss - t.ss);
	}
	int getseconds()
	{
		return hh * 3600 + mm * 60 + ss;
	}
};

struct person
{
	int id;
	mytime come;
	int proc;
	person(int id, int hh, int mm, int ss, int proc)
	{
		this->id = id;
		this->come = mytime(hh, mm, ss);
		this->proc = proc;
	}
};

bool cmp(person& p1, person& p2)
{
	return p1.come < p2.come;
}

int n, k, t, r = 0;
double totalmytime = 0.0;
const mytime T8 = mytime(8, 0, 0);
const mytime T17 = mytime(17, 0, 0);
vector<person> v, w;
queue<person> q;
string str;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++)
		w.push_back(person(0, 0, 0, 0, 0));
	for (int i = 0; i < n; i++)
	{
		cin >> str >> t;
		//每人占用窗口不超过1小时
		if (t > 60) t = 60;
		int h = stoi(str.substr(0, 2));
		int m = stoi(str.substr(3, 2));
		int s = stoi(str.substr(6, 2));
		mytime t1 = mytime(h, m, s);
		//如果到达时间晚于17点，则不处理
		if (T17 < t1)
			continue;
		else
			v.push_back(person(i, h, m, s, 60 * t));
	}
	sort(v.begin(), v.end(), cmp);
	for (auto i : v) q.push(i);
	//08:00:00, 开始办理业务
	for (int i = 0; i < k; i++)
	{
		if (q.empty()) break;
		auto p = q.front();
		//如果队头晚于8点，则直接跳过
		if (T8 < p.come) break;
		//如果当前窗口空闲，则服务队头顾客
		if (w[i].proc == 0)
		{
			w[i] = q.front();
			q.pop();
			r++;
			//计算等待时间并加入总时间
			totalmytime += T8 - w[i].come;
		}
	}
	for (int i = 1;; i++)
	{
		if (r == 0 && q.empty()) break;
		for (int j = 0; j < k; j++)
		{
			if (w[j].proc > 0 && --w[j].proc == 0)
				r--;
		}
		while (!q.empty() && r < k && 
		q.front().come.getseconds() <= i + 8 * 3600)
		{
			for (int j = 0; j < k; j++)
			{
				if (w[j].proc == 0)
				{
					w[j] = q.front();
					q.pop();
					r++;
					totalmytime += i + 8 * 3600 -
						w[j].come.getseconds();
					break;
				}
			}
		}
	}
	cout << fixed << setprecision(1);
	cout << (double)totalmytime / 60 / v.size();
	return 0;
}
