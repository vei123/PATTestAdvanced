#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct book
{
	int id;
	string title;
	string author;
	vector<string> keywords;
	string publisher;
	int year;
	bool operator<(const book& b)
	{
		return this->id < b.id;
	}
};

inline void printid(int id)
{
	if (id >= 1000000) cout << id;
	else
	{
		string t = to_string(id);
		while (t.size() < 7) t = '0' + t;
		cout << t;
	}
}

int main()
{
	int n, m;
	vector<book> booklist;
	//建立从标题到图书索引号的映射
	unordered_map<string, vector<int>> titlelist;
	//建立从作者到图书索引号的映射
	unordered_map<string, vector<int>> authorlist;
	//建立从关键词到图书索引号的映射
	unordered_map<string, vector<int>> keywordlist;
	//建立从出版社到图书索引号的映射
	unordered_map<string, vector<int>> publisherlist;
	//建立从年份到图书索引号的映射
	unordered_map<int, vector<int>> yearlist;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		book b;
		char c;
		string t;
		cin >> b.id;
		//getchar()接受多余的回车符避免被下一个getline读取
		getchar();
		getline(cin, b.title);
		if (!titlelist.count(b.title))
			titlelist[b.title] = vector<int>();
		titlelist[b.title].push_back(i);
		getline(cin, b.author);
		if (!authorlist.count(b.author))
			authorlist[b.author] = vector<int>();
		authorlist[b.author].push_back(i);
		while ((c = getchar()) != '\n')
		{
			if (c == ' ')
			{
				b.keywords.push_back(t);
				t.clear();
			}
			else
				t.push_back(c);
		}
		if (!t.empty()) b.keywords.push_back(t);
		for (auto s : b.keywords)
		{
			if (!keywordlist.count(s))
				keywordlist[s] = vector<int>();
			keywordlist[s].push_back(i);
		}
		getline(cin, b.publisher);
		if (!publisherlist.count(b.publisher))
			publisherlist[b.publisher] = vector<int>();
		publisherlist[b.publisher].push_back(i);
		cin >> b.year;
		if (!yearlist.count(b.year))
			yearlist[b.year] = vector<int>();
		yearlist[b.year].push_back(i);
		booklist.push_back(b);
	}
	cin >> m;
	while (m--)
	{
		int type;
		vector<int> resid;
		cin >> type;
		getchar();
		getchar();
		string t;
		getline(cin, t);
		if (type == 1)
		{
			for (int i : titlelist[t])
				resid.push_back(booklist[i].id);
		}
		else if (type == 2)
		{
			for (int i : authorlist[t])
				resid.push_back(booklist[i].id);
		}
		else if (type == 3)
		{
			for (int i : keywordlist[t])
				resid.push_back(booklist[i].id);
		}
		else if (type == 4)
		{
			for (int i : publisherlist[t])
				resid.push_back(booklist[i].id);
		}
		else
		{
			int tyear = stoi(t);
			for (int i : yearlist[tyear])
				resid.push_back(booklist[i].id);
		}
		sort(resid.begin(), resid.end());
		cout << type << ": " << t << '\n';
		for (int i = 0; i < resid.size(); i++)
		{
			printid(resid[i]);
			if (m || i != resid.size() - 1) cout << '\n';
		}
		if (resid.empty())
		{
			cout << "Not Found";
			if (m) cout << '\n';
		}
	}
	return 0;
}
