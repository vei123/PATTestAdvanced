#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#define iipair pair<int,int>
using namespace std;
//题目叙述的有点复杂，说白了就是有两个数列，一个升序一个降序，
//求某一个索引，那两个数列中在这个索引位置的数字的最小值最大
//比如两个数列：
//1 2 4 5 8 9
//6 5 5 3 2 1
//在索引为3处(索引从1开始)，有min(4，5) = 4，为最大值
//注意由于每天骑行的距离可能是个很大的数(虽然不太科学)，
//所以不能用数组的方式来计数，只能用数对pair的方式来存储计数值
bool cmp(const iipair& p1, const iipair& p2) { return p1.first < p2.first; }

int n, t;
unordered_map<int, int> umap;
vector<iipair> v;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		umap[t - 1]++;
	}
	for (auto& p : umap)
		if (p.second) v.emplace_back(p);
	sort(v.begin(), v.end(), cmp);
	for (int i = (int)v.size() - 2; i >= 0; i--)
		v[i].second += v[i + 1].second;
	int k = v.size() - 1;
	while (v[k].second < v[k].first) k--;
	cout << max(min(v[k].first, v[k].second), min(v[k + 1].first, v[k + 1].second));
	return 0;
}
