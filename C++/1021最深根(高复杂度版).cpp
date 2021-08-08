#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int n, u, v, t;
int f[10005];
int maxdepth = 0;
//存储结点的点度
int degree[10005] = { 0 };
//邻接表存储图
vector<vector<int>> graph;
//存储所有度数为1的结点的深度
int depth[10005] = { 0 };
//存储所有有着最大深度的结点
vector<int> ans;
//标记结点访问情况，避免重复访问
int isvisited[10005] = { 0 };

//并查集查询函数
int getroot(int i)
{
	return f[i] == i ? i : f[i] = getroot(f[i]);
}

//利用并查集计算连通分量数量
int countconnectedcomponents()
{
	int res = 0;
	for (int i = 1; i <= n; i++)
		if (f[i] == i) res++;
	return res;
}

//对1度结点深搜，搜寻最大深度
//src为源点，用depth[src]记录从src结点出发的最大深度
void dfs(int& src, int u, int curdepth)
{
	if (curdepth >= maxdepth)
	{
		maxdepth = curdepth;
		depth[src] = curdepth;
	}
	isvisited[u] = 1;
	for (int i : graph[u])
	{
		if (!isvisited[i])
			dfs(src, i, curdepth + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	graph.resize(n + 1);
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i < n; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		degree[u]++;
		graph[v].push_back(u);
		degree[v]++;
		f[getroot(u)] = getroot(v);
	}
	t = countconnectedcomponents();
	if (t > 1)
	{
		cout << "Error: " << t << " components";
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 1)
		{
			memset(isvisited, 0, sizeof(isvisited));
			dfs(i, i, 0);
		}
	}
	for (int i = 1; i <= n; i++)
		if (depth[i] == maxdepth) ans.push_back(i);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
		if (i != ans.size() - 1) cout << '\n';
	}
	return 0;
}
