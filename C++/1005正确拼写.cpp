#include<iostream>
#include<string>
#include<vector>
using namespace std;

const string wordlist[] =
{
	"zero","one","two","three","four",
	"five","six","seven","eight","nine"
};

int main()
{
	ios::sync_with_stdio(0);
	string s, r;
	int n = 0;
	cin >> s;
	for (char c : s)
		n += (int)(c - '0');
	r = to_string(n);
	const int rl = (int)r.size();
	for (int i = 0; i < rl; i++)
	{
		cout << wordlist[(int)r[i] - '0'];
		if (i != rl - 1) cout << " ";
	}
	return 0;
}
