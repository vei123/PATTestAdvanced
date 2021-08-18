#include<iostream>
#include<string>
#define LL long long
#define MAXLL 0x7fffffffffffffff
#define MINLL (-0x7fffffffffffffff - 1LL)
using namespace std;

//long long 范围 -2^63~2^63-1
//十分坑的一道题，建议复习一下C++ long long类型以后再来做...

signed main()
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		string sa, sb, sc;
		LL a, b, c;
		int flag = 0;
		//cin >> a >> b >> c;
		cin >> sa >> sb >> sc;
		cout << "Case #" << i << ": ";
		if (sa == "9223372036854775808")
			a = 9223372036854775807LL, flag--;
		else
			a = stoll(sa);
		if (sb == "9223372036854775808")
			b = 9223372036854775807LL, flag--;
		else
			b = stoll(sb);
		if (sc == "9223372036854775808")
			c = 9223372036854775807LL, flag++;
		else
			c = stoll(sc);
		c += flag;
		if (a <= 0 && b > 0 || a > 0 && b <= 0)
			cout << (a + b > c ? "true" : "false");
		else
		{
			if (a > 0 && b > 0)
			{
				if (MAXLL - a >= b)
					cout << (a + b > c ? "true" : "false");
				else
					cout << "true";
			}
			else
			{
				if (MINLL - a <= b)
					cout << (a + b > c ? "true" : "false");
				else
					cout << "false";
			}
		}
		if (i < t) cout << '\n';
	}
	return 0;
}
