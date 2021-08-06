#include<iostream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

bool isprime(int n)
{
	if (n <= 1) return 0;
	if (n == 2) return 1;
	for (int i = 2; i <= (int)sqrt(n); i++)
		if (n % i == 0) return 0;
	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	int n, d;
	vector<string> res;
	while (cin >> n)
	{
		if (n < 0) break;
		cin >> d;
		if (isprime(n))
		{
			vector<int> t;
			int c = 1, s = 0;
			while (n)
			{
				t.push_back(n % d);
				n /= d;
			}
			for (int i = t.size() - 1; i >= 0; i--)
			{
				s += t[i] * c;
				c *= d;
			}
			if (isprime(s))
				res.push_back("Yes");
			else
				res.push_back("No");
		}
		else
			res.push_back("No");
	}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
		if (i != res.size() - 1) cout << "\n";
	}
	return 0;
}
