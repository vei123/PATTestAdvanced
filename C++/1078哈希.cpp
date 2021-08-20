#include<iostream>
#include<vector>
using namespace std;

//先判断出1~10007中哪些是质数，哪些是合数，方便之后改变大小
//然后对输入的数据依次判断存放位置，如果冲突就使用只有正增量平方探测法解决
//正增量平方探测法：
//①判断原位置(设为pos)是否冲突，不冲突就存放，结束，否则转②
//②设i从1开始，依次计算(i*i+pos)%m的位置是否冲突，不冲突就存放，否则
//继续计算当i=2、3、4...是否冲突，直到不冲突(找到合适位置)
//或(i*i+pos)%m的值回到了原位置pos(即没有找到合适位置，应该输出'-')

int p[10008] = { 0 };

void sieve()
{
	p[0] = p[1] = 1;
	for (int i = 2; i < 10008; i++)
	{
		if (!p[i])
		{
			for (int j = 2; i*j < 10008; j++)
				p[i*j] = 1;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	int m, n;
	cin >> m >> n;
	sieve();
	if (p[m])
	{
		for (int i = m + 1; i <= 10007; i++)
		{
			if (!p[i])
			{
				m = i;
				break;
			}
		}
	}
	vector<int> hash(m, 0);
	while (n--)
	{
		int t, pos;
		cin >> t;
		pos = t % m;
		if (hash[pos])
		{
			bool find = 0;
			for (int i = 1; ; i++)
			{
				int npos = (pos + i * i) % m;
				if (npos == pos) break;
				if (!hash[npos])
				{
					hash[npos] = t;
					cout << npos;
					find = 1;
					break;
				}
			}
			if (!find) cout << '-';
		}
		else
		{
			hash[pos] = t;
			cout << pos;
		}
		if (n) cout << ' ';
	}
	return 0;
}
