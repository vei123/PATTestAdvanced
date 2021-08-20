#include<iostream>
#include<string>
using namespace std;

signed main()
{
	ios::sync_with_stdio(0);
	string s;
	cin >> s;
	int e = s.find('E');
	if (stof(s.substr(1, e - 1)) == 0.0)
	{
		cout << 0;
		return 0;
	}
	string base = s.substr(0, e);
	int exp = stoi(s.substr(e + 1));
	if(exp)
	{
		while (exp > 0)
		{
			int pos = base.find('.');
			if (pos == -1) base.push_back('0');
			else
			{
				if (pos == base.size() - 1)
				{
					base.erase(base.end() - 1);
					base.insert(pos, 1, '0');
				}
				else
				{
					base.erase(pos, 1);
					base.insert(pos + 1, 1, '.');
				}
			}
			exp--;
		}
		while (exp < 0)
		{
			int pos = base.find('.');
			if (base[1] == '0') base.insert(pos + 1, 1, '0');
			else
			{
				base.erase(pos, 1);
				base.insert(1, 1, '.');
				base.insert(1, 1, '0');
			}
			exp++;
		}
	}
	if (base.back() == '.') base.pop_back();
	if (base[0] == '+') base.erase(0, 1);
	cout << base;
	return 0;
}
