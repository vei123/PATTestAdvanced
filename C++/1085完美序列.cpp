#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

int n, p, maxnum = 0, a[100005];

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> p;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int i = 0, j = 0;
	while (i < n)
	{
		while (j < n && a[j] <= a[i] * p)
		{
			maxnum = max(maxnum, j - i + 1);
			j++;
		}
		i++;
	}
	cout << maxnum;
	return 0;
}

//注意int会溢出，所以要改为long long
/*思路：
原始想法是排序后双重循环暴力求解，找最大值即可
	for i = 0 : n-1
		for j = i + 1 : n-1
			do judge and update max
但是题目中数据量为10e5，这样肯定会超时，是不是就不能这样做了呢？
实际上，上述循环是可以优化的。

先对数组排升序，复杂度为O(nlogn)，设排序结果为数组a[]
然后让双指针i, j起始都指向a[0]
考虑由于p为正数，所以此时[a[i],a[j]]范围内的最大值、最小值
都是a[0], a[0]<=a[0]*p == 1<=p， 一定满足条件

①首先保持i=0不变，对j递增+1，只要满足要求就继续+1，直到不满足：
此时有a[j]>a[i]*p，如果继续增大j，a[j]也增大，势必不满足，所以停止对j增加，转②
②将i +1，由于a[i]增大，满不满足条件需要重新判定，所以继续对j从当前值
(为什么从当前值开始？因为j回溯后一定是满足条件的，并且j-i+1还变小了，所以回溯是没有意义的)
开始判断，只要满足j就递增+1，直到不满足，又重新转②
③当i为n时循环结束

上述算法伪代码：
set i = j = 0
for i = 0 : n - 1
	while(j < n and a[j] <= a[i] * p)
		update max, j++;

上述算法也是一个双重循环，看似有着O(n^2)复杂度，实则不然：
考虑到i和j在整个过程中是一直只增不减的，并且每一次内循环的结果只有两种情况：
①满足条件，所以j++
②不满足条件，跳出内循环，但在外循环中i++

所以每一次内循环，i和j一定会有一个增加1，当j增至n-1时，i将一直增大到n-1，随后结束
综上，这一部分算法的时间复杂度其实是O(n)：
上限是O(2n)，即i和j都增大到了n
下限是O(n+1)，j只增大了1就不满足条件，随后i增至n结束
所以时间复杂度是合格的，总复杂度为排序算法复杂度，也满足要求
*/
