#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

//这道题的最后一个测试点非常卡时间，网上绝大多数题解都是卡点过(500+ms)，
//此题解的400ms甚至算快了，目前不知道有没有什么方法可以使效率有质的提升

//用string映射到int，而不是用string直接映射到vector数组，希望能快点...
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
		//PAT输出格式通病：就是折磨人，每次为了处理格式必定多小10行代码！
		if (i != n - 1) cout << '\n';
	}
	return 0;
}
