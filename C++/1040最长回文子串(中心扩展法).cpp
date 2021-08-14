#include<cstdio>
using namespace std;
//中心扩展法，时间复杂度O(n^2)，n为字符串长度
signed main()
{
	char c[2100], ch;
	int cnt = 0, maxlen = 0;
	c[cnt++] = '{';
	c[cnt++] = '#';
	while ((ch = getchar()) != '\n')
	{
		c[cnt++] = ch;
		c[cnt++] = '#';
	}
	c[cnt++] = '}';
	for (int i = 2; i < cnt - 2; i++)
	{
		int j = 1;
		while (c[i - j] == c[i + j]) j++;
		maxlen = 2 * (j - 1) + 1 > maxlen ? 2 * (j - 1) + 1 : maxlen;
	}
	printf("%d", (maxlen - 1) / 2);
	return 0;
}
