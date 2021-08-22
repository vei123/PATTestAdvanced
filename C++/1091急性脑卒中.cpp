#include<iostream>
#include<queue>
#define int short
using namespace std;
/*
连通体问题，一般用搜索的方式解决，需要设置标记是否访问过的变量来减少重复
此题值得注意的几个问题：
一、空间限制很严格，一个int a[61][1287][129]就快爆内存了，两个绝对不行，
所以只能用一个int三维数组解决问题，如果想要用两个数组，需要声明为short型数组，
但是同时注意有些变量必须仍然用int，不然可能溢出
二、不能使用DFS，由于数组可能很大，DFS存在递归过深的问题，会报段错误，
解决方法是只能换一个方法：用BFS，可以迭代搜索，避免了过度调用系统栈而引发的递归过深问题
复杂度分析：O(l*m*n)，即每个点大约访问常数次
*/
struct point { int k, i, j; };

int m, n, l, t;
signed vol = 0, total = 0;
int a[61][1287][129], vt[61][1287][129] = { 0 };

inline bool inbound(int k, int i, int j)
{
	return k>=1 && k<=l && i>=1 && i<=m && j>=1 && j<=n;
}
/*DFS是不行的，会在样例5、6报段错误，因为递归过深
void dfs(int k, int i, int j)
{
	if (vt[k][i][j]) return;
	vt[k][i][j] = 1;
	if (!a[k][i][j]) return;
	else vol += 1;
	if (inbound(k - 1, i, j)) dfs(k - 1, i, j);
	if (inbound(k + 1, i, j)) dfs(k + 1, i, j);
	if (inbound(k, i - 1, j)) dfs(k, i - 1, j);
	if (inbound(k, i + 1, j)) dfs(k, i + 1, j);
	if (inbound(k, i, j - 1)) dfs(k, i, j - 1);
	if (inbound(k, i, j + 1)) dfs(k, i, j + 1);
}
*/
void bfs(int k, int i, int j)
{
	queue<point> q;
	q.push({ k,i,j });
	while (!q.empty())
	{
		signed len = q.size();
		while (len--)
		{
			point p = q.front();
			q.pop();
			k = p.k, i = p.i, j = p.j;
			if (!vt[k][i][j])
			{
				vt[k][i][j] = 1;
				if (a[k][i][j]) vol++;
				else continue;
			}
			else continue;
			if (inbound(k - 1, i, j)) q.push({ k - 1,i,j });
			if (inbound(k + 1, i, j)) q.push({ k + 1,i,j });
			if (inbound(k, i - 1, j)) q.push({ k,i - 1,j });
			if (inbound(k, i + 1, j)) q.push({ k,i + 1,j });
			if (inbound(k, i, j - 1)) q.push({ k,i,j - 1 });
			if (inbound(k, i, j + 1)) q.push({ k,i,j + 1 });
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> m >> n >> l >> t;
	for (int k = 1; k <= l; k++)
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				cin >> a[k][i][j];
	for (int k = 1; k <= l; k++)
	{
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (!vt[k][i][j] && a[k][i][j])
				{
					vol = 0;
					bfs(k, i, j);
					if (vol >= t) total += vol;
				}
			}
		}
	}
	cout << total;
	return 0;
}
