#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

int k, len;
char c;
string s;
unordered_set<char> all, notstucked, likely, printed;
vector<char> v;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> k >> s;
	len = s.size();
	for (int i = 0; i < len;)
	{
		all.insert(s[i]);
		c = s[i];
		int j = i + 1;
		while (j < len && s[j] == c) j++;
		if ((j - i) % k) notstucked.insert(c);
		else 
		{
			likely.insert(c);
			v.emplace_back(c);
		}
		i = j;
	}
	for (char ch : v)
		if (!notstucked.count(ch) && !printed.count(ch))
		{
			printed.insert(ch);
			cout << ch;
		}
	for (int i = 0; i < s.size();)
	{
		if (!notstucked.count(s[i]) && likely.count(s[i]))
		{
			int j = i + 1;
			for (int l = 1; l < k; l++) s.erase(j, 1);
			i = j;
		}
		else i++;
	}
	cout << '\n' << s;
	return 0;
}
