#include<iostream>
using namespace std;
//并查集的模板题
int n, k, q, birds, trees = 0, f[10005];

int getroot(int i)
{
	return f[i] == i ? i : f[i] = getroot(f[i]);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= 10000; i++) f[i] = i;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		int a, b, t;
		for (int j = 0; j < k; j++)
		{
			cin >> t;
			if (t > birds) birds = t;
			if (j)
			{
				a = b, b = t;
				f[getroot(a)] = getroot(b);
			}
			else b = t;
		}
	}
	for (int i = 1; i <= birds; i++)
		if (f[i] == i) trees++;
	cout << trees << ' ' << birds << '\n';
	cin >> q;
	while (q--)
	{
		int a, b;
		cin >> a >> b;
		if (getroot(a) == getroot(b)) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
