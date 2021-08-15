#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

signed main()
{
	ios::sync_with_stdio(0);
	string s1, s2;
	unordered_set<char> uset;
	getline(cin, s1);
	getline(cin, s2);
	for (char c : s2)
		if (!uset.count(c)) uset.insert(c);
	for (char c : s1)
		if (!uset.count(c)) cout << c;
	return 0;
}
