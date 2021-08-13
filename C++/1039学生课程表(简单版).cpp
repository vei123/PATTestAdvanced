#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

//此版本在PAT里可以AC，但在AcWing中会报TLE

unordered_map<int, vector<string>> course;
unordered_map<string, vector<int>> student;

signed main()
{
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int ci, ni;
		string id;
		cin >> ci >> ni;
		for (int j = 0; j < ni; j++)
		{
			cin >> id;
			if (!course.count(ci)) course[ci] = vector<string>();
			course[ci].push_back(id);
			if (!student.count(id)) student[id] = vector<int>();
			student[id].push_back(ci);
		}
	}
	for (int i = 0; i < n; i++)
	{
		string id;
		cin >> id;
		cout << id << ' ';
		cout << student[id].size();
		int len = student[id].size();
		if (len)
		{
			cout << ' ';
			sort(student[id].begin(), student[id].end());
			for (int j = 0; j < len; j++)
			{
				cout << student[id][j];
				if (j != len - 1) cout << ' ';
			}
		}
		if (i != n - 1) cout << '\n';
	}
	return 0;
}
