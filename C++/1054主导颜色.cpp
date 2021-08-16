#include<iostream>
#include<unordered_map>
using namespace std;

int m, n, t;
int color = -1, cnt = 0;
unordered_map<int, int> freq;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> t;
			freq[t]++;
			if (freq[t] > cnt)
			{
				color = t;
				cnt = freq[t];
			}
		}
	}
	cout << color;
	return 0;
}
