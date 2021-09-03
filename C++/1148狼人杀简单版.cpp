#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
//枚举说谎的两人，并依此填出玩家身份，先选出确定的狼人，如果没满2人，再从不确定的人里加
int n, s[105], p[105];
vector<int> t, wolfs(2, 101);

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			bool invalid = 0;
			memset(p, 0, 420);
			t.clear();
			for (int k = 1; k <= n; k++)
			{
				if (k == i || k == j)
				{
					if (p[abs(s[k])])
					{
						if (p[abs(s[k])] * s[k] > 0)
						{
							invalid = 1;
							break;
						}
					}
					else p[abs(s[k])] = (s[k] < 0 ? 1 : -1);
				}
				else
				{
					if (p[abs(s[k])])
					{
						if (p[abs(s[k])] * s[k] < 0)
						{
							invalid = 1;
							break;
						}
					}
					else p[abs(s[k])] = (s[k] > 0 ? 1 : -1);
				}
			}
			if (!invalid)
			{
				for (int k = 1; k <= n; k++)
				{
					if (p[k] == -1) t.emplace_back(k);
				}
				if (t.size() < 2)
				{
					for (int k = 1; k <= n; k++)
					{
						if (p[k] == 0)
						{
							t.emplace_back(k);
							if (t.size() == 2) break;
						}
					}
				}
			}
			if (t.size() == 2)
			{
				sort(t.begin(), t.end());
				if ((i == t[0] && j != t[1]) || (i != t[0] && j == t[1]) || (i == t[1] && j != t[0]) || (i != t[1] && j == t[0]))
				{
					if (t < wolfs) wolfs = t;
				}
			}
		}
	}
	if (wolfs == vector<int>{101, 101}) cout << "No Solution";
	else cout << wolfs[0] << ' ' << wolfs[1];
	return 0;
}
