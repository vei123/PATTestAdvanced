#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;
//根据前序和中序，直接从中序中找到序号位于u的序号和v的序号之间的根
int n, m, u, v, a, in[10005], pre[10005];
unordered_set<int> allkeys;
unordered_map<int, int> indexof;

signed main()
{
	ios::sync_with_stdio(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> in[i];
		indexof[in[i]] = i;
		allkeys.insert(in[i]);
	}
	for (int i = 0; i < n; i++) cin >> pre[i];
	while (m--)
	{
		cin >> u >> v;
		if (!allkeys.count(u) && !allkeys.count(v))
			cout << "ERROR: " << u << " and " << v << " are not found.\n";
		else if (!allkeys.count(u))
			cout << "ERROR: " << u << " is not found.\n";
		else if (!allkeys.count(v))
			cout << "ERROR: " << v << " is not found.\n";
		else
		{
			int il = 0, ir = n - 1, im, pl = 0, pr = 0;
			while (1)
			{
				im = indexof[pre[pl]];
				if (indexof[u] < im && indexof[v] < im)
					ir = im - 1, pr = im - il + pl++;
				else if (indexof[u] > im && indexof[v] > im)
					pl = im - il + pl + 1, il = im + 1;
				else
				{
					a = in[im];
					break;
				}
			}
			if (a == u)
				cout << u << " is an ancestor of " << v << ".\n";
			else if (a == v)
				cout << v << " is an ancestor of " << u << ".\n";
			else
				cout << "LCA of " << u << " and " << v << " is " << a << ".\n";
		}
	}
	return 0;
}
