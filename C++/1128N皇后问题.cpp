#include<iostream>
#include<cmath>
using namespace std;
/*
只需判断每次皇后是否有同一行，或者在同一斜线上即可，
判断在同一行，即某两个数字相同，判断在同意斜线，即
两个数组元素值的差值的绝对值与它们下标的差值的绝对值相等
复杂度分析：O(k*n^2)
每次最大200个样例，每个样例最大1000，则总复杂度为：
200 * 1000^2 / 2 = 10e8，符合要求(测评机器的秒算力在
10e8~10e9之间)
如果希望想改善效率到O(k*n)，从4*n条对角线的唯一性入手
*/
int k, n, a[1005];

signed main()
{
	ios::sync_with_stdio(0);
	cin >> k;
	while (k--)
	{
		cin >> n;
		bool yes = 1;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (a[i] == a[j] || abs(a[i] - a[j]) == abs(i - j))
				{
					yes = 0;
					break;
				}
			}
		}
		if (yes) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
