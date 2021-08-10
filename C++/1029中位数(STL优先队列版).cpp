#include<cstdio>
#include<queue>
#define NEWLINE printf("\n");
using namespace std;

//注意该版本只能在PAT测试中AC，在AcWing中会超时

int main()
{
	int n1, n2, t, m;
	priority_queue<int, vector<int>, greater<int>> q;
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++)
	{
		scanf("%d", &t);
		q.push(t);
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++)
	{
		scanf("%d", &t);
		q.push(t);
	}
	m = (n1 + n2 + 1) / 2 - 1;
	for (int i = 0;; i++)
	{
		if (i == m)
		{
			printf("%d", q.top());
			break;
		}
		q.pop();
	}
	return 0;
}
