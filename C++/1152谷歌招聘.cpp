#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int l, k, n;
string s, t;

bool isprime(int i)
{
	if (i <= 1) return 0;
	if (i == 2) return 1;
	for (int j = 2; j <= (int)sqrt(i); j++)
		if (i%j == 0) return 0;
	return 1;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> l >> k;
	cin >> s;
	if (s.size() < k)
	{
		cout << 404 << '\n';
		return 0;
	}
	t = s.substr(0, k);
	n = stoi(t);
	if (isprime(n))
	{
		cout << t << '\n';
		return 0;
	}
	else
	{
		for (int i = k; i < s.size(); i++)
		{
			t.erase(0, 1);
			t.push_back(s[i]);
			n = stoi(t);
			if (isprime(n))
			{
				cout << t << '\n';
				return 0;
			}
		}
	}
	cout << 404 << '\n';
	return 0;
}
