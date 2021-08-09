#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void delprezeros(string& s)
{
	while (!s.empty() && s[0] == '0')
		s.erase(0, 1);
}

bool isPalin(string s)
{
	for (auto i = s.begin(), j = s.end() - 1; i < j; i++, j--)
		if (*i != *j) return 0;
	return 1;
}

string stradd(string a, string b)
{
	string res;
	int al = a.size(), bl = b.size();
	int* cc = new int[max(al, bl) + 1]();
	int* aa = new int[max(al, bl) + 1]();
	int* bb = new int[max(al, bl) + 1]();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for (int i = 0; i < a.size(); i++)
		aa[i] = (int)(a[i] - '0');
	for (int i = 0; i < b.size(); i++)
		bb[i] = (int)(b[i] - '0');
	for (int i = 0; i < max(al, bl) + 1; i++)
	{
		cc[i + 1] += (aa[i] + bb[i] + cc[i]) / 10;
		cc[i] = (aa[i] + bb[i] + cc[i]) % 10;
		res.push_back((char)cc[i] + '0');
	}
	reverse(res.begin(), res.end());
	delprezeros(res);
	return res;
}

string reverstr(string s)
{
	reverse(s.begin(), s.end());
	return s;
}

int main()
{
	ios::sync_with_stdio(0);
	string n;
	int k;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		if (isPalin(n))
		{
			cout << n << '\n' << i;
			return 0;
		}
		n = stradd(n, reverstr(n));
	}
	cout << n << '\n' << k;
	return 0;
}
