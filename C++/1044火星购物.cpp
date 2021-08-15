#include<iostream>
#include<vector>
using namespace std;

//看到N<=10^5，就知道一定得用O(n)复杂度的算法，自然想到"滑动窗口"法

struct segm
{
	int i, j, val;
	segm(int i, int j, int val) :i(i), j(j), val(val) {  }
};

signed main()
{
	ios::sync_with_stdio(0);
	int n, m, d, a[100005];
	vector<segm> ans;
	int minlost = 0x7fffffff;
	vector<segm> minlosts;
	cin >> n >> m;
	for (int k = 1; k <= n; k++) cin >> a[k];
	int l = 1, r = 1, tsum = a[1];
	while (r <= n)
	{
		if (tsum == m)
		{
			ans.push_back(segm(l, r, m));
			tsum -= a[l];
			l++;
		}
		else if (tsum < m)
		{
			r++;
			tsum += a[r];
		}
		else
		{
			if (tsum < minlost)
			{
				minlost = tsum;
				minlosts.clear();
				minlosts.push_back(segm(l, r, tsum));
			}
			else if (tsum == minlost)
				minlosts.push_back(segm(l, r, tsum));
			tsum -= a[l];
			l++;
		}
	}
	if (ans.size())
	{
		for (int k = 0; k < ans.size(); k++)
		{
			if (k) cout << '\n';
			cout << ans[k].i << '-' << ans[k].j;
		}
	}
	else
	{
		for (int k = 0; k < minlosts.size(); k++)
		{
			if (k) cout << '\n';
			cout << minlosts[k].i << '-' << minlosts[k].j;
		}
	}
	return 0;
}
