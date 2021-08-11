#include<cstdio>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main()
{
	int s1, s2, n;
	//存储字母表
	unordered_map<int, int> table;
	//存储两个单词中的字母的 “地址”
	vector<int> word1, word2;
	scanf("%d%d%d", &s1, &s2, &n);
	for (int i = 0; i < n; i++)
	{
		int addr, next;
		char ch;
		scanf("%d %c %d", &addr, &ch, &next);
		table[addr] = next;
	}
	int x = s1, y = s2;
	//通过遍历把两个单词的地址记录下来
	while (x != -1)
	{
		word1.push_back(x);
		x = table[x];
	}
	while (y != -1)
	{
		word2.push_back(y);
		y = table[y];
	}
	reverse(word1.begin(), word1.end());
	reverse(word2.begin(), word2.end());
	int i = 0, l1 = word1.size(), l2 = word2.size();
	for (; i < l1 && i < l2; i++)
		if (word1[i] != word2[i]) break;
	if (!i) printf("-1");
	else printf("%05d", word1[i - 1]);
	return 0;
}
