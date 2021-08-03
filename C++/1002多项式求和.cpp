#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define term pair<int,double>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	int k1, k2;
	int n;
	double a;
	vector<term> v1, v2, v3;
	cin >> k1;
	for (int i = 0; i < k1; i++)
	{
		cin >> n >> a;
		v1.push_back(term(n, a));
	}
	cin >> k2;
	for (int i = 0; i < k2; i++)
	{
		cin >> n >> a;
		v2.push_back(term(n, a));
	}
	int l1 = v1.size(), l2 = v2.size();
	for (int i = 0, j = 0; i != l1 || j != l2;)
	{
		if (i == l1)
		{
			v3.push_back(v2[j]);
			j++;
		}
		else if (j == l2)
		{
			v3.push_back(v1[i]);
			i++;
		}
		else if (v1[i].first > v2[j].first)
		{
			v3.push_back(v1[i]);
			i++;
		}
		else if (v1[i].first < v2[j].first)
		{
			v3.push_back(v2[j]);
			j++;
		}
		else
		{
			double at = v1[i].second + v2[j].second;
			if (abs(at) > 0.0000001)
				v3.push_back(term(v1[i].first, at));
			i++, j++;
		}
	}
	cout << v3.size();
	if (v3.size()) cout << " ";
	for (int i = 0; i < v3.size(); i++)
	{
		cout << v3[i].first << " ";
		//printf("%.1lf", v3[i].second);
		cout << fixed << setprecision(1) << v3[i].second;
		if (i != v3.size() - 1) cout << " ";
	}
	return 0;
}
