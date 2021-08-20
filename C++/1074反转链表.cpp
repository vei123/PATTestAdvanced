#include<cstdio>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//用unordered_map存储读入的链表数据，再根据头结点从其中遍历
//一次链表，并按照每个vector长度至多为k的原则存入二维vector中，
//随后再遍历一次二维vector，对实际长度为k的vector翻转一次，
//按照要求输出next即可

struct node
{
	int addr, data, next;
};

signed main()
{
	int head, n, k;
	unordered_map<int, node> list;
	vector<vector<node>> v(1, vector<node>());
	scanf("%d %d%d", &head, &n, &k);
	for (int i = 0; i < n; i++)
	{
		node t;
		scanf("%d %d %d", &t.addr, &t.data, &t.next);
		list[t.addr] = t;
	}
	while (head != -1)
	{
		if (v.back().size() == k)
			v.emplace_back(vector<node>());
		v.back().emplace_back(list[head]);
		head = list[head].next;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].size() == k)
			reverse(v[i].begin(), v[i].end());
		if (i) printf("%05d\n", v[i][0].addr);
		for (int j = 0; j < v[i].size(); j++)
		{
			printf("%05d %d ", v[i][j].addr, v[i][j].data);
			if (j < v[i].size() - 1)
				printf("%05d\n", v[i][j + 1].addr);
		}
	}
	printf("-1");
	return 0;
}
