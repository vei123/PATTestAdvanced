#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
经典左右两次遍历的线性DP题，l[i]位置i左侧的最大值，r[i]记录i右侧的
最小值，然后再遍历一次，对于a[i]，如果a[i]比它左侧的最大值大，且比
它右侧的最小值小，那么a[i]就可以作为一个pivot，把a[i]放入vector中，
最后排个序就可以输出了
复杂度：O(3n)~O(nlogn)，满足数据量N<=10e5的要求
*/
int n, a[100005], l[100005], r[100005];
vector<int> v;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	l[1] = 0;
	for (int i = 2; i <= n; i++)
		l[i] = a[i - 1] > l[i - 1] ? a[i - 1] : l[i - 1];
	r[n] = 0x7fffffff;
	for (int i = n - 1; i >= 1; i--)
		r[i] = a[i + 1] < r[i + 1] ? a[i + 1] : r[i + 1];
	for (int i = 1; i <= n; i++)
		if (l[i]<a[i] && r[i]>a[i]) v.emplace_back(a[i]);
	sort(v.begin(), v.end());
	int len = v.size();
	cout << len << '\n';
	for (int i = 0; i < len; i++)
	{
		if (i) cout << ' ';
		cout << v[i];
	}
	cout << '\n';
	return 0;
}
