#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

//广度优先搜索(BFS)，使用队列存储每一层所需访问的结点，
//注意，使用bfs需要对边界处理具有极好的掌控能力，如果不能适当
//剪枝，或者出口没有设置好(这样往往会多运行一层)，很容易超时

int n, l, k, m, t, cnt;
int visit[1005];
vector<vector<int>> net;

void bfs(int p)
{
	memset(visit, 0, 4020);
	cnt = 0;
	queue<int> q;
	q.push(p);
	int level = 0;
	while (!q.empty())
	{
		int len = q.size();
		while (len--)
		{
			int t = q.front();
			q.pop();
			if (level == l) continue;
			for (int& i : net[t])
			{
				if (!visit[i])
				{
					cnt++;
					visit[i] = 1;
					q.push(i);
				}
			}
		}
		if (++level > l) break;
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> l;
	net.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> m;
		while (m--)
		{
			cin >> t;
			net[t].emplace_back(i);
		}
	}
	cin >> k;
	while (k--)
	{
		cin >> t;
		bfs(t);
		cout << (visit[t] ? cnt - 1 : cnt);
		if (k) cout << '\n';
	}
	return 0;
}
