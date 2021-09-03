#include<iostream>
#include<iomanip>
using namespace std;

int s, n, m, t, cnt = 0, a[10008] = { 0 }, prime[10008] = { 0 };

void sieve()
{
	prime[1] = 1;
	for (int i = 2; i < 10008; i++)
	{
		if (!prime[i])
		{
			for (int j = 2; i*j < 10008; j++)
				prime[i*j] = 1;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> s >> n >> m;
	sieve();
	while (prime[s]) s++;
	while (n--)
	{
		cin >> t;
		int p = t % s;
		if (a[p])
		{
			int i = 1;
			for (; i < s; i++)
			{
				if (!a[(p + i * i) % s])
				{
					a[(p + i * i) % s] = t;
					break;
				}
			}
			if (i == s) cout << t << " cannot be inserted.\n";
		}
		else a[p] = t;
	}
	for (int k = 0; k < m; k++)
	{
		cin >> t;
		int p = t % s, i = 0;
		for (; i < s; i++)
		{
			if (a[(p + i * i) % s] == t || !a[(p + i * i) % s]) break;
		}
		cnt += i + 1;
	}
	cout << fixed << setprecision(1);
	cout << 1.0 * cnt / m;
	return 0;
}
