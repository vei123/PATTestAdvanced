#include<cstdio>
#include<vector>
#include<unordered_set>
using namespace std;

struct node { int addr, key, next; };

inline void printnode(node& i)
{
	printf("%05d %d ", i.addr, i.key);
	if (i.next != -1) printf("%05d\n", i.next);
	else printf("-1\n");
}

signed main()
{
	int head, n;
	vector<node> v, v1, v2;
	unordered_set<int> uset;
	scanf("%d %d", &head, &n);
	v.resize(100005);
	for (int i = 0; i < n; i++)
	{
		int addr, key, next;
		scanf("%d %d %d", &addr, &key, &next);
		v[addr] = node{ addr, key, next };
	}
	while (head != -1)
	{
		node& i = v[head];
		if (uset.count(abs(i.key))) v2.emplace_back(i);
		else
		{
			uset.insert(abs(i.key));
			v1.emplace_back(i);
		}
		head = i.next;
	}
	for (int i = 0; i < (int)v1.size() - 1; i++) v1[i].next = v1[i + 1].addr;
	if(!v1.empty()) v1.back().next = -1;
	for (int i = 0; i < (int)v2.size() - 1; i++) v2[i].next = v2[i + 1].addr;
	if(!v2.empty()) v2.back().next = -1;
	for (auto& i : v1) printnode(i);
	for (auto& i : v2) printnode(i);
	return 0;
}
