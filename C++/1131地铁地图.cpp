#include<cstdio>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#define inf 0x3fffffff
using namespace std;
/*
如果没有中转站的判定，那么这道题很简单，是一道dijk的模板题，
但是由于有中转站，如果不加以处理，将无法在dijkstra内部就选择出最优
路径，所以我们只在dijkstra内部完成最短距离下前驱数组的记录，再根据前驱
数组作DFS，找出同时满足距离最小，且最小距离下最少中转的路径，最后再打印路径
关键点：
一、无法在Dijkstra中一次性完成最优路径选择，除非对图进行改造
二、每次在输入一条地铁线路时，就用unordered_map记录相邻两个站点之间的所属线路
三、用DFS对Dijkstra所得的前驱数组进行搜索，找出最优路线
*/
struct node
{
	int v, w;
	bool operator<(const node& e) const { return w > e.w; }
};

//不会变化的数据
int n, m, k;
vector<vector<node>> graph;
unordered_map<int, int> line; //用第一个int的十进制高4位表示站号x，低四位表示站号y，第二个int表示x->y的所属线路号，没有线路则为0
//每次询问会更新的数据
int src, des, d[10000], visit[10000] = { 0 };
int mindis = inf, mintrans = inf;
vector<int> path, tmp;
vector<vector<int>> pre;

//获取两个站点之间的线路号
inline int getlineno(int x, int y) { return line[10000 * x + y]; }

void dijkstra()
{
	for (int i = 0; i < 10000; i++) d[i] = inf;
	for (int i = 0; i < 10000; i++) visit[i] = 0;
	d[src] = 0;
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
				pre[e2.v].clear();
				pre[e2.v].emplace_back(e1.v);
				q.push(node{ e2.v, d[e2.v] });
			}
			else if (d[e1.v] + e2.w == d[e2.v])
				pre[e2.v].emplace_back(e1.v);
		}
	}
}

//根据dijkstra记录的前驱数组，找出最佳路线
void dfs(int y = des, int z = -1, int dis = 0, int trans = 0)
{
	tmp.emplace_back(y);
	if (y == src)
	{
		if (dis < mindis || (dis == mindis && trans < mintrans))
		{
			mindis = dis;
			mintrans = trans;
			path = tmp;
		}
	}
	else
	{
		for (int x : pre[y])
		{
			int t;
			if (z == -1 || getlineno(x, y) == getlineno(y, z)) t = 0;
			else t = 1;
			dfs(x, y, dis + 1, trans + t);
		}
	}
	tmp.pop_back();
}

//每次询问之前，初始化变量，重新计算
void init()
{
	pre.clear();
	pre.resize(10000);
	path.clear();
	tmp.clear();
	mindis = mintrans = inf;
}

signed main()
{
	scanf("%d", &n);
	graph.resize(10000);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		int u, v, t;
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &t);
			if (j)
			{
				u = v;
				v = t;
				graph[u].emplace_back(node{ v, 1 });
				graph[v].emplace_back(node{ u, 1 });
				line[10000 * u + v] = line[10000 * v + u] = i;
			}
			else v = t;
		}
	}
	scanf("%d", &k);
	while (k--)
	{
		scanf("%d %d", &src, &des);
		int u, v, lineno, len, t = des;
		init();
		dijkstra();
		dfs();
		reverse(path.begin(), path.end());
		printf("%d\n", d[des]);
		v = path[0], len = path.size();
		for (int i = 1; i < len - 1; i++)
		{
			if (getlineno(path[i - 1], path[i]) != getlineno(path[i], path[i + 1]))
			{
				u = v, v = path[i], lineno = getlineno(path[i - 1], path[i]);
				printf("Take Line#%d from %04d to %04d.\n", lineno, u, v);
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", getlineno(path[len - 2], path.back()), v, path.back());
	}
	return 0;
}
