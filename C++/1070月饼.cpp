#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct mooncake
{
	double amount;
	double price;
	double ratio;
	bool operator<(const mooncake& m) { return this->ratio > m.ratio; }
};

signed main()
{
	int n;
	double d, profit = 0.0;
	vector<mooncake> v;
	scanf("%d%lf", &n, &d);
	for (int i = 0; i < n; i++)
	{
		mooncake m;
		scanf("%lf", &m.amount);
		v.emplace_back(m);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &v[i].price);
		v[i].ratio = v[i].price / double(v[i].amount);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		if (d > v[i].amount)
		{
			profit += (double)v[i].amount * v[i].ratio;
			d -= v[i].amount;
		}
		else
		{
			profit += (double)d * v[i].ratio;
			break;
		}
		if (!d) break;
	}
	printf("%.2lf", profit);
	return 0;
}
