#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
/*
思路：第一反应是用类背包的动态规划求解，但是由于限制了数字总个数恰好
为k，常规背包问题解法无法应用。于是又发现n和k都是小于等于400的数，
想用普通动态规划求解，发现仍然不行，因为对于每一个n、k，并不能唯一决定一个
正确解(非最优)，并且到达此状态的途径也不止一条，所以只能硬着头皮DFS

不加处理的暴力DFS一定会超时，因为复杂度可达O(n^k)，是一个天文数字，所以
必须加以剪枝，至于如何剪枝？这个是DFS的难点之一，必须具体问题具体分析：
一、最容易想到的剪枝方法：朴素DFS之所以有指数的复杂度，是因为每个状态，
都需要对所有可以的选择进行一次搜索，比如对于"169 167 2"这组输入，
第一次在{1,4,9,...13}中选一次，第二次又在这个集合中选一次...
复杂度高达O(13^167)，这是不能接受的。
所以很自然地想到，应当从大到小地选择数字，并且每一次选择后，下一次以及之后所有选择
，只能选小于等于这个数的数，比如某一次选了9,之后就只能选9及小于9的数字。
这是最简单的剪枝方式，但是复杂度仍然非常高

二、对输入"169 167 2"的思考，发现由于k很大，必须把某些次的可选择项，限制到
接近1的状态，不然一定会超时，比如即使你优化到每次只能选择两项，
O(2^167)仍然是一个不可接受的复杂度，所以必须将某些可选项锁定到一个选项：

我们发现，当第一次选择了任何大于1的幂数{4,9,...13}后，下一个状态将变为
n k 2，其中n<k，也就是说，就算每次都只选择1，也不能符合要求。我们可以根据这一点归纳
一个具有普遍性的剪枝规则：
若当前状态为 n k p, 若这一次选择了一个幂数m，那么下一个状态将变为n-m k-1 p，
此时所有大于(n-m)/(k-1)的数字都不能再选。

以上面的169 167 2为例，若选择了4，那么下一个状态为 165 166 2，所以
所有大于165/166=(一个小于1的数)的数都不能选，所以可以直接结束，省去大量判断。
再比如输入400 200 2，只要选了大于1的数，下一个状态，以及之后，都只能再选
1了，这样可以将k很大(大于n/2)的所有状态，降为常数复杂度O(k)

只要做了以上两点优化之后，就可以AC了，只是时间没有降到100ms以内,还可以稍作以下的
剪枝：
三、在每次进入循环之前判断：当可选的数字中最大数字都小于剩余选择的数字个数时，直接返回，道理很简单不解释
四、每一个终态，即0 k p的状态，直接返回，不用再进入循环了，这一优化看似
无关痛痒，实际上是很有用的，因为dfs的最深层很多，有很多出口，如果每个出口
都让它再循环一次再自然结束，也会花费很多时间，不如直接return
*/
int n, k, p, len, maxsum = 0;
vector<int> h, f, t, r;

bool largerthan(vector<int>& v1, vector<int>& v2)
{
	for(int i = 0; i < k; i++)
		if (v1[i] != v2[i]) return v1[i] > v2[i];
	return 0;
}

void dfs(int num = n, int cnt = k, int lmt = 0, int sum = 0)
{
	if (!cnt)
	{
		if (!num && (sum > maxsum || (sum == maxsum && largerthan(t, r))))
		{
			maxsum = sum;
			r = t;
		}
		return;
	}
	//剪枝四
	if (!num) return;
	//剪枝三，没有这一句话能AC，但是某个样例会有数百ms花费
	if (f[lmt] * cnt < num) return;
	for (int i = lmt; i < len; i++)
	{
 		if (num >= f[i])
		{
			//↓剪枝一、二
			int lmt1 = lmt;
			while (lmt1 < len && num - f[lmt1] < cnt - 1) lmt1++;
			lmt1 = max(lmt1, i);
			//↑剪枝一、二
			t.emplace_back(f[i]);
			dfs(num - f[i], cnt - 1, lmt1, sum + h[i]);
			t.pop_back();
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> k >> p;
	r = vector<int>(k, -1);
	for (int i = 1;; i++)
	{
		int e = (int)pow(i, p);
		if (e > n) break;
		h.emplace_back(i);
		f.emplace_back(e);
	}
	len = f.size();
	sort(f.begin(), f.end(), greater<int>());
	sort(h.begin(), h.end(), greater<int>());
	dfs();
	if (!maxsum) cout << "Impossible";
	else
	{
		cout << n << " = ";
		for (int i = 0; i < r.size(); i++)
		{
			if (i) cout << " + ";
			cout << (int)pow(r[i], 1.0 / p) << '^' << p;
		}
	}
	return 0;
}
