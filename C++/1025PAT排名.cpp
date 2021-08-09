#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Info
{
	string registration_number;
	int final_rank;
	int location_number;
	int local_rank;
	int total_score;
};

bool cmp(Info i1, Info i2)
{
	if (i1.total_score != i2.total_score)
		return i1.total_score > i2.total_score;
	else
		return i1.registration_number.compare(i2.registration_number) < 0;
}

int main()
{
	ios::sync_with_stdio(0);
	int n, total = 0;
	cin >> n;
	Info* global = new Info[30010];
	for (int i = 1; i <= n; i++)
	{
		int k, l = total + 1;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			++total;
			string registration_number;
			cin >> global[total].registration_number;
			cin >> global[total].total_score;
			global[total].location_number = i;
		}
		sort(global + l, global + total + 1, cmp);
		for (int j = l, rank = 1; j <= total; j++)
		{
			if (j > l & global[j].total_score < global[j - 1].total_score)
				rank = j - l + 1;
			global[j].local_rank = rank;
		}
	}
	sort(global + 1, global + total + 1, cmp);
	for (int j = 1, rank = 1; j <= total; j++)
	{
		if (j > 1 & global[j].total_score < global[j - 1].total_score)
			rank = j;
		global[j].final_rank = rank;
	}
	cout << total << endl;
	for (int i = 1; i <= total; i++)
	{
		cout << global[i].registration_number << " ";
		cout << global[i].final_rank << " ";
		cout << global[i].location_number << " ";
		cout << global[i].local_rank << endl;
	}
	return 0;
}
