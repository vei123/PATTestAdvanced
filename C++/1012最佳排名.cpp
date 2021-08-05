#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct Grade
{
	string id;
	int c, m, e, a;
	int cr, mr, er, ar;
	int index;
	Grade(string id, int c, int m, int e)
	{
		this->id = id;
		this->c = c;
		this->m = m;
		this->e = e;
		this->a = (c + m + e) / 3;
	}
	int getbest()
	{
		if (ar <= cr)
		{
			if (ar <= mr)
			{
				if (ar <= er) return 4;
				else return 3;
			}
			else
			{
				if (mr <= er) return 2;
				else return 3;
			}
		}
		else
		{
			if (cr <= mr)
			{
				if (cr <= er) return 1;
				else return 3;
			}
			else
			{
				if (mr <= er) return 2;
				else return 3;
			}
		}
	}
};

bool cmpc(const Grade& g1, const Grade& g2)
{
	return g1.c > g2.c;
}

bool cmpm(const Grade& g1, const Grade& g2)
{
	return g1.m > g2.m;
}

bool cmpe(const Grade& g1, const Grade& g2)
{
	return g1.e > g2.e;
}

bool cmpa(const Grade& g1, const Grade& g2)
{
	return g1.a > g2.a;
}

bool cmpi(const Grade& g1, const Grade& g2)
{
	return g1.index < g2.index;
}

unordered_map<string, int> umap;
vector<Grade> v;

int main()
{
	ios::sync_with_stdio(0);
	int n, m;
	string idi;
	int ci, mi, ei;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> idi >> ci >> mi >> ei;
		v.push_back(Grade(idi, ci, mi, ei));
		v[i].index = umap[idi] = i + 1;
	}
	sort(v.begin(), v.end(), cmpa);
	for (int i = 0; i < v.size(); i++)
	{
		if (!i) v[i].ar = 1;
		else if (v[i].a == v[i - 1].a)
			v[i].ar = v[i - 1].ar;
		else v[i].ar = i + 1;
	}
	sort(v.begin(), v.end(), cmpc);
	for (int i = 0; i < v.size(); i++)
	{
		if (!i) v[i].cr = 1;
		else if (v[i].c == v[i - 1].c)
			v[i].cr = v[i - 1].cr;
		else v[i].cr = i + 1;
	}
	sort(v.begin(), v.end(), cmpm);
	for (int i = 0; i < v.size(); i++)
	{
		if (!i) v[i].mr = 1;
		else if (v[i].m == v[i - 1].m)
			v[i].mr = v[i - 1].mr;
		else v[i].mr = i + 1;
	}
	sort(v.begin(), v.end(), cmpe);
	for (int i = 0; i < v.size(); i++)
	{
		if (!i) v[i].er = 1;
		else if (v[i].e == v[i - 1].e)
			v[i].er = v[i - 1].er;
		else v[i].er = i + 1;
	}
	sort(v.begin(), v.end(), cmpi);
	for (int i = 0; i < m; i++)
	{
		cin >> idi;
		if (umap[idi] > 0)
		{
			Grade g = v[umap[idi] - 1];
			int t = g.getbest();
			if (t == 1) cout << g.cr << " C";
			else if (t == 2) cout << g.mr << " M";
			else if (t == 3) cout << g.er << " E";
			else cout << g.ar << " A";
		}
		else cout << "N/A";
		if (i != m - 1) cout << "\n";
	}
	return 0;
}
