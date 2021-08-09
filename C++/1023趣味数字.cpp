#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

void delprezeros(string& s)
{
	while (!s.empty() && s[0] == '0')
		s.erase(0, 1);
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
		cc[i + 1] += (aa[i] + bb[i]) / 10;
		cc[i] += (aa[i] + bb[i]) % 10;
		res.push_back((char)(cc[i] + '0'));
	}
	reverse(res.begin(), res.end());
	delprezeros(res);
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	string s, t, v;
	cin >> s;
	v = t = stradd(s, s);
	unordered_map<char, int> umap;
	for (char c : s)
		umap[c]++;
	for (char c : t)
		umap[c]--;
	for (auto p : umap)
	{
		if (p.second)
		{
			cout << "No\n";
			cout << v;
			return 0;
		}
	}
	cout << "Yes\n";
	cout << v;
	return 0;
}
