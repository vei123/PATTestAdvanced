#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int m;
	string id, in, out;
	string unlockid, lockid;
	string unlocktime = "24:00:00", locktime = "00:00:00";
	cin >> m;
	while (m--)
	{
		cin >> id >> in >> out;
		if (in < unlocktime)
		{
			unlocktime = in;
			unlockid = id;
		}
		if (out > locktime)
		{
			locktime = out;
			lockid = id;
		}
	}
	cout << unlockid << " " << lockid;
	return 0;
}
