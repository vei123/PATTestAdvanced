#include<iostream>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	int n, r;
	int l = 0;
	int time = 0;
	cin >> n;
	while (n--)
	{
		cin >> r;
		time += r > l ? 6 * (r - l) + 5 : 4 * (l - r) + 5;
		l = r;
	}
	cout << time;
	return 0;
}
