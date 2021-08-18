#include<cstdio>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#define sipair pair<string, int>
using namespace std;

unordered_map<string, int> freq;
vector<sipair> res;

bool cmp(const sipair& p1, const sipair& p2)
{
	return p1.first < p2.first;
}

inline bool isanchar(char& c)
{
	if (c >= '0' && c <= '9') return 1;
	else if (c >= 'a' && c <= 'z') return 1;
	else if (c >= 'A' && c <= 'Z')
	{
		c += 'a' - 'A';
		return 1;
	}
	else return 0;
}

signed main()
{
	string s;
	char ch;
	while (1)
	{
		ch = getchar();
		if (isanchar(ch)) s.push_back(ch);
		else
		{
			if (!s.empty()) freq[s]++;
			s.clear();
		}
		if (ch == '\n') break;
	}
	int maxfreq = 0;
	for (auto& p : freq)
	{
		if (p.second > maxfreq)
		{
			res.clear();
			res.emplace_back(p);
			maxfreq = p.second;
		}
		else if (p.second == maxfreq)
			res.emplace_back(p);
	}
	sort(res.begin(), res.end(), cmp);
	printf("%s %d", res[0].first.c_str(), res[0].second);
	return 0;
}
