#include<iostream>
#include<vector>
#include<queue>
#define inf 0x3fffffff
using namespace std;

struct node
{
	int v, w;
	bool operator<(const node& b) const { return w > b.w; }
};

int n, m, src, des, teams[505];
int d[505], r[505] = { 0 }, visit[505] = { 0 }, cnt[505] = { 0 };
vector<vector<node>> graph;

void dijkstra()
{
	for (int i = 0; i < n; i++) d[i] = inf;
	d[src] = 0;
	r[src] = teams[src];
	cnt[src] = 1;
	priority_queue<node> q;
	q.push(node{ src, 0 });
	while (!q.empty())
	{
		auto e1 = q.top();
		q.pop();
		if (visit[e1.v]) continue;
		visit[e1.v] = 1;
		for (auto e2 : graph[e1.v])
		{
			if (d[e1.v] + e2.w < d[e2.v])
			{
				d[e2.v] = d[e1.v] + e2.w;
				r[e2.v] = r[e1.v] + teams[e2.v];
				cnt[e2.v] = cnt[e1.v];
				q.push(node{ e2.v, d[e2.v] });
			}
			else if (d[e1.v] + e2.w == d[e2.v])
			{
				if (r[e1.v] + teams[e2.v] > r[e2.v])
					r[e2.v] = r[e1.v] + teams[e2.v];
				cnt[e2.v] += cnt[e1.v];
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m >> src >> des;
	graph.resize(n);
	for (int i = 0; i < n; i++) cin >> teams[i];
	while (m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].emplace_back(node{ v, w });
		graph[v].emplace_back(node{ u, w });
	}
	dijkstra();
	cout << cnt[des] << ' ' << r[des] << '\n';
	return 0;
}
