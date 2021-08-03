#include<iostream>
#include<unordered_map>
#include<queue>
#define iipair pair<int,int>
#define inf 0x7fffffff
using namespace std;

struct cmp
{
	bool operator()(const iipair& a, const iipair& b)
	{
		return a.second > b.second;
	}
};

int n, m, c1, c2;
int d[505];
int teams[505];
int mincost = inf;
int maxhands = 0;
int paths = 0;
unordered_map<int, vector<iipair>> graph;
priority_queue<iipair, vector<iipair>, cmp> q;

void dfs(int s, int cost, int hands,
	unordered_map<int, int> visited)
{
	if (cost > mincost) return;
	visited[s] = 1;
	hands += teams[s];
	if (s == c2)
	{
		if (cost == mincost)
		{
			paths++;
			maxhands = hands > maxhands ? hands : maxhands;
		}
		return;
	}
	for (auto e : graph[s])
	{
		if (!visited[e.first])
			dfs(e.first, cost + e.second, hands, visited);
	}
	visited[s] = 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m >> c1 >> c2;
	for (int i = 0; i < n; i++)
	{
		d[i] = inf;
		cin >> teams[i];
	}
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		if (!graph.count(u)) graph[u] = vector<iipair>();
		if (!graph.count(v)) graph[v] = vector<iipair>();
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}
	q.push({ c1,0 });
	while (!q.empty())
	{
		iipair e = q.top();
		q.pop();
		if (d[e.first] != inf) continue;
		d[e.first] = e.second;
		for (auto l : graph[e.first])
		{
			if (d[l.first] != inf) continue;
			else q.push({ l.first, l.second + e.second });
		}
	}
	mincost = d[c2];
	dfs(c1, 0, 0, unordered_map<int, int>());
	cout << paths << " " << maxhands;
	return 0;
}
