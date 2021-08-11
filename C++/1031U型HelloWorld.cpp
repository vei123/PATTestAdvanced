#include<cstdio>
#include<string>
using namespace std;

int main()
{
	string s;
	char ch, c[81][81];
	while ((ch = getchar()) != '\n') s.push_back(ch);
	int n = s.size();
	int n1, n2, n3;
	n1 = n3 = (n + 2) / 3;
	n2 = (n + 2) - (n1 + n3);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			c[i][j] = ' ';
	}
	for (int i = 1; i <= n1; i++)
		c[i][1] = s[i - 1];
	for (int i = 1; i <= n2; i++)
		c[n1][i] = s[n1 + i - 2];
	for (int i = 1; i <= n3; i++)
		c[n3 - i + 1][n2] = s[n1 + n2 + i - 3];
	for (int i = 1; i <= n1; i++)
	{
		for (int j = 1; j <= n2; j++)
			printf("%c", c[i][j]);
		if (i < n2) printf("\n");
	}
	return 0;
}
