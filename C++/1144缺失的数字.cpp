#include<iostream>
using namespace std;

int n, t, a[100005] = { 0 }, i = 1;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	while (n--)
	{
		cin >> t;
		if (t > 0 && t < 100005) a[t] = 1;
	}
	while (a[i]) i++;
	cout << i;
	return 0;
}
