#include<iostream>
#include<string>
using namespace std;

const string week[] = 
{
	"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
};

inline int isletter(char c)
{
	if (c <= 'Z' && c >= 'A') return 1;
	else if (c <= 'z' && c >= 'a') return 0;
	else return -1;
}

inline bool isweek(char c)
{
	return c <= 'G' && c >= 'A';
}

inline int ishour(char c)
{
	if (c <= '9' && c >= '0') return int(c - '0');
	else if (c <= 'N' && c >= 'A') return int(c - 'A' + 10);
	else return -1;
}

signed main()
{
	string s1, s2, s3, s4;
	int res[3], mode = 0;
	cin >> s1 >> s2 >> s3 >> s4;
	int l1 = s1.size() < s2.size() ? s1.size() : s2.size();
	for (int i = 0; i < l1; i++)
	{
		if (mode == 0)
		{
			if (s1[i] == s2[i] && isweek(s1[i]))
			{
				res[mode] = s1[i] - 'A';
				mode = 1;
			}
		}
		else
		{
			if (s1[i] == s2[i] && ishour(s1[i]) >= 0)
			{
				res[mode] = ishour(s1[i]);
				mode = 2;
				break;
			}
		}
	}
	int l3 = s3.size() < s4.size() ? s3.size() : s4.size();
	for (int i = 0; i < l3; i++)
	{
		if (s3[i] == s4[i] && isletter(s3[i]) >= 0)
		{
			res[mode] = i;
			break;
		}
	}
	cout << week[res[0]] << ' ';
	printf("%02d:%02d", res[1], res[2]);
	return 0;
}
