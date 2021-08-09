#include<cstdio>
#include<string>
using namespace std;

char tochar(int i)
{
	if (i < 10) return (char)i + '0';
	else return (char)i + 'A' - 10;
}

string toradix13(int n)
{
	string s;
	s.push_back(tochar(n % 13));
	n /= 13;
	s.push_back(tochar(n % 13));
	swap(s[0], s[1]);
	return s;
}

int main()
{
	int r, g, b;
	scanf("%d %d %d", &r, &g, &b);
	printf("#%s%s%s", toradix13(r).c_str(), toradix13(g).c_str(), toradix13(b).c_str());
	return 0;
}
