#include<iostream>
#include<string>
#include<cstdlib>
#include<unordered_set>
using namespace std;

inline void alter(char& c)
{
	if (c >= 'a' && c <= 'z') c += 'A' - 'a';
}

signed main()
{
	ios::sync_with_stdio(0);
	string s1, s2, res;
	int i = 0, j = 0;
	unordered_set<char> uset;
	cin >> s1 >> s2;
	for (; i < s1.size() && j < s2.size();)
	{
		alter(s1[i]);
		alter(s2[j]);
		if (s1[i] == s2[j]) i++, j++;
		else
		{
			if (!uset.count(s1[i]))
			{
				res.push_back(s1[i]);
				uset.insert(s1[i]);
			}
			i++;
		}
	}
	while (i < s1.size())
	{
		alter(s1[i]);
		if (!uset.count(s1[i]))
		{
			res.push_back(s1[i]);
			uset.insert(s1[i]);
		}
		i++;
	}
	cout << res;
	return 0;
}
