#include<cstdio>
using namespace std;

signed main()
{
	int ag, as, ak, bg, bs, bk, cg, cs, ck;
	scanf("%d.%d.%d %d.%d.%d", &ag, &as, &ak, &bg, &bs, &bk);
	ck = ak + bk;
	cs = as + bs;
	cg = ag + bg;
	cs += ck / 29;
	ck = ck % 29;
	cg += cs / 17;
	cs = cs % 17;
	printf("%d.%d.%d", cg, cs, ck);
	return 0;
}
