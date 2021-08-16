#include<cstdio>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int n, m, s, w[105];
int id, k, t;
unordered_map<int, vector<int>> tree;
vector<vector<int>> ans;
vector<int> tmp;

void dfs(int id, int weight)
{
	weight += w[id];
	tmp.emplace_back(w[id]);
	//如果是叶结点就判定一次
	if (!tree.count(id))
	{
		if (weight == s)
			ans.emplace_back(tmp);
	}
	//否则对每个孩子结点继续深搜
	else
		for (int i : tree[id]) dfs(i, weight);
	tmp.pop_back();
	weight -= w[id];
}

bool cmp(const vector<int>& v1, const vector<int>& v2)
{
	int len = min(v1.size(), v2.size());
	for (int i = 0; i < len; i++)
		if (v1[i] != v2[i]) return v1[i] > v2[i];
	return 0;
}

signed main()
{
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n; i++) scanf("%d", w + i);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &id, &k);
		if (!tree.count(id)) tree[id] = vector<int>();
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &t);
			tree[id].emplace_back(t);
		}
	}
	dfs(0, 0);
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++)
	{
		if (i) printf("\n");
		for (int j = 0; j < ans[i].size(); j++)
		{
			if (j) printf(" ");
			printf("%d", ans[i][j]);
		}
	}
	return 0;
}
