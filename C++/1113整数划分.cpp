#include<iostream>
#include<queue>
using namespace std;

int n, t, sum1 = 0, sum = 0, ans1, ans2;
priority_queue<int> q;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		q.push(t);
		sum += t;
	}
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		sum1 += q.top();
		q.pop();
	}
	cout << n % 2 << ' ' << 2 * sum1 - sum;
	return 0;
}
