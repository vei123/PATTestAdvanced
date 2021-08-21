#include<cstdio>
#define int long long
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int lcm(int a, int b) { return a / gcd(a, b) * b; }

signed main()
{
	int n, r[105][2], maxd = 1, sumn = 0;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld/%lld", &r[i][0], &r[i][1]);
		int g = gcd(r[i][0], r[i][1]);
		if (g < 0) g = -g;
		r[i][0] /= g, r[i][1] /= g;
	}
	for (int i = 0; i < n; i++)
		maxd = lcm(maxd, r[i][1]);
	for (int i = 0; i < n; i++)
	{
		r[i][0] *= maxd / r[i][1];
		sumn += r[i][0];
	}
	int resi = sumn / maxd;
	int resn = sumn % maxd;
	int g = gcd(resn, maxd);
	if (g < 0) g = -g;
	resn /= g, maxd /= g;
	if(resi) printf("%lld", resi);
	if (resi && resn) printf(" ");
	if (resn) printf("%lld/%lld", resn, maxd);
	if (!resi && !resn) printf("0");
	return 0;
}
