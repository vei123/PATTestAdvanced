#include<iostream>
using namespace std;

//一道数学题。看到数据量10^5，一定是线性复杂度，所以不能排序后再从小到大
//每次取两个数比较，这样复杂度O(n^2)一定会超时
//所以这样做：输入时顺便统计每种面值的硬币的数量，用数组v[]存储，
//因为数据都为整数，故可以从i=1开始到m/2，查找v[]中是否有面值为i和m-i的
//两种硬币，如果有就直接输出，特别的，对于i==m-i的情形需要v[i]>=2，即
//硬币数量超过2枚。由于i是从1开始的，故得到的一定是正确解
//如果循环结束了还没找到解，就自然"No Solution"

signed main()
{
	ios::sync_with_stdio(0);
	int n, m, t, v[1005] = { 0 };
	cin >> n >> m;
	while (n--)
	{
		cin >> t;
		v[t]++;
	}
	for (int i = 1; i <= m / 2; i++)
	{
		int j = m - i;
		if (i != j)
		{
			if (v[i] && v[j])
			{
				cout << i << ' ' << j;
				return 0;
			}
		}
		else
		{
			if (v[i] >= 2)
			{
				cout << i << ' ' << i;
				return 0;
			}
		}
	}
	cout << "No Solution";
	return 0;
}
