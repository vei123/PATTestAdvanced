#include<iostream>
#include<string>
#include<stack>
using namespace std;

//这是一道超纲题目，用vector+二分查找会超时，只能用高级数据结构
//但是甲级是不会考高级数据结构的...

/*单点修改、区间查询的树状数组
举个例子，对于一个数列{8, 3, 3, 10, 5, 1}, 我们怎么快速统计值小于等于i的元素个数呢？

假设数组a[i](注意是并不是下面的数组c[])统计值为i的元素个数，
用c[i](即下面的c[]数组)来“辅助统计”值小于等于i的元素个数
(注意c[i]并不直接代表小于等于i的元素个数，而是需要根据c[i]计算)

则数组情况为：
index: 0  1  2  3  4  5  6  7  8  9  10 ...虽然后面的数组元素程序也会计算，但不影响结果
a[] =  0  1  0  2  0  1  0  0  1  0  1  (1个1，2个3，1个5...)
c[] =  0  1  1  2  3  1  1  0  5  0  2
(1个1，1个在[1, 2]内，2个3，3个在[1, 4]内，1个5，"2个在[5, 6]内"...)
即:
c[1] = a[1]
c[2] = a[1] + a[2]
c[3] = a[3]
c[4] = a[1] + a[2] + a[3] + a[4]
...
c[i] = a[i] (i为奇数)
	 = a[i - 2^k + 1] + a[i - 2^k + 2] + ... + a[i]
		(i为偶数，即从包括a[i]往前数2^k个元素，其中k即是lowbit中所求值)
这样构建出c[]数组后，我们就可以利用c[]快速统计区间[1, i]内的元素个数，
即getsum函数，它可以在logn复杂度内查询值处在区间[1, i]内的元素个数

接下来，peekmedian函数，用二分查找的方式，查询哪个值是中位数，即
区间[1, i]的元素个数刚好为元素个数的一半，以上面的数列为例子
快进到程序查询getsum(7) = 4 >= 3，即表示小于等于7的元素个数为4，
发现仍然大于(6/3) = 3, 所以继续查询getsum(4) = 3 >= 3， 继续查询
(此时l = 1, r = 4, m = 2) getsum(m==2) = 1 < 3， 所以改为查询右半区间，
(l = 3, r = 4, m = 3), getsum(m==3) = 3 >= 3, 继续查询左半区间
(l = 3, r = 3, m = 3), 由于l == r， 结束while循环，返回值3，表示3
就是要找的中位数，至此一次查询结束
来看一下复杂度：
对于Peekmedia操作，用二分查找锁定[1, N]内某个中位数大约会进行log2(N)次
getsum函数的调用，每一个getsum函数的复杂度的期望是log2(N/2)，
也为log2(N)(其实是log2(N) - 1)，所以总复杂度为(log2(N))*(log2(N))
对于Push操作，即单点更新，调用一次update函数，复杂度期望为log2(N)，实际上是log2(N/2))
对于Pop操作，也调用一次update函数，复杂度期望也为log2N

所以整个程序的复杂度介于log2(N)与log2(N)*log2(N)之间，
以这道题的N等于十万为例，每次操作需要进行log2(10万) ~= 17次循环执行到
log2(N)*log2(N) ~= 17 * 16 == 272次循环执行，可以n次操作程序的总复杂度
为17*n到272*n之间，取题目中n==十万次push,pop,peekmedian操作，
最大复杂度为"272*10^5*程序复杂度常数" 接近于 10^8，符合要求
*/

const int N = 100005;
//用数组c[]维护小于等于下标值的元素个数
int c[100005] = { 0 };
stack<int> stk;

//树状数组中快速求2^k(k为i的低位连续0长度)的方法
inline int lowbit(int i) { return i & (-i); }

//单点修改，在c[]的下标位i的位置加(或减)k，需要同时在
//c[i], c[i+2^k1], c[i+2^k1+i+2^k2], ... ,直到不超过c[N]的所有关键位置处修改值，复杂度为logn
void update(int i, int k)
{
	while (i <= N)
	{
		c[i] += k;
		i += lowbit(i);
	}
}

//区间求和，求值在区间[1, i]的所有元素的个数
int getsum(int i)
{
	int res = 0;
	while (i > 0)
	{
		res += c[i];
		i -= lowbit(i);
	}
	return res;
}

int peekmedian(int k)
{
	int l = 1, r = N - 1, m;
	while (l < r)
	{
		m = (l + r) / 2;
		//如果小于等于值m的元素个数比k少，就查询右边的区间
		if (getsum(m) < k)
			l = m + 1;
		//反之如果元素个数大于等于k，就查询左边的区间，注意由于包含等于，所以左边区间也包含m自己
		else
			r = m;
	}
	return l;
}

signed main()
{
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	while (n--)
	{
		string comd;
		cin >> comd;
		if (comd == "Push")
		{
			int key;
			cin >> key;
			stk.push(key);
			update(key, 1);
		}
		else if (comd == "Pop")
		{
			if (stk.empty())
				cout << "Invalid";
			else
			{
				cout << stk.top();
				update(stk.top(), -1);
				stk.pop();
			}
			if (n) cout << '\n';
		}
		else
		{
			if (stk.empty())
				cout << "Invalid";
			else
				cout << peekmedian((stk.size() + 1) / 2);
			if (n) cout << '\n';
		}
	}
	return 0;
}
