#include<iostream>
#include<iomanip>
using namespace std;

inline int m_max(double& a, double& b, double& c)
{
	return a >= b ? (a >= c ? 0 : 2) : (b >= c ? 1 : 2);
}

int main()
{
	ios::sync_with_stdio(0);
	double n1, n2, n3;
	char c[3];
	double d[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> n1 >> n2 >> n3;
		int t = m_max(n1, n2, n3);
		if (t == 0)
		{
			c[i] = 'W';
			d[i] = n1;
		}
		else if (t == 1)
		{
			c[i] = 'T';
			d[i] = n2;
		}
		else
		{
			c[i] = 'L';
			d[i] = n3;
		}
	}
	cout << c[0] << " "; 
	cout << c[1] << " ";
	cout << c[2] << " ";
	cout << fixed << setprecision(2);
	cout << (d[0] * d[1] * d[2] * 0.65 - 1) * 2;
	return 0;
}
