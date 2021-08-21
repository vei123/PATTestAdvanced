#include<iostream>
#include<vector>
#include<string>
using namespace std;
//很磨人的一道题，最难点在于判断何时该插入“ling”
const string num[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
const string unit[] = { "", "Shi", "Bai", "Qian"};
const string part[] = { "", "Wan", "Yi" };

signed main()
{
	ios::sync_with_stdio(0);
	int n, m, len, ling;
	vector<string> res;
	cin >> n;
	m = n;
	n = n > 0 ? n : -n;
	len = to_string(n).size();
	for (int i = 0; i < len; i++, n /= 10)
	{
		if (!n) break;
		int t = n % 10;
		if (i == 4 && n % 1000) res.insert(res.begin(), part[1]);
		if (i == 8 && n) res.insert(res.begin(), part[2]);
		if (!t)
		{
			if (i % 4 == 3 && res.size() && res[0] != "ling")
			{
				res.insert(res.begin(), "ling");
				ling = 0;
			}
			else ling = 1;
			continue;
		}
		if (ling && res.size())
		{
			if (res[0] != part[1] && res[0] != part[2] && res[0] != "ling")
				res.insert(res.begin(), "ling");
		}
		if (i % 4) res.insert(res.begin(), unit[i % 4]);
		res.insert(res.begin(), num[t]);
		ling = 0;
	}
	if (m < 0) cout << "Fu ";
	else if (m == 0) cout << "ling";
	for (int i = 0; i < res.size(); i++)
	{
		if (i) cout << ' ';
		cout << res[i];
	}
	return 0;
}
