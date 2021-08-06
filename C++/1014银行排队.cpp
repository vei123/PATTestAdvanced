#include<iostream>
#include<vector>
#include<queue>
#define iipair pair<int,int>
using namespace std;

int n, m, k, q, t, r = 0;
vector<queue<iipair>> win;
queue<iipair> out;
int res[1005] = { 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m >> k >> q;
	for (int i = 0; i < n; i++)
		win.push_back(queue<iipair>());
	for (int i = 1; i <= k; i++)
	{
		cin >> t;
		out.push({ i, t });
	}
	//08:00时刻，靠前的顾客进入黄线内
	while (r < n*m && !out.empty())
	{
		for (int i = 0; i < n; i++)
		{
			if (out.empty()) break;
			if (win[i].size() < m)
			{
				win[i].push(out.front());
				out.pop();
				r++;
			}
		}
	}
	//开始一天的工作，每分钟统计一次
	for (int i = 1;; i++)
	{
		//当黄线内顾客人数为0且黄线外顾客人数为0时结束
		if (!r && out.empty()) break;
		//对每一个窗口做一次处理
		for (int j = 0; j < n; j++)
		{
			//如果窗口j有人在办理业务
			if (!win[j].empty())
			{
				//正在办理业务的人等待用时减去一分钟，
				//如果等待用时为0，说明完成，写结果到res数组
				if (--win[j].front().second == 0)
				{
					res[win[j].front().first] = i;
					win[j].pop();
					r--;
				}
			}
		}
		//只要黄线内顾客人数少于n*m(最大可容纳)，
		//并且黄线外顾客人数不为0，
		//并且在17:00之前(注意不包括17:00)
		while (r < n*m && !out.empty() && i < 540)
		{
			t = 0;
			//寻找最小排队人数的窗口
			for (int j = 1; j < n; j++)
			{
				if (win[j].size() < win[t].size())
					t = j;
			}
			win[t].push(out.front());
			out.pop();
			r++;
		}
		//16:59分时特殊处理
		if (i == 539)
		{
			//对每一个窗口做一次特殊处理
			for (int j = 0; j < n; j++)
			{
				//如果窗口人数非空，直接计算出正在办理业务的
				//顾客的业务结束时间
				if (!win[j].empty())
				{
					res[win[j].front().first] =
						i + win[j].front().second;
					win[j].pop();
					r--;
				}
				//对于在排队的顾客，将其完成时间置为0，
				//即表示今天之内无法完成业务办理，要下班了
				while (!win[j].empty())
				{
					res[win[j].front().first] = 0;
					win[j].pop();
					r--;
				}
			}
			//同理对于黄线外的顾客也将其完成时间置为0
			while (!out.empty())
			{
				res[out.front().first] = 0;
				out.pop();
			}
			break;
		}
	}
	//打印完成时间
	for (int i = 0; i < q; i++)
	{
		cin >> t;
		if (!res[t]) cout << "Sorry";
		else
		{
			int hh = 8 + res[t] / 60;
			int mm = res[t] % 60;
			if (hh < 10) cout << '0';
			cout << hh;
			cout << ':';
			if (mm < 10) cout << '0';
			cout << mm;
		}
		if (i != q - 1) cout << '\n';
	}
	return 0;
}
