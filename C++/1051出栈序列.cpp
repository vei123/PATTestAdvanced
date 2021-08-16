#include<iostream>
#include<stack>
using namespace std;

int m, n, k, t;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> m >> n >> k;
	while (k--)
	{
		bool flag = 1;
		stack<int> stk;
		//下一个入栈数
		int in = 1;
		for (int i = 0; i < n; i++)
		{
			//下一个出栈数
			cin >> t;
			//如果下一个出栈数大于等于下一个入栈数，就依次入栈，并判断是否超过容量m，最后出栈一个数
			if (t >= in)
			{
				for (int j = in; j <= t; j++) stk.push(j);
				in = t + 1;
				if (stk.size() > m)
				{
					while (++i < n) cin >> t;
					flag = 0;
					break;
				}
				stk.pop();
			}
			//否则下一个出栈数小于下一个入栈数，说明下一个出栈数已入栈，就看栈顶是不是这个数
			else
			{
				if (stk.top() == t)
					stk.pop();
				else
				{
					while (++i < n) cin >> t;
					flag = 0;
					break;
				}
			}
		}
		if (flag) cout << "YES";
		else cout << "NO";
		if (m) cout << '\n';
	}
	return 0;
}
