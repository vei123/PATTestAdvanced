#include<iostream>
#include<vector>
using namespace std;

//看似与质数有关，但实际上与判定质数没有什么关系，并且如果用了质数还会超时

vector<vector<int>> v;

signed main()
{
	int n, r;
	cin >> n;
	cout << n << '=';
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	int m = n;
	for (int i = 2; i <= m / i; i++)
	{
		if (n % i == 0)
		{
			int exp = 1;
			n /= i;
			while (n % i == 0)
			{
				exp++;
				n /= i;
			}
			v.push_back({ i,exp });
		}
		if (n == 1) break;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (i) cout << '*';
		if (v[i][1] == 1)
			cout << v[i][0];
		else
			cout << v[i][0] << '^' << v[i][1];
	}
	if (n != 1)
	{
		if (v.size()) cout << '*' << n;
		else cout << n;
	}
	return 0;
}
