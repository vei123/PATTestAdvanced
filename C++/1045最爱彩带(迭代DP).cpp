#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

//迭代DP，复杂度O(nm)，n为原始彩带数量(实际上可以先将不属于最爱颜色的颜色
//去掉，可以适当优化，如本程序下面的某一步，只需加个判断)，m为最爱的颜色
//顺序的序列长度
//思路：假如彩带的区块索引i和颜色序列索引j所对应的颜色做匹配：
//如果v[i]==o[j]，即颜色一样，那么只需要将i加一，即不改变当前颜色再
//继续判断下一个位置，这是当前状态下的最优策略
//如果v[i]!=o[j]，即当前颜色与当前位置的颜色不一样，那就有两种策略：
//①颜色不变，换下一个位置再判断
//②位置不变，换最爱彩带序列中的下一个颜色再判断
//然后只需取上面两种策略的最大值即可

int n, m, l, t;
//存放最爱的颜色序列
int o[205];
//存放去掉无关颜色的彩带
vector<int> v;
//存放最爱的颜色，以筛掉无关颜色
unordered_set<int> colors;
//迭代DP状态数组，在递归DP中仍需使用此数组
int d[10005][205];

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> m;
	memset(d, 0, sizeof(d));
	for (int i = 0; i < m; i++)
	{
		cin >> o[i];
		colors.insert(o[i]);
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		cin >> t;
    //筛去无关颜色
		if (colors.count(t)) v.emplace_back(t);
	}
	for (int i = 1; i <= v.size(); i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (v[i - 1] == o[j - 1]) //如果颜色相同，只改变位置
				d[i][j] = 1 + d[i - 1][j];
			else //否则取两种策略中的最大值
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}
	cout << d[v.size()][m];
	return 0;
}
