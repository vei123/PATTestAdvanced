#include<iostream>
#include<string>
#define LL long long
using namespace std;

//题目输入变量
string n1, n2;
int tag, radix;
//用于逐步计算并保存n1，n2的数值
LL v1 = 0, v2 = 0;
//用于记录计算过程中的每一位数字的“权”
LL c1 = 1, c2 = 1;
//折半查找的左右边界
LL l = 0, r = 0x3fffffff;
//表示n2的进制
LL m;

inline LL ctoll(char c)
{
	if (c <= '9') return (LL)(c - '0');
	else return (LL)(c - 'a' + 10);
}

//返回0表示该进制下与n1的值相等，返回-1表示该进制下小于n1的值
//返回1表示该进制下大于n1，如果溢出，也返回1
int isbase(string& s, int m)
{
	v2 = 0, c2 = 1;
	for (int i = s.size() - 1; i >= 0; i--, c2 *= m)
	{
		LL t = ctoll(s[i]);
		v2 += t * c2;
		if (v2 > v1 || v2 < 0) return 1;
		else if (v2 == v1)
		{
			if (i) return 1;
			else return 0;
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n1 >> n2 >> tag >> radix;
	//如果tag为2，则交换两个数字就行
	if (tag == 2) swap(n1, n2);
	//计算n1的值(由于交换，此时radix一定是n1的进制)
	for (int i = n1.size() - 1; i >= 0; i--, c1 *= radix)
		v1 += ctoll(n1[i])*c1;
	//如果n2只有一位就特殊讨论，因为当位数大于1时，可以确保
	//有且只有一个进制满足要求，但是位数只有1位时会出现多种
	//进制满足要求的情况，而题目中要求取最小进制
	if (n2.size() == 1)
	{
		if (ctoll(n2[0]) == v1)
		{
			cout << v1 + 1;
			return 0;
		}
		else
		{
			cout << "Impossible";
			return 0;
		}
	}
	//否则进入二分查找
	//枚举找出二分查找下(左)界
	for (char c : n2)
	{
		LL t = ctoll(c);
		l = t + 1 > l ? t + 1 : l;
	}
	//二分查找上(右)界设置为n1的值，因为上界必定不可能大于n1
	//的值，否则此时n2的值一定大于n1的值
	r = v1;
	while (1)
	{
		LL m = (l + r) / 2;
		if (l >= r)
		{
			if (isbase(n2, m) == 0)
			{
				cout << m;
				return 0;
			}
			else break;
		}
		int t = isbase(n2, m);
		if (t == 1) r = m - 1;
		else if (t == -1) l = m + 1;
		else
		{
			cout << m;
			return 0;
		}
	}
	cout << "Impossible";
	return 0;
}
