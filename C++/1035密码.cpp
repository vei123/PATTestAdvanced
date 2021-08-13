#include<iostream>
#include<vector>
#include<string>
#define sspair pair<string, string>
using namespace std;

signed main()
{
	ios::sync_with_stdio(0);
	int n;
	string name, code;
	vector<sspair> res;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		bool modified = 0;
		cin >> name >> code;
		for (int i = 0; i < code.size(); i++)
		{
			if (code[i] == '1')
			{
				code[i] = '@';
				modified = 1;
			}
			else if (code[i] == '0')
			{
				code[i] = '%';
				modified = 1;
			}
			else if (code[i] == 'l')
			{
				code[i] = 'L';
				modified = 1;
			}
			else if (code[i] == 'O')
			{
				code[i] = 'o';
				modified = 1;
			}
		}
		if (modified) res.push_back({ name, code });
	}
	if (res.size())
	{
		cout << res.size() << '\n';
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i].first << ' ' << res[i].second;
			if (i < res.size() - 1) cout << '\n';
		}
	}
	else
	{
		if (n == 1)
			cout << "There is 1 account and no account is modified";
		else
		{
			cout << "There are " << n;
			cout << " accounts and no account is modified";
		}
	}
	return 0;
}
