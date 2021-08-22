#include<iostream>
#include<algorithm>
using namespace std;

int n, a[105], b[105], mode, iter = 0;

signed main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	bool flag = 0;
	for (int i = 1; i < n; i++)
	{
		if (!flag)
		{
			if (b[i] < b[i - 1]) flag = 1;
		}
		else
		{
			if (a[i] != b[i])
			{
				cout << "Merge Sort\n";
				mode = 2;
				break;
			}
		}
		if (i == n - 1)
		{
			mode = 1;
			cout << "Insertion Sort\n";
		}
	}
	if (mode == 1)
	{
		int i = 1;
		while (i < n && b[i] >= b[i - 1]) i++;
		//没必要判定i是否为n，i一定小于n，因为题目中明确说了
		//只有一种可能的结果，所以初始序列一定无序
		int key = b[i];
		while (b[i - 1] > key)
		{
			b[i] = b[i - 1];
			i--;
		}
		b[i] = key;
	}
	else
	{
		//从步长i=2开始，依次检测是否在步长i下有序，否则直接结束，开始排序
		int i = 2;
		bool flag = 0;
		while (i < n)
		{
			for (int j = 0; j < n; j += i)
			{
				for (int k = j + 1; k < n&&k < j + i; k++)
				{
					if (b[k] < b[k - 1])
					{
						flag = 1;
						break;
					}
				}
				if (flag) break;
			}
			if (flag) break;
			i *= 2;
		}
		int k = 0;
		//因为数据量小，可以sort，如果对复杂度要求高，可以merge
		for (; k + i < n; k += i)
			sort(b + k, b + k + i);
		if (k != n) sort(b + k, b + n);
	}
	for (int i = 0; i < n; i++)
	{
		if (i) cout << ' ';
		cout << b[i];
	}
	return 0;
}
