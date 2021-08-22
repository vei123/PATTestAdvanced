#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#define inf 0x3fffffff
using namespace std;

//类似于PAT甲级1030，Dijkstra加DFS

struct node
{
	int v, w;
	node(int v, int w) :v(v), w(w) {  }
	bool operator<(const node& n) const { return w > n.w; }
};

int n, k, t, c1, c2;
int cnt = 1, h[205], d[205], visit[205] = { 0 };
int maxhappy = 0, routes = 0;
string s, s1, s2;
vector<vector<node>> graph;
vector<vector<int>> pre;
vector<int> path;
vector<vector<int>> paths;
unordered_map<string, int> f1;
unordered_map<int, string> f2;

inline void dijkstra()
{
	for (int i = 0; i < n; i++) d[i] = inf;
	d[0] = 0;
	priority_queue<node> q;
	q.push(node{ 0,0 });
	while (!q.empty())
	{
		auto e1 = q.top();
		q.pop();
		if (visit[e1.v]) continue;
		visit[e1.v] = 1;
		for (auto& e2 : graph[e1.v])
		{
			if (e2.w + d[e1.v] < d[e2.v])
			{
				d[e2.v] = e2.w + d[e1.v];
				pre[e2.v].clear();
				pre[e2.v].emplace_back(e1.v);
				q.push(node(e2.v, d[e2.v]));
			}
			else if (e2.w + d[e1.v] == d[e2.v])
				pre[e2.v].emplace_back(e1.v);
		}
	}
}

void dfs(int p = f1["ROM"], int happy = h[f1["ROM"]])
{
	path.emplace_back(p);
	if (p)
	{
		for (int& i : pre[p])
			dfs(i, happy + h[i]);
	}
	else
	{
		routes++;
		if (happy > maxhappy)
		{
			maxhappy = happy;
			paths.clear();
			paths.emplace_back(path);
		}
		else if (happy == maxhappy)
			paths.emplace_back(path);
	}
	path.pop_back();
}

bool cmp(vector<int>& a, vector<int>& b) { return a.size() < b.size(); }

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> k >> s;
	graph.resize(n);
	pre.resize(n);
	f1[s] = 0, f2[0] = s;
	for (int i = 1; i < n; i++)
	{
		cin >> s >> h[i];
		f1[s] = cnt, f2[cnt] = s;
		cnt++;
	}
	for (int i = 0; i < k; i++)
	{
		cin >> s1 >> s2 >> t;
		c1 = f1[s1], c2 = f1[s2];
		graph[c1].emplace_back(node(c2, t));
		graph[c2].emplace_back(node(c1, t));
	}
	dijkstra();
	dfs();
	sort(paths.begin(), paths.end(), cmp);
	cout << routes << ' ' << d[f1["ROM"]] << ' ';
	cout << maxhappy << ' ' << maxhappy / (paths[0].size() - 1) << '\n';
	reverse(paths[0].begin(), paths[0].end());
	for (int i = 0; i < paths[0].size(); i++)
	{
		if (i) cout << "->";
		cout << f2[paths[0][i]];
	}
	return 0;
}
