#include<iostream>
#include<string>
using namespace std;

/*考虑所有极端情形：
000001
0000
0.000
0012.000
...
*/

string tostandardform(string& s, int n)
{
	string r(s);
	int exp = 0;
	int pos = s.find(".");
	//xxx
	if (pos == -1)
	{
		while (r.size() && r[0] == '0') r.erase(0, 1);
		exp = r.size();
		while (r.size() < n) r.push_back('0');
		if (r[0] == '0') return "0." + r.substr(0, n) + "*10^0";
		else return "0." + r.substr(0, n) + "*10^" + to_string(exp);
	}
	//xxx.xxx
	else
	{
		string ipart = r.substr(0, pos);
		string dpart = r.substr(pos + 1, r.size() - pos - 1);
		while (ipart.size() > 1 && ipart[0] == '0') ipart.erase(0, 1);
		if (ipart.size() > 1) exp = ipart.size();
		else if (ipart[0] == '0')
		{
			for (int i = 0; i < dpart.size(); i++)
			{
				if (dpart[i] == '0') exp--;
				else break;
			}
			if (-exp == dpart.size()) exp = 0;
		}
		else exp = 1;
		string t = ipart + dpart;
		while (t.size() && t[0] == '0') t.erase(0, 1);
		while (t.size() < n) t.push_back('0');
		return "0." + t.substr(0, n) + "*10^" + to_string(exp);
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	int n;
	string a, b;
	cin >> n >> a >> b;
	string aa = tostandardform(a, n);
	string bb = tostandardform(b, n);
	if (aa == bb)
		cout << "YES " << aa;
	else
		cout << "NO " << aa << ' ' << bb;
	return 0;
}
