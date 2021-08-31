#include<iostream>
#include<string>
#include<vector>
#define iipair pair<int, int>
using namespace std;

signed main()
{
	ios::sync_with_stdio(0);
	string s;
	int n;
	cin >> s >> n;
	n--;
	while (n--)
	{
		vector<iipair> v;
		char ch = s[0];
		int cnt = 0;
		for (char c : s)
		{
			if (c != ch)
			{
				if (cnt)
					v.emplace_back(iipair{ int(ch) - '0', cnt });
				cnt = 0;
				ch = c;
			}
			if (ch == c) cnt++;
		}
		if (cnt) v.emplace_back(iipair{ int(ch) - '0', cnt });
		s.clear();
		for (auto& p : v)
		{
			s.push_back(char(p.first + '0'));
			s.push_back(char(p.second + '0'));
		}
	}
	cout << s;
	return 0;
}
