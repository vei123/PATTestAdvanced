#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<iomanip>
using namespace std;

struct Call
{
	string name;
	string time;
	string word;
	Call(string name, string time, string word):
	name(name), time(time), word(word) {}
};

bool cmp(const Call& a, const Call& b)
{
	if (a.name != b.name) return a.name < b.name;
	else return a.time < b.time;
}

inline int getabsolutetime(int time)
{
	return (time / 10000 * 1440) +
		(time % 10000 / 100 * 60) +
		(time % 100);
}

inline int getday(int time)
{
	return time / 10000;
}

inline int gethour(int time)
{
	return time % 10000 / 100;
}

inline int getminute(int time)
{
	return time % 100;
}

int timeadd(int time, int delt)
{
	int d, h, m;
	d = getday(time);
	h = gethour(time);
	m = getminute(time);
	m += delt;
	h += m / 60;
	m %= 60;
	d += h / 24;
	h %= 24;
	return 10000 * d + 100 * h + m;
}

const string online = "on-line";
const string offline = "off-line";
int n;
int rate[24];
vector<Call> v;
vector<vector<Call>> t;
stack<Call> stk;

int main()
{
	ios::sync_with_stdio(0);
	string name, time, word;
	for (int i = 0; i < 24; i++)
		cin >> rate[i];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> time >> word;
		v.push_back(Call(name, time, word));
	}
	sort(v.begin(), v.end(), cmp);
	string tmp("");
	for (auto c : v)
	{
		if (c.name != tmp)
		{
			tmp = c.name;
			t.push_back(vector<Call>());
			t.back().push_back(c);
		}
		else
			t.back().push_back(c);
	}
	for (int i = 0; i < t.size(); i++)
	{
		vector<string> output;
		vector<int> fees;
		stk = stack<Call>();
		int total = 0;
		for (auto c : t[i])
		{
			if (c.word == online)
				stk.push(c);
			else
			{
				int curfee = 0;
				if (stk.empty()) continue;
				else
				{
					auto a = stk.top();
					while (!stk.empty())
						stk.pop();
					int start, end;
					start = stoi(
						a.time.substr(3, 2) +
						a.time.substr(6, 2) +
						a.time.substr(9, 2)
					);
					end = stoi(
						c.time.substr(3, 2) +
						c.time.substr(6, 2) +
						c.time.substr(9, 2)
					);
					int diff = getabsolutetime(end) -
						getabsolutetime(start);
					if (getminute(start) && diff >= 60)
					{
						curfee += rate[gethour(start)]
							* (60 - getminute(start));
						start = timeadd(start,
							60 - getminute(start));
					}
					else if(getminute(start) && diff < 60)
					{
						if (gethour(start) == gethour(end))
						{
							curfee += rate[gethour(start)]
								* (end - start);
						}
						else
						{
							curfee += rate[gethour(start)]
								* (60 - getminute(start));
							curfee += rate[gethour(end)]
								* (getminute(end));
						}
						start = end;
					}
					while (start < end)
					{
						if (end - start >= 60)
						{
							curfee +=
								rate[gethour(start)] * 60;
							start = timeadd(start, 60);
						}
						else
						{
							curfee +=
								rate[gethour(start)] *
								(end - start);
							start = end;
						}
					}
					output.push_back(a.time.substr(3, 8)
						+ " " + c.time.substr(3, 8) + " "
						+ to_string(diff) + " "
						+ "$");
					fees.push_back(curfee);
					total += curfee;
				}
			}
		}
		if (total)
		{
			cout << t[i][0].name << ' ';
			cout << t[i][0].time.substr(0, 2) << '\n';
			while (!output.empty())
			{
				cout << output[0];
				cout << fixed << setprecision(2);
				cout << (double)fees[0] / 100;
				cout << endl;
				output.erase(output.begin());
				fees.erase(fees.begin());
			}
			cout << "Total amount: $";
			cout << fixed << setprecision(2);
			cout << (double)total / 100;
			cout << '\n';
		}
	}
	return 0;
}
