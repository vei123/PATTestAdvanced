#include<iostream>
using namespace std;

int a[20000];

int main()
{
	ios::sync_with_stdio(0);
	int k;
	int maxsum = 0x80000000;
	int tmpsum = -1;
	int l = 0, r = 0, tmpl, tmpr;
	bool flag = 0;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> a[i];
		if (a[i] >= 0) flag = 1;
	}
	for (int i = 0; i < k; i++)
	{
		if (tmpsum < 0)
		{
			tmpl = tmpr = i;
			tmpsum = a[i];
		}
		else
		{
			tmpr = i;
			tmpsum += a[i];
		}
		if (tmpsum > maxsum)
		{
			l = tmpl;
			r = tmpr;
			maxsum = tmpsum;
		}
	}
	if (flag)
		cout << maxsum << " " << a[l] << " " << a[r];
	else
		cout << 0 << " " << a[0] << " " << a[k - 1];
	return 0;
}
