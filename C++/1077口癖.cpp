#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

signed main()
{
	int n, minlen = 256;
	char ch;
	string s[101];
	string suf;
	scanf("%d", &n);
	getchar();
	for (int i = 1; i <= n; i++)
	{
		while ((ch = getchar()) != '\n')
			s[i].push_back(ch);
		minlen = s[i].size() < minlen ? s[i].size() : minlen;
		reverse(s[i].begin(), s[i].end());
	}
	for (int j = 0; j < minlen; j++)
	{
		char c = s[1][j];
		bool match = 1;
		for (int i = 2; i <= n; i++)
		{
			if (s[i][j] != c)
			{
				match = 0;
				break;
			}
		}
		if (match) suf.push_back(c);
		else break;
	}
	if (suf.empty()) printf("nai");
	else
	{
		reverse(suf.begin(), suf.end());
		printf("%s", suf.c_str());
	}
	return 0;
}
