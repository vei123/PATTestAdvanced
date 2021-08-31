#include<iostream>
#include<unordered_map>
using namespace std;
/*
此题如果不加以优化，直接双重while的话，PAT能勉强通过，但AcWing不行
内层循环是为了找到当前的根节点位置，可以在输入时就用哈希表记录中序遍历
中每个值的下标位置，在之后直接从哈希表中取出对应值的下标就行，这样就
省去了内层循环，时间复杂度降为O(n)
没优化时，对于极端情况，即每个结点都只有左孩子结点时，前序和中序
序列将刚好反序：
前序：1 2 3 4 5 6 7 ... 50000
中序：50000 49999 49998 ... 1
这样内层循环每次将访问当前区间长度个元素，外层循环将执行n次，时间
复杂度为O(n^2/2)，对于n=5e4, n^2/2 > 10e9，会超时

值得一提的是，如果开了O2优化，即使是暴力双重循环也能在AcWing中通过
*/
int n, pre[50005], in[50005];
unordered_map<int, int> umap;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> pre[i];
	for (int i = 0; i < n; i++)
	{
		cin >> in[i];
		umap[in[i]] = i;
	}
	int pl = 0, pr = n - 1, il = 0, ir = n - 1;
	while (pl < pr)
	{
		int k = umap[pre[pl]];
		if (k > il) ir = k - 1, pr = k - il + pl++;
		else il++, pl++;
	}
	cout << pre[pl];
	return 0;
}
