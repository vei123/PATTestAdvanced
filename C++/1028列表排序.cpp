#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define NEWLINE printf("\n");
using namespace std;

int mode = 0;

struct student
{
	int id;
	char name[9];
	int grade;
};

bool cmp(const student& a, const student& b)
{
	switch (mode)
	{
	case 1:
		return a.id < b.id;
		break;
	case 2:
		if (strcmp(a.name, b.name) != 0) return strcmp(a.name, b.name) < 0;
		else return a.id < b.id;
		break;
	case 3:
		if (a.grade != b.grade) return a.grade < b.grade;
		else return a.id < b.id;
		break;
	default:
		break;
	}
	return 0;
}

int main()
{
	int n, c;
	vector<student> v;
	scanf("%d%d", &n, &c);
	mode = c;
	for (int i = 0; i < n; i++)
	{
		student s;
		scanf("%d %s %d", &s.id, s.name, &s.grade);
		v.push_back(s);
	}
	stable_sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		printf("%06d %s %d", v[i].id, v[i].name, v[i].grade);
		if (i != n - 1) NEWLINE
	}
	return 0;
}
