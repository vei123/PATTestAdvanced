#include<cstdio>
#include<cmath>
#define int long long
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int lcm(int a, int b) { return a / gcd(a, b) * b; }

inline void simplify(int& a, int& b)
{
	int g = gcd(abs(a), abs(b));
	a /= g, b /= g;
	if ((a < 0 && b < 0) || b < 0)	a = -a, b = -b;
}

void print(int a, int b)
{
	int a0 = a, b0 = b;
	if (a0*b0 < 0) printf("(-");
	if (a)
	{
		a = abs(a), b = abs(b);
		if (a / b)
		{
			printf("%lld", a / b);
			if (a%b) printf(" %lld/%lld", a%b, b);
		}
		else printf("%lld/%lld", a, b);
	}
	else printf("0");
	if (a0*b0 < 0) printf(")");
}

void printequ(int a1, int b1, int a2, int b2, int op)
{
	print(a1, b1);
	if(op == 1) printf(" + ");
	else if (op == 2) printf(" - ");
	else if (op == 3) printf(" * ");
	else printf(" / ");
	print(a2, b2);
	printf(" = ");
}

void add(int a1, int b1, int a2, int b2)
{
	printequ(a1, b1, a2, b2, 1);
	int a, b;
	int l = lcm(b1, b2);
	a1 *= l / b1, a2 *= l / b2;
	a = a1 + a2;
	b = l;
	simplify(a, b);
	print(a, b);
}

void sub(int a1, int b1, int a2, int b2)
{
	printequ(a1, b1, a2, b2, 2);
	int a, b;
	int l = lcm(b1, b2);
	a1 *= l / b1, a2 *= l / b2;
	a = a1 - a2;
	b = l;
	simplify(a, b);
	print(a, b);
}

void mul(int a1, int b1, int a2, int b2)
{
	printequ(a1, b1, a2, b2, 3);
	int a, b;
	a = a1 * a2;
	b = b1 * b2;
	simplify(a, b);
	print(a, b);
}

void div(int a1, int b1, int a2, int b2)
{
	printequ(a1, b1, a2, b2, 4);
	int a, b;
	if (a2)
	{
		a = a1 * b2;
		b = b1 * a2;
		simplify(a, b);
		print(a, b);
	}
	else printf("Inf");
}

signed main()
{
	int a1, b1, a2, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	simplify(a1, b1);
	simplify(a2, b2);
	add(a1, b1, a2, b2);
	printf("\n");
	sub(a1, b1, a2, b2);
	printf("\n");
	mul(a1, b1, a2, b2);
	printf("\n");
	div(a1, b1, a2, b2);
	printf("\n");
	return 0;
}
