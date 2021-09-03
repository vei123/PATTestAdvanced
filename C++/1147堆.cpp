#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int m, n, a[1005];
vector<int> post;

void postordertraversal(int i)
{
	if (i >= n) return;
	postordertraversal(2 * i + 1);
	postordertraversal(2 * i + 2);
	post.emplace_back(a[i]);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> m >> n;
	while (m--)
	{
		for (int i = 0; i < n; i++) cin >> a[i];
		bool maxheap = 1, minheap = 1;
		for (int i = n / 2; i >= 0; i--)
		{
			int left = 2 * i + 1, right = 2 * i + 2;
			if (left < n && a[left] > a[i]) maxheap = 0;
			if (right < n && a[right] > a[i]) maxheap = 0;
			if (left < n && a[left] < a[i]) minheap = 0;
			if (right < n && a[right] < a[i]) minheap = 0;
		}
		if (maxheap) cout << "Max Heap\n";
		else if (minheap) cout << "Min Heap\n";
		else cout << "Not Heap\n";
		post.clear();
		postordertraversal(0);
		for (int i = 0; i < n; i++)
		{
			if (i) cout << ' ';
			cout << post[i];
		}
		cout << '\n';
	}
	return 0;
}
