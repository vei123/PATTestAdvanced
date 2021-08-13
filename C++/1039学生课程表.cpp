#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

//这道题如果不注意某些细节很容易被卡常，无论是我自己的题解，还是网上找的题解，其运行时间均数百毫秒(甚至此题解的400ms还算快了)

//建立从string到int的映射，期望能比直接从string哈希映射到vector够快一点，实际上不知道是不是快了...
unordered_map<string, int> ref1;
vector<vector<int>> student;

signed main()
{
	ios::sync_with_stdio(0);
	int n, k, cnt = 1;
	cin >> n >> k;
	//这道题非常坑的一点，实际名单里的学生数可以超过40000，甚至150000都不够，vector小了会段错误
	student.resize(200000);
	for (int i = 0; i < k; i++)
	{
		int ci, ni;
		string id;
		cin >> ci >> ni;
		for (int j = 0; j < ni; j++)
		{
			cin >> id;
			if (!ref1.count(id)) ref1[id] = cnt++;
			student[ref1[id]].emplace_back(ci);
		}
	}
	for (int i = 0; i < n; i++)
	{
		string id;
		cin >> id;
		cout << id << ' ';
		int t = ref1[id], len = student[t].size();
		cout << len;
		if (len)
		{
			cout << ' ';
			sort(student[t].begin(), student[t].end());
			for (int j = 0; j < len; j++)
			{
				cout << student[t][j];
				if (j != len - 1) cout << ' ';
			}
		}
		if (i != n - 1) cout << '\n';
	}
	return 0;
}
