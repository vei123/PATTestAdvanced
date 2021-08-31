#include<cstdio>
#include<vector>
#include<unordered_map>
using namespace std;

struct node { int addr, data, next; };

int head, n, k;
unordered_map<int, node> umap;
vector<node> origin, a, b, c, v;

signed main()
{
	scanf("%d %d %d", &head, &n, &k);
	for (int i = 0; i < n; i++)
	{
		node t;
		scanf("%d %d %d", &t.addr, &t.data, &t.next);
		umap[t.addr] = t;
	}
	int p = head;
	while (p != -1)
	{
		origin.emplace_back(umap[p]);
		p = umap[p].next;
	}
	for (auto& t : origin)
	{
		if (t.data < 0) a.emplace_back(t);
		else if (t.data > k) c.emplace_back(t);
		else b.emplace_back(t);
	}
	for (auto& t : a) v.emplace_back(t);
	for (auto& t : b) v.emplace_back(t);
	for (auto& t : c) v.emplace_back(t);
	for (int i = 0; i < (int)v.size() - 1; i++)
		printf("%05d %d %05d\n", v[i].addr, v[i].data, v[i + 1].addr);
	printf("%05d %d -1", v.back().addr, v.back().data);
	return 0;
}
