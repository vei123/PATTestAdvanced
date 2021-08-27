#include<iostream>
#include<vector>
#include<queue>
#define inf 0x3fffffff
using namespace std;
//没意义的繁琐的题目，相当于做了两次PAT1030或两次PAT1087

//用于邻接表，以及堆操作的边结构体，
//表示从某一个点(在邻接表graph中是二维vector的一级索引)到v的距离为d，花费为c
struct node
{
	int v, d, c;
	node(int v, int d, int c) :v(v), d(d), c(c) {  }
};
//其实如果只有一个权值，可以不写结构体，只需把在node中重载小于运算符“<”即可，但这里有两个权值
//优先队列中要用到的比较结构体，“d”表示这里是比较距离，注意由于每次要取最小距离的node，所以
//要构建小顶堆，大的node要下沉，所以返回a.d大于b.d，而不是小于，这一点要格外注意
struct cmpd { bool operator()(const node& a, const node& b) { return a.d > b.d; } };
//同理cpmd，但这里是比较最小花费
struct cmpc { bool operator()(const node& a, const node& b) { return a.c > b.c; } };
//ed，ec存储两种权值的邻接矩阵，因为邻接表不方便取任意两点之间边的权值
int n, m, t, src, des, ed[505][505], ec[505][505];
int dist[505], cost[505], visit[505], tcost[505], inter[505];
vector<vector<node>> graph;//图的邻接表表示
vector<int> pred, prec, shortestpath, fastestpath;

//mode=1计算最短路，mode=0计算最小花费，格外注意要用到的各种数组，对它们的初始化不能出错
void dijkstra(bool mode)
{
	for (int i = 0; i < n; i++) visit[i] = 0;
	if (mode)
	{
		for (int i = 0; i < n; i++) dist[i] = inf;
		for (int i = 0; i < n; i++) tcost[i] = inf;
		dist[src] = tcost[src] = 0;
		priority_queue<node, vector<node>, cmpd> q;
		q.push(node(src, 0, 0));
		while (!q.empty())
		{
			auto e1 = q.top();
			q.pop();
			if (visit[e1.v]) continue;
			visit[e1.v] = 1;
			for (auto e2 : graph[e1.v])
			{
				if (dist[e1.v] + e2.d < dist[e2.v])
				{
					dist[e2.v] = dist[e1.v] + e2.d;
					pred[e2.v] = e1.v;
					tcost[e2.v] = tcost[e1.v] + ec[e1.v][e2.v];
					q.push(node(e2.v, dist[e2.v], e2.c));
				}
				else if (dist[e1.v] + e2.d == dist[e2.v] && tcost[e1.v] + ec[e1.v][e2.v] < tcost[e2.v])
				{
					pred[e2.v] = e1.v;
					tcost[e2.v] = tcost[e1.v] + ec[e1.v][e2.v];
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++) cost[i] = inf;
		for (int i = 0; i < n; i++) inter[i] = inf;
		cost[src] = inter[src] = 0;
		priority_queue<node, vector<node>, cmpc> q;
		q.push(node(src, 0, 0));
		while (!q.empty())
		{
			auto e1 = q.top();
			q.pop();
			if (visit[e1.v]) continue;
			visit[e1.v] = 1;
			for (auto e2 : graph[e1.v])
			{
				if (cost[e1.v] + e2.c < cost[e2.v])
				{
					cost[e2.v] = cost[e1.v] + e2.c;
					prec[e2.v] = e1.v;
					inter[e2.v] = inter[e1.v] + 1;
					q.push(node(e2.v, e2.d, cost[e2.v]));
				}
				else if (cost[e1.v] + e2.c == cost[e2.v] && inter[e1.v] + 1 < inter[e2.v])
				{
					prec[e2.v] = e1.v;
					inter[e2.v] = inter[e1.v] + 1;
				}
			}
		}
	}
}
//倒序打印路径，由于存储时是从终点往起点存的，所以要倒序打印
void printpath(vector<int>& v)
{
	for (int i = v.size() - 1; i >= 0; i--)
	{
		cout << v[i];
		if (i) cout << " -> ";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < 505; i++)
		for (int j = 0; j < 505; j++)
			ed[i][j] = ec[i][j] = inf;
	graph.resize(n);
	pred = vector<int>(n, -1);
	prec = vector<int>(n, -1);
	for (int i = 0; i < m; i++)
	{
		int v1, v2, oneway, d, c;
		cin >> v1 >> v2 >> oneway >> d >> c;
		graph[v1].emplace_back(node(v2, d, c));
		ed[v1][v2] = min(d, ed[v1][v2]);
		ec[v1][v2] = min(c, ec[v1][v2]);
		if (!oneway)
		{
			graph[v2].emplace_back(node(v1, d, c));
			ed[v2][v1] = min(d, ed[v2][v1]);
			ec[v2][v1] = min(c, ec[v2][v1]);
		}
	}
	cin >> src >> des;
	dijkstra(1);
	dijkstra(0);
	t = des;
	while (t >= 0)
	{
		shortestpath.emplace_back(t);
		t = pred[t];
	}
	t = des;
	while (t >= 0)
	{
		fastestpath.emplace_back(t);
		t = prec[t];
	}
	if (shortestpath == fastestpath)
	{
		cout << "Distance = " << dist[des] << "; Time = " << cost[des] << ": ";
		printpath(shortestpath);
	}
	else
	{
		cout << "Distance = " << dist[des] << ": ";
		printpath(shortestpath);
		cout << "\nTime = " << cost[des] << ": ";
		printpath(fastestpath);
	}
	return 0;
}
