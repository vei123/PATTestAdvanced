#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int n, b;
vector<int> v;
queue<int> q;
stack<int> s;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> b;
	while (n)
	{
		v.push_back(n % b);
		s.push(n % b);
		q.push(n % b);
		n /= b;
	}
	while (!s.empty())
	{
		if (s.top() != q.front())
		{
			cout << "No\n";
			break;
		}
		s.pop();
		q.pop();
	}
	if (s.empty()) cout << "Yes\n";
	for (int i = v.size() - 1; i >= 0; i--)
	{
		cout << v[i];
		if (i) cout << ' ';
	}
	return 0;
}
