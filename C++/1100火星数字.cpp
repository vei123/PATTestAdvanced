#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

//注意要用getline或者getchar接收输入数据，并且如果同时用了流输入
//和scanf、printf的话，不能关闭同步(ios::sync_with_stdio)

const string low[] =
{
	"tret", "jan", "feb", "mar", "apr", "may", "jun", 
	"jly", "aug", "sep", "oct", "nov", "dec"
};

const string high[] = 
{
	"", "tam", "hel", "maa", "huh", "tou", "kes", 
	"hei", "elo", "syy", "lok", "mer", "jou"
};

signed main()
{
	//ios::sync_with_stdio(0);
	int n;
	//scanf("%d\n", &n);
	cin >> n;
	getchar();
	unordered_map<string, int> lmap, hmap;
	for (int i = 0; i < 13; i++) lmap[low[i]] = i;
	for (int i = 1; i < 13; i++) hmap[high[i]] = i * 13;
	while (n--)
	{
		string t;
		getline(cin, t);
		if (t[0] >= '0'&&t[0] <= '9')
		{
			int x = stoi(t);
			int h = x / 13, l = x % 13;
			if (h) cout << high[h];
			if (h && l) cout << ' ';
			if (l) cout << low[l];
			if (!h && !l) cout << "tret";
			cout << '\n';
		}
		else
		{
			if (t.find(' ') == -1)
			{
				if (lmap[t] || hmap[t])
				{
					if (lmap[t]) cout << lmap[t] << '\n';
					else cout << hmap[t] << '\n';
				}
				else cout << "0\n";
			}
			else
			{
				string h = t.substr(0, t.find(' '));
				string l = t.substr(t.find(' ') + 1, 3);
				cout << hmap[h] + lmap[l] << '\n';
			}
		}
	}
	return 0;
}
