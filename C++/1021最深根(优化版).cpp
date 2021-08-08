#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int n, u, v, t;
int f[10005];
int maxdepth = 0;
//邻接表存储图
vector<vector<int>> graph;
//存储第一次深搜中所有最远的结点
vector<int> ans1;
//存储第二次深搜中所有最远的结点
vector<int> ans2;
//标记结点访问情况，避免重复访问
int isvisited[10005] = { 0 };
unordered_map<int, int> umap;

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

void dfs(int u, int curdepth, vector<int>& a)
{
	if (curdepth > maxdepth)
	{
		maxdepth = curdepth;
		a.clear();
		a.push_back(u);
	}
	else if (curdepth == maxdepth)
		a.push_back(u);
	isvisited[u] = 1;
	for (int i : graph[u])
	{
		if (!isvisited[i])
			dfs(i, curdepth + 1, a);
	}
	isvisited[u] = 0;
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
		graph[v].push_back(u);
		f[getroot(u)] = getroot(v);
	}
	t = countconnectedcomponents();
	if (t > 1)
	{
		cout << "Error: " << t << " components";
		return 0;
	}
	dfs(1, 0, ans1);
	maxdepth = 0;
	dfs(ans1[0], 0, ans2);
	int len = ans1.size() + ans2.size(), cnt = 0;
	for (int i : ans1) umap[i] = 1;
	for (int i : ans2) umap[i] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (umap[i])
		{
			cout << i;
			cnt++;
			if (cnt != len) cout << '\n';
		}
	}
	return 0;
}
