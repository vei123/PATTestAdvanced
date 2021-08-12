#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

//区间贪心

struct stop
{
	double price;
	int start;
	stop(double d, int i) :price(d), start(i) {  }
};

bool cmp(const stop& s1, const stop& s2)
{
	return s1.price > s2.price;
}

double cost[32005] = { 0.0 };

signed main()
{
	double cmax, davg;
	int d, n;
	vector<stop> v;
	scanf("%lf%d%lf%d", &cmax, &d, &davg, &n);
	while (n--)
	{
		double pi;
		int di;
		scanf("%lf%d", &pi, &di);
		v.push_back(stop(pi, di));
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
	{
		double tmp = v[i].price / davg;
		for (int j = v[i].start; j < v[i].start + int(cmax*davg); j++)
			cost[j] = tmp;
	}
	double sum = 0.0;
	int k = 0;
	for (; k < d&&cost[k] != 0.0; k++) sum += cost[k];
	if (k < d)
		printf("The maximum travel distance = %.2lf", (double)k);
	else
		printf("%.2lf", sum);
}
