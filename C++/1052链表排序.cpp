#include<cstdio>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<iomanip>
using namespace std;

//很简单的题目：
//先将数据读入到哈希表中，用链表的方式遍历一次哈希表，将所有节点
//存入vector数组中，然后对vector按照key值排升序，
//最后也是不可忽略的一步，要将排序后的vector的每两个结点之间，
//将前一个结点的next设为后一个结点的addr
//坑点：最后一个数据输入是"0 -1"，表示空表，相应地，输出也应该是"0 -1"

struct node
{
	int addr, key, next;
	node() :addr(0), key(0), next(0) {  }
	node(int addr, int key, int next) : addr(addr), key(key), next(next) {  }
	bool operator<(const node& n) { return this->key < n.key; }
	void print()
	{
		printf("%05d %d ", addr, key);
		if (next != -1) printf("%05d", next);
		else printf("-1");
	}
};

unordered_map<int, node> mlist;
vector<node> v;

signed main()
{
	int n, head;
	scanf("%d%d", &n, &head);
	for (int i = 0; i < n; i++)
	{
		int addr, key, next;
		scanf("%d %d %d", &addr, &key, &next);
		mlist[addr] = node(addr, key, next);
	}
	while (head != -1)
	{
		v.emplace_back(mlist[head]);
		head = mlist[head].next;
	}
	sort(v.begin(), v.end());
	int len = v.size();
	printf("%d", len);
	if (len) printf(" %05d\n", v[0].addr);
	else printf(" -1");
	for (int i = 0; i < len; i++)
	{
		if (i < len - 1) v[i].next = v[i + 1].addr;
		else v[i].next = -1;
		if (i) printf("\n");
		v[i].print();
	}
	return 0;
}
