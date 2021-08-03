#include<iostream>
#include<unordered_map>
#define iipair pair<int,int>
using namespace std;

int f[105];
int res[105];
unordered_map<int, iipair> graph;

int getroot(int id, int dis = 0)
{
	if (f[id] == id) return dis;
	else return getroot(f[id], dis + 1);
}

int main()
{
	ios::sync_with_stdio(0);
	int n, m, id, idt;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) f[i] = i;
	while (m--)
	{
		cin >> id;
		if (!graph.count(id))
			graph[id] = iipair(0, 0);
		int k;
		cin >> k;
		while (k--)
		{
			cin >> idt;
			if (!graph.count(idt))
				graph[idt] = iipair(0, 0);
			graph[id].second++;
			f[idt] = id;
		}
	}
	int maxdepth = 0;
	for (int i = 1; i <= n; i++)
	{
		graph[i].first = getroot(i);
		maxdepth = graph[i].first > maxdepth ? graph[i].first : maxdepth;
		if (!graph[i].second) res[graph[i].first]++;
	}
	for (int i = 0; i <= maxdepth; i++)
	{
		cout << res[i];
		if (i != maxdepth) cout << " ";
	}
	return 0;
}
