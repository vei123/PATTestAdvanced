#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

signed main()
{
	ios::sync_with_stdio(0);
	int n, k;
	long double sum = 0.0;
	string s;
	cin >> n;
	k = n;
	for (int i = 0; i < n; i++)
	{
		bool legal = 1;
		int cntofpoint = 0;
		cin >> s;
		string t = s;
		if (s[0] == '-' || s[0] == '+') s.erase(0, 1);
		if (s.empty()) legal = 0;
		for (char& c : s)
		{
			if (c < '0' || c > '9')
			{
				if (c == '.') cntofpoint++;
				else
				{
					legal = 0;
					break;
				}
			}
		}
		if (legal && cntofpoint > 1)
			legal = 0;
		if (legal && s.find('.') != -1 && ((int)s.find('.') < (int)s.size() - 3))
			legal = 0;
		if (legal && (stold(s) > 1000 || stold(s) < -1000))
			legal = 0;
		if (legal) sum += stold(t);
		else
		{
			k--;
			cout << "ERROR: " << t << " is not a legal number\n";
		}
	}
	cout << fixed << setprecision(2);
	if (k > 1) cout << "The average of " << k << " numbers is " << sum / k;
	else if (k == 1) cout << "The average of 1 number is " << sum;
	else cout << "The average of 0 numbers is Undefined";
	return 0;
}
