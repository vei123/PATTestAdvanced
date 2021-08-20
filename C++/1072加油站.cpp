#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<iomanip>
#define inf 0x3fffffff
using namespace std;

//m轮dijkstra计算任意两点之间距离，注意不能用floyd算法，会超时

struct node
{
	int v, w;
	node(int v, int w) :v(v), w(w) {  }
	bool operator<(const node& a) const { return w > a.w; }
};

int n, m, k, ds;
string t;
vector<vector<node>> graph;
int d[1015][1015];
int ans0 = inf;
double ans1 = 0.0, ans2 = 1e9;

void dijkstra(int src)
{
	for (int i = 0; i < 1015; i++) d[src][i] = inf;
	priority_queue<node> q;
	q.push(node(src, 0));
	while (!q.empty())
	{
		auto e1 = q.top();
		q.pop();
		if (d[src][e1.v]!=inf) continue;
		d[src][e1.v] = e1.w;
		for (auto& e2 : graph[e1.v])
		{
			if (d[src][e2.v] != inf) continue;
			else q.push({ e2.v, e1.w + e2.w });
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m >> k >> ds;
	graph.resize(1011);
	for (int i = 0; i < k; i++)
	{
		int u, v, w;
		cin >> t;
		if (t[0] == 'G') u = 1000 + stoi(t.substr(1));
		else u = stoi(t);
		cin >> t;
		if (t[0] == 'G') v = 1000 + stoi(t.substr(1));
		else v = stoi(t);
		cin >> w;
		graph[u].emplace_back(node(v, w));
		graph[v].emplace_back(node(u, w));
	}
	//m轮dijkstra
	for (int i = 1001; i <= 1000 + m; i++) dijkstra(i);
	//找出所有符合条件的选址
	int mindist = inf, sumdist = 0;
	double avgdist = 0.0;
	bool skip = 0;
	for (int i = 1001; i <= 1000 + m; i++)
	{
		mindist = inf, sumdist = 0, skip = 0;
		for (int j = 1; j <= n; j++)
		{
			sumdist += d[i][j];
			if (d[i][j] > ds) { skip = 1; break; }
			if (d[i][j] < mindist) mindist = d[i][j];
		}
		avgdist = double(sumdist) / n;
		if (skip) continue;
		if (mindist < ans1) continue;
		if (mindist == ans1 && avgdist > ans2) continue;
		if (mindist == ans1 && avgdist == ans2 && i > ans0) continue;
		ans0 = i, ans1 = mindist, ans2 = avgdist;
	}
	if (ans0 != inf)
	{
		cout << 'G' << ans0 - 1000 << '\n';
		cout << fixed << setprecision(1);
		cout << ans1 + 1e-8 << ' ' << ans2 + 1e-8;
	}
	else cout << "No Solution";
	return 0;
}
