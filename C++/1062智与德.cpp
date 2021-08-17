#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n, l, h;

struct person
{
	int id, tal, vir, type;
	void gettype()
	{
		if (tal < l || vir < l) type = 0;
		else if (tal >= h && vir >= h) type = 1;
		else if (vir >= h && tal < h) type = 2;
		else if (vir < h && tal < h && vir >= tal) type = 3;
		else type = 4;
	}
	bool operator<(const person& p)
	{
		if (type != p.type) return type < p.type;
		else
		{
			int t1 = vir + tal, t2 = p.vir + p.tal;
			if (t1 != t2) return t1 > t2;
			else
			{
				if (vir != p.vir) return vir > p.vir;
				else return id < p.id;
			}
		}
	}
};

signed main()
{
	scanf("%d %d %d", &n, &l, &h);
	vector<person> v;
	while (n--)
	{
		person p;
		scanf("%d %d %d", &p.id, &p.vir, &p.tal);
		p.gettype();
		if (p.type) v.push_back(p);
	}
	sort(v.begin(), v.end());
	int len = v.size();
	printf("%d", len);
	if (len)
		for (auto& p : v) printf("\n%08d %d %d", p.id, p.vir, p.tal);
	return 0;
}
