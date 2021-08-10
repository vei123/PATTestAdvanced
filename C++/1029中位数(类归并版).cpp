#include<cstdio>
using namespace std;

int* v1 = new int[200005];
int* v2 = new int[200005];

int main()
{
	int n1, n2, t, m;
	int i, j;
	scanf("%d", &n1);
	for (i = 0; i < n1; i++) scanf("%d", &v1[i]);
	scanf("%d", &n2);
	for (j = 0; j < n2; j++) scanf("%d", &v2[j]);
	m = (n1 + n2 + 1) / 2 - 1;
	bool flag = 0;
	i = j = 0;
	while (1)
	{
		if (i + j - 1 == m) break;
		if (i >= n1) j++, flag = 1;
		else if (j >= n2) i++, flag = 0;
		else if (v1[i] <= v2[j]) i++, flag = 0;
		else j++, flag = 1;
	}
	printf("%d", flag ? v2[j - 1] : v1[i - 1]);
	//就不delete[]了
	return 0;
}
