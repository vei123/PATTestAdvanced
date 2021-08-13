#include<iostream>
#include<string>
using namespace std;

signed main()
{
	ios::sync_with_stdio(0);
	int n;
	int highest = -1, lowest = 101;
	string fname, mname, fid, mid;
	string name, id;
	char gender;
	int grade;
	cin >> n;
	while (n--)
	{
		cin >> name >> gender >> id >> grade;
		if (gender == 'F')
		{
			if (grade > highest)
			{
				fname = name;
				fid = id;
				highest = grade;
			}
		}
		else
		{
			if (grade < lowest)
			{
				mname = name;
				mid = id;
				lowest = grade;
			}
		}
	}
	if (highest == -1 && lowest == 101)
		cout << "Absent\nAbsent\nNA";
	else if (highest == -1)
	{
		cout << "Absent\n";
		cout << mname << ' ' << mid << "\nNA";
	}
	else if (lowest == 101)
		cout << fname << ' ' << fid << "\nAbsent\nNA";
	else
	{
		cout << fname << ' ' << fid << '\n';
		cout << mname << ' ' << mid << '\n';
		cout << highest - lowest;
	}
	return 0;
}
