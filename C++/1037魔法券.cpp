#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//很简单的数学题，不用多解释了
signed main()
{
	ios::sync_with_stdio(0);
	int nc, np, t, sum = 0;
	vector<int> cp, pp, cn, pn;
	cin >> nc;
	for (int i = 0; i < nc; i++)
	{
		cin >> t;
		t > 0 ? cp.push_back(t) : cn.push_back(t);
	}
	cin >> np;
	for (int i = 0; i < np; i++)
	{
		cin >> t;
		t > 0 ? pp.push_back(t) : pn.push_back(t);
	}
	sort(cp.begin(), cp.end(), greater<int>());
	sort(pp.begin(), pp.end(), greater<int>());
	sort(cn.begin(), cn.end(), less<int>());
	sort(pn.begin(), pn.end(), less<int>());
	int lp = cp.size() < pp.size() ? cp.size() : pp.size();
	int ln = cn.size() < pn.size() ? cn.size() : pn.size();
	for (int i = 0; i < lp; i++) sum += cp[i] * pp[i];
	for (int i = 0; i < ln; i++) sum += cn[i] * pn[i];
	cout << sum;
	return 0;
}
