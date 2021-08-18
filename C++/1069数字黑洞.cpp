#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

signed main()
{
	int n;
	scanf("%d", &n);
	int m = n / 10, k = n % 10;
	if (!n)
	{
		printf("0000 - 0000 = 0000");
		return 0;
	}
	while (m)
	{
		if (m % 10 != k) break;
		m /= 10;
		if (!m)
		{
			printf("%04d - %04d = 0000", n, n);
			return 0;
		}
	}
	while (1)
	{
		string s = to_string(n);
		while (s.size() < 4) s = '0' + s;
		sort(s.begin(), s.end(), greater<char>());
		n = stoi(s);
		reverse(s.begin(), s.end());
		int m = stoi(s);
		int diff = n - m;
		printf("%04d - %04d = %04d", n, m, diff);
		if (diff != 6174) printf("\n");
		else break;
		n = diff;
	}
	return 0;
}
