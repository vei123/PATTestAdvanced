#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#define iipair pair<int,int>
#define inf 0x3fffffff
using namespace std;

struct path
{
	vector<int> trail;
	int send, fetch;
	int curnum;
	path() :
		send(0), fetch(0), curnum(0), trail(vector<int>()) { }
	path(const path& p)
	{
		this->trail = vector<int>(p.trail);
		this->send = p.send;
		this->fetch = p.fetch;
		this->curnum = p.curnum;
	}
};

struct cmpforpair
{
	bool operator()(const iipair& a, const iipair& b)
	{
		return a.second > b.second;
	}
};

struct cmpforpath
{
	bool operator()(const path& a, const path& b)
	{
		if (a.send != b.send) return a.send > b.send;
		else return a.fetch > b.fetch;
	}
};

int cmax, n, sp, m;
//存储每个站点的自行车数量
int bikes[505] = { 0 };
//存储单源最短路，源点为0
int d[505];
//用哈希表存储图的邻接表结构
unordered_map<int, vector<iipair>> graph;
//优先队列存储边集，为Dijkstra作堆优化
priority_queue<iipair, vector<iipair>, cmpforpair> q;
//存储所有时间最优路径
priority_queue<path, vector<path>, cmpforpath> paths;
//标记深搜过程中访问过的点
int isvisited[505] = { 0 };

//深搜找出所有时间最优路径
void dfs(int s, int cost, path road)
{
	//剪枝提升效率
	if (cost > d[sp]) return;
	//存储路径状态以备还原
	path mem = path(road);
	road.trail.push_back(s);
	//标记访问
	isvisited[s] = 1;
	//如果多于一半就拿走
	if (bikes[s] >= cmax / 2)
		road.curnum += bikes[s] - cmax / 2;
	else //如果少于一半就补充
	{
		//如果现有的自行车数量不够, 就增加初始携带数量
		if (road.curnum < cmax / 2 - bikes[s])
		{
			road.send += cmax / 2 - bikes[s] - road.curnum;
			road.curnum = 0;
		}
		else //如果够，就直接补充
			road.curnum -= cmax / 2 - bikes[s];
	}
	//如果到达了终点就存储此条路径(一定不会重复)
	if (s == sp)
	{
		road.fetch = road.curnum;
		paths.push(road);
	}
	else //否则继续扩展搜索
	{
		for (auto p : graph[s])
		{
			if (!isvisited[p.first])
				dfs(p.first, cost + p.second, road);
		}
	}
	//还原节点访问状态
	isvisited[s] = 0;
	//还原路径状态
	road = path(mem);
}

void printpath(path road)
{
	cout << road.send << ' ';
	for (int i = 0; i < road.trail.size(); i++)
	{
		cout << road.trail[i];
		if (i != road.trail.size() - 1) cout << "->";
	}
	cout << ' ' << road.fetch;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> cmax >> n >> sp >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> bikes[i];
		d[i] = inf;
	}
	bikes[0] = cmax / 2;
	d[0] = inf;
	for (int i = 0; i < m; i++)
	{
		int si, sj, tij;
		cin >> si >> sj >> tij;
		if (!graph.count(si)) graph[si] = vector<iipair>();
		graph[si].push_back({ sj, tij });
		if (!graph.count(sj)) graph[sj] = vector<iipair>();
		graph[sj].push_back({ si, tij });
	}
	q.push({ 0, 0 });
	while (!q.empty())
	{
		auto e = q.top();
		q.pop();
		if (d[e.first] != inf) continue;
		d[e.first] = e.second;
		for (auto l : graph[e.first])
		{
			if (d[l.first] != inf) continue;
			else q.push({ l.first, l.second + e.second });
		}
	}
	dfs(0, 0, path());
	printpath(paths.top());
	return 0;
}
