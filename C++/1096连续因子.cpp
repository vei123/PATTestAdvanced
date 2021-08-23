#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*
思路：
暴力循环，从i=2开始判断以i开头，连续因子序列可以有多长；
对于某些样例，一定会超时，所以考虑到一些特性作如下优化：
一、i不是循环到n，也不是根号i，而是maxlen次根号下n，
	其中maxlen为当前已探明最大长度，这个很好理解不做解释
二、特殊情况，对于奇数和不能被3整除的数，它的最大连续因子序列长度，一定分别不超过1和2
	原理也很简单，假设一个数有长度为2的连续因子序列 i*(i+1)，那么
	i和i+1中一定有一个是偶数，所以此数字n一定是偶数，反推回去奇数的最大连续因子长度只能为1，
	对于不能被3整除的数，同理可得它的最长序列长度为2
	推广：若n % i != 0，n的最长连续因子序列长度不超过i-1，
	此题只需要筛选以上两种情况即可，不需要再讨论不能被4、5...整除的情况
三、更特殊的情况，对于质数n，n有且仅有一个子序列，即n自身，所以直接输出n
*/
bool isprime(int n)
{
	if (n <= 1) return 0;
	if (n == 2) return 1;
	for (int i = 2; i <= (int)sqrt(n); i++)
		if (n%i == 0) return 0;
	return 1;
}

signed main()
{
	ios::sync_with_stdio(0);
	int n, maxlen = 0, limit = -1;
	vector<int> factor, seq;
	cin >> n;
	if (isprime(n))
	{
		cout << 1 << '\n' << n;
		return 0;
	}
	else if (n % 2) limit = 1;
	else if (n % 3) limit = 2;
	for (int i = 2; i<=int(pow(n, 1.0 / (maxlen + 1))); i++)
	{
		factor.clear();
		int m = n;
		for (int j = i;; j++)
		{
			if (m%j == 0)
			{
				factor.emplace_back(j);
				m /= j;
			}
			else break;
		}
		if (factor.size() > maxlen)
		{
			maxlen = factor.size();
			seq = vector<int>(factor);
		}
		if (maxlen == limit) break;
	}
	cout << maxlen << '\n';
	for (int i = 0; i < seq.size(); i++)
	{
		if (i) cout << '*';
		cout << seq[i];
	}
	return 0;
}
