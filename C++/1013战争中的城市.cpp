#include<cstdio>
#include<vector>
using namespace std;

int n, m, k;
int f[1005];
vector<vector<int>> edges;

//并查集的查询函数，注意一定要动态调整并查集结构以优化
//查询速度，否则会超时
int getroot(int i)
{
	return f[i] == i ? i : f[i] = getroot(f[i]);
}

//构造并查集，计数连通分量个数，O(N+M)的复杂度
inline int unionset(int s)
{
	int res = 0;
	for (int i = 0; i <= n; i++) f[i] = i;
	for (int i = 0; i < m; i++)
	{
		int u = edges[i][0], v = edges[i][1];
		if (u != s && v != s)
			f[getroot(u)] = getroot(v);
	}
	for (int i = 1; i <= n; i++)
	{
		if (getroot(i) == i)
			res++;
	}
	return res;
}

int main()
{
	int u, v, s;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		edges.push_back({ u, v });
	}
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &s);
		printf("%d", unionset(s) - 2);
		if (i != k - 1) printf("\n");
	}
	return 0;
}
