#include<iostream>
#include<algorithm>
using namespace std;
/*
简单的贪心问题，有点哈夫曼编码的味道...
要使最后绳子最长，需要把长的绳子放后面对折，所以先排序，
又因为每次对折都是将两个的长度相加再除以2，
所以这个结果依然是最短的，就不需要再重新排序了，
依次计算到最后一节即可。
如果要难一点，也可以每次只让其中一根绳子减半，比如序列：
3 3 4 5 ...
3 + 3 / 2 = 4.5，这样算出的值就不一定仍然是最短的了，需要重新
挪动位置。如果问题变成这样的话，也很简单，可以用优先队列来实现，
复杂度为O(nlogn)，依然满足要求
*/
int n;
double d[20005], res;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> d[i];
	sort(d, d + n);
	res = d[0];
	for (int i = 1; i < n; i++) res = (res + d[i]) / 2;
	cout << int(res);
	return 0;
}
