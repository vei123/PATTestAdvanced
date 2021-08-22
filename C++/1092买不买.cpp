#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

unordered_map<char, int> shewants;

signed main()
{
	ios::sync_with_stdio(0);
	string s, t;
	int lost = 0, extra = 0;
	cin >> s >> t;
	for (auto& c : t) shewants[c]++;
	for (auto& c : s) shewants[c]--;
	for (auto& p : shewants) p.second > 0 ? lost += p.second : extra -= p.second;
	if (lost) cout << "No " << lost;
	else cout << "Yes " << extra;
	return 0;
}
