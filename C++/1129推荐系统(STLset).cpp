#include<iostream>
#include<set>
using namespace std;
/*
一种取巧的方法，不值得提倡，时间复杂度比较高，卡点AC(200ms左右)
本题的大概意思就是让你动态排序，每输入一个值，对以前某个数据结构来一次重新排序，
但是发现数据量比较大，所以每次都重新搞个vector来排序，可能会超时
(实际上，在PAT中AC，但在AcWing中超时)

所以想到用某些数据结构，比如堆，但是STL的堆比较残废，几乎只能操作头部，所以无法使用.

继而想到，用set来实现(map也可以，只需忽略value值)，set和map的底层是红黑树，
对于插入和删除操作，有着较高的效率(O(logn))，所以我们可以使用set内部的自动排序
来动态地为商品及其访问次数排序，只需要一个自定义结构体以及重载小于运算符：

自定义一个结构体来作为set的元素，这个结构体包含x，y。x表示商品序号，
y表示商品访问次数，那么只需要重载小于运算符，就可以让set自动为其排序，这样每次
访问得到的序列就是自然有序的了

但也有个问题，如果某个商品没有被创建，很好办，直接insert就可以，但如果这个商品
已经被创建呢？我们希望可以直接修改结构体中的y值，使其访问频率+1，但是set中的元素是
常量，不可以被修改，所以每次只能先erase，再重新创建，这就使得复杂度比较高
*/
struct fpair
{
	int x, y;
	bool operator<(const fpair& fp) const
	{
		if (y != fp.y) return y > fp.y;
		else return x < fp.x;
	}
};

int n, k, t, c[50005] = { 0 };
set<fpair> freq;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		if (i)
		{
			auto it = freq.find({ t, c[t] - 1 });
			if (it == freq.end())
				freq.insert(fpair{ t, 1 });
			else
			{
				freq.erase(it);
				freq.insert(fpair{ t, c[t] });
			}
		}
		cin >> t;
		if (i)
		{
			int cnt = 0;
			cout << t << ':';
			for (auto& p : freq)
			{
				cout << ' ' << p.x;
				if (++cnt == k) break;
			}
			cout << '\n';
		}
		c[t]++;
	}
	return 0;
}
