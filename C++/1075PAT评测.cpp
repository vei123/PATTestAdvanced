#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct user
{
	int id, s[6], total, acs, rank;
	bool operator<(const user& u) const
	{
		if (total != u.total) return total > u.total;
		else
		{
			if (acs != u.acs) return acs > u.acs;
			else return id < u.id;
		}
	}
};

int n, k, m, p[6];
vector<user> v;
vector<user> a;

signed main()
{
	scanf("%d %d %d", &n, &k, &m);
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		v[i].id = i;
		memset(v[i].s, -1, sizeof(v[i].s));
		v[i].total = -1;
		v[i].acs = 0;
	}
	for (int i = 1; i <= k; i++) scanf("%d", p + i);
	while (m--)
	{
		int uid, pid, score;
		scanf("%d %d %d", &uid, &pid, &score);
		if (v[uid].s[pid] == -1) v[uid].s[pid] = 0;
		if (score != -1)
		{
			if (v[uid].total == -1) v[uid].total = 0;
			if (score > v[uid].s[pid])
			{
				if (score == p[pid]) v[uid].acs++;
				v[uid].total += score - v[uid].s[pid];
				v[uid].s[pid] = score;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (v[i].total != -1)
			a.emplace_back(v[i]);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++)
	{
		if (!i) a[i].rank = 1;
		else
		{
			printf("\n");
			if (a[i].total == a[i - 1].total)
				a[i].rank = a[i - 1].rank;
			else
				a[i].rank = i + 1;
		}
		printf("%d %05d %d", a[i].rank, a[i].id, a[i].total);
		for (int j = 1; j <= k; j++)
		{
			if (a[i].s[j] != -1)
				printf(" %d", a[i].s[j]);
			else
				printf(" -");
		}
	}
	return 0;
}
