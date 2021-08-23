#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int n, m, root = 0;
int maxnum = 0, maxlevel = 0;
bool notroot[105] = { 0 };
vector<vector<int>> v;

void bfs(int r)
{
	queue<int> q;
	q.push(r);
	int level = 1;
	while (!q.empty())
	{
		int len = q.size();
		if (len > maxnum)
		{
			maxnum = len;
			maxlevel = level;
		}
		while (len--)
		{
			int t = q.front();
			q.pop();
			for (int& i : v[t]) q.push(i);
		}
		level++;
	}
}

signed main()
{
	scanf("%d%d", &n, &m);
	v.resize(n + 1);
	while (m--)
	{
		int id, k;
		scanf("%d %d", &id, &k);
		while (k--)
		{
			v[id].emplace_back(0);
			scanf("%d", &v[id].back());
			notroot[v[id].back()] = 1;
		}
	}
	while (notroot[++root]);
	bfs(root);
	printf("%d %d", maxnum, maxlevel);
	return 0;
}
