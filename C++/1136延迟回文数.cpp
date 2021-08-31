#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

inline void delprezeros(string& t)
{
	while (!t.empty() && t[0] == '0') t.erase(0, 1);
}

bool ispalin(string& t)
{
	auto p1 = t.begin(), p2 = t.end() - 1;
	while (p1 < p2 && (*p1) == (*p2)) p1++, p2--;
	if (p1 >= p2) return 1;
	else return 0;
}

string stradd(string sa, string sb)
{
	string ans;
	int len = max(sa.size(), sb.size());
	int a[1005] = { 0 }, b[1005] = { 0 }, c[1005] = { 0 };
	reverse(sa.begin(), sa.end());
	reverse(sb.begin(), sb.end());
	for (int i = 0; i < sa.size(); i++) a[i] = int(sa[i] - '0');
	for (int i = 0; i < sb.size(); i++) b[i] = int(sb[i] - '0');
	for (int i = 0; i < len; i++)
	{
		c[i + 1] = (a[i] + b[i] + c[i]) / 10;
		c[i] = (a[i] + b[i] + c[i]) % 10;
	}
	for (int i = 0; i < len + 1; i++) ans.push_back(char(c[i] + '0'));
	reverse(ans.begin(), ans.end());
	delprezeros(ans);
	return ans;
}

signed main()
{
	ios::sync_with_stdio(0);
	string s;
	cin >> s;
	for (int i = 0; i < 10; i++)
	{
		if (ispalin(s))
		{
			cout << s << " is a palindromic number.\n";
			return 0;
		}
		string r = s, t;
		reverse(r.begin(), r.end());
		cout << s << " + " << r << " = " << (t = stradd(s, r)) << '\n';
		s = t;
	}
	cout << "Not found in 10 iterations.\n";
	return 0;
}
