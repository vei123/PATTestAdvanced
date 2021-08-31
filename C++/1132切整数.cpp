#include<iostream>
#include<string>
using namespace std;

signed main()
{
	ios::sync_with_stdio(0);
	int n;
	string s;
	cin >> n;
	while (n--)
	{
		cin >> s;
		int len = s.size();
		int c = stoi(s);
		int a = stoi(s.substr(0, len / 2));
		int b = stoi(s.substr(len / 2, len / 2));
		if (!(a*b)) cout << "No\n";
		else if (!(c % (a*b))) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
