#include<cstdio>
using namespace std;

signed main()
{
	int n;
	int* a = new int[100005];
	int* c = new int[10001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		c[a[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		if (c[a[i]] == 1)
		{
			printf("%d", a[i]);
			return 0;
		}
	}
	printf("None");
	return 0;
}
