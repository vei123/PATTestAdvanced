#include<cstdio>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct person
{
	int id;
	double mest, area;
};

struct info
{
	int id, num, flag;
	double sumsets, sumarea;
	bool operator<(const info& i)
	{
		if (sumarea / num != i.sumarea / i.num) 
			return sumarea / num > i.sumarea / i.num;
		else return id < i.id;
	}
};

int n, f[10005], valid[10005] = { 0 };
person pers[10005];
unordered_map<int, info> umap;
vector<info> res;

int getroot(int i) { return f[i] == i ? i : f[i] = getroot(f[i]); }

void unite(int i1, int i2)
{
	int r1 = getroot(i1), r2 = getroot(i2);
	if (r1 < r2) f[r2] = r1;
	else f[r1] = r2;
}

signed main()
{
	scanf("%d", &n);
	for (int i = 0; i < 10000; i++) f[i] = i;
	for (int i = 0; i < n; i++)
	{
		int id, fa, mo, k;
		double mest, area;
		scanf("%d %d %d %d", &id, &fa, &mo, &k);
		valid[id] = 1;
		if (fa != -1)
		{
			valid[fa] = 1;
			unite(id, fa);
		}
		if (mo != -1)
		{
			valid[mo] = 1;
			unite(id, mo);
		}
		for (int j = 0; j < k; j++)
		{
			int child;
			scanf("%d", &child);
			valid[child] = 1;
			unite(id, child);
		}
		scanf("%lf %lf", &mest, &area);
		pers[id].mest += mest;
		pers[id].area += area;
	}
	for (int i = 0; i < 10000; i++)
	{
		if (valid[i])
		{
			int root = getroot(i);
			umap[root].id = root;
			umap[root].num++;
			umap[root].flag = 1;
			umap[root].sumsets += pers[i].mest;
			umap[root].sumarea += pers[i].area;
		}
	}
	for (auto& p : umap)
		if (p.second.flag) res.emplace_back(p.second);
	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	for (auto& i : res)
		printf("%04d %d %.3lf %.3lf\n", i.id, i.num, i.sumsets / i.num, i.sumarea / i.num);
	return 0;
}
