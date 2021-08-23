#include<cstdio>
#define int long long
using namespace std;
//两次遍历计数所有字符左边'P'数量和右边'T'数量，然后对每个'A'字符计算并加上即可
int n = 0, p[100005] = { 0 }, t[100005] = { 0 }, cnt = 0;
char s[100005], ch;

signed main()
{
	while ((ch = getchar()) != '\n') s[++n] = ch;
	s[0] = s[n + 1] = '#';
	for (int i = 1; i < n; i++) p[i] = (s[i - 1] == 'P' ? p[i - 1] + 1 : p[i - 1]);
	for (int i = n; i > 1; i--) t[i] = (s[i + 1] == 'T' ? t[i + 1] + 1 : t[i + 1]);
	for (int i = 2; i < n; i++) if(s[i]=='A') cnt += p[i] * t[i];
	printf("%lld", cnt % 1000000007);
	return 0;
}
