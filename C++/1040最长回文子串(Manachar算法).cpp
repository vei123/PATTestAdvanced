#include<cstdio>
using namespace std;
//Manachar算法，有点繁琐，但时间复杂度为O(n)，适用于数据量特别大的情形，不过这道题n=1000，O(n^2)足够了，所以没必要用
//至于为什么算法时间复杂度是O(n)？原因在于马拉车算法的核心变量是当前回文串的右边界r，
//而r随着内部循环while的进行一定会跟着线性增长，然而每当r增长后，位于r之前的位置访问次数上限只是常数，所以算法的总复杂度是O(n)
char s[2100], ch;
int p[2100] = { 0 };
int i, _i, c = 0, r = 0;
int cnt = 0, maxlen = 0;

void input()
{
	s[cnt++] = '{';
	s[cnt++] = '#';
	while ((ch = getchar()) != '\n')
	{
		s[cnt++] = ch;
		s[cnt++] = '#';
	}
	s[cnt++] = '}';
}

signed main()
{
	input();
	for (int i = 1; i < cnt - 1; i++)
	{
		//确定i关于当前回文中心c的镜像位置
		int _i = 2 * c - i;
		//如果右边界r大于i，很好办，p[i]的值就是p[_i]的值，p[i]的值置为r-i和p[_i]中的最小值，是为了解决镜像位置_i的回文长度受限于左边界的情形
		if (r > i) p[i] = r - i < p[_i] ? r - i : p[_i];
		//否则需要拓展r，将p[i]先置为0，在while里会根据中心扩展次数增加p[i]，r随着p[i]的增加而增加
		else p[i] = 0;
		//这一步与中心扩展法中的步骤没区别，但是可以根据这一步的结果拓展r
		while (s[i + 1 + p[i]] == s[i - 1 - p[i]]) p[i]++;
		//拓展r
		if (i + p[i] > r)
		{
			c = i;
			r = i + p[i];
		}
	}
	//最后从得到的p[i]数组中获取最大回文长度，如果有需要也可以找出整个回文串，只需添加变量就可以实现
	for (int i = 1; i < cnt - 1; i++)
		if (p[i] > maxlen) maxlen = p[i];
	printf("%d", maxlen);
	return 0;
}
