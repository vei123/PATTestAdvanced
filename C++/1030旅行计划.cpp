#include<iostream>
#include<vector>
#include<queue>
#define inf 0x3fffffff
using namespace std;

struct node
{
	int v, w;
	node(int v, int w) :v(v), w(w) {  }
	bool operator<(const node& x) const { return this->w > x.w; }
};

int n, m, s, d;
//最小花费
int mincost = inf;
int dis[505];
bool visit[505] = { 0 };
//城市道路花费表
int cost[505][505];
//图的邻接表
vector<vector<node>> graph;
//路径上结点的前驱数组
vector<vector<int>> pre;
//堆优化要用到的优先队列
priority_queue<node> q;
//存储临时路径和最佳路径的数组
vector<int> temppath, bestpath;

//对堆优化的dijkstra算法做下改变，使其能够记录每个结点的前驱结点，并写入pre
inline void dijkstra()
{
	for (int i = 0; i < n; i++) dis[i] = inf;
	dis[s] = 0;
	q.push(node(s, 0));
	while (!q.empty())
	{
		auto e1 = q.top();
		q.pop();
		if (visit[e1.v]) continue;
		visit[e1.v] = 1;
		for (auto e2 : graph[e1.v])
		{
			if (dis[e2.v] > dis[e1.v] + e2.w)
			{
				dis[e2.v] = dis[e1.v] + e2.w;
				q.push(node(e2.v, dis[e1.v] + e2.w));
				pre[e2.v].clear();
				pre[e2.v].push_back(e1.v);
			}
			else if (dis[e2.v] == dis[e1.v] + e2.w)
				pre[e2.v].push_back(e1.v);
		}
	}
}

//从目的城市结点开始，根据pre数组向起始城市深搜最小花费
void dfs(int curnode, int curcost, vector<int>& t)
{
	//剪枝优化
	if (curcost > mincost) return;
	t.push_back(curnode);
	//如果当前结点为起始结点，计算并结束
	if (curnode == s)
	{
		if (curcost < mincost)
		{
			mincost = curcost;
			bestpath = t;
		}
	}
	//对当前的每个结点的前驱继续深搜，如果是起点，则会自动跳过
	for (int i : pre[curnode])
		dfs(i, curcost + cost[i][curnode], t);
	t.pop_back();
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &d);
	//由于城市编号从0开始，故只需大小为n的vector数组
	graph.resize(n);
	pre.resize(n);
	for (int i = 0; i < m; i++)
	{
		int u, v, w, c;
		scanf("%d%d%d%d", &u, &v, &w, &c);
		graph[u].push_back(node(v, w));
		graph[v].push_back(node(u, w));
		cost[u][v] = cost[v][u] = c;
	}
	dijkstra();
	dfs(d, 0, temppath);
	//倒序输出路径
	for (int i = bestpath.size() - 1; i >= 0; i--)
		printf("%d ", bestpath[i]);
	printf("%d %d", dis[d], mincost);
	return 0;
}
