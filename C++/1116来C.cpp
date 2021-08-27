#include<iostream>
#include<iomanip>
using namespace std;

int n, id, k, r[10005] = { 0 }, prime[10005] = { 0 }, checked[10005] = { 0 };

void sieve()
{
	prime[1] = 1;
	for (int i = 2; i < 10001; i++)
	{
		if (!prime[i])
		{
			for (int j = 2; i*j < 10001; j++)
				prime[i*j] = 1;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	sieve();
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> id;
		r[id] = i + 1;
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> id;
		cout << setfill('0') << setw(4);
		cout << id << ": ";
		if (!r[id]) cout << "Are you kidding?";
		else if (checked[id]) cout << "Checked";
		else if (r[id] == 1) cout << "Mystery Award";
		else if (!prime[r[id]]) cout << "Minion";
		else cout << "Chocolate";
		checked[id] = 1;
		cout << '\n';
	}
	return 0;
}
