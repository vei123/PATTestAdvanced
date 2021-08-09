#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//整个流程的逻辑分析：
//先将输入的所有用户信息存入vector数组中
//然后对从08:00:00开始的每一个时刻(按秒为最小刻度)按先后顺序分别进行如下四个操作：
//操作一：如果没有任何未收到服务的pair，直接结束
//操作二：将这一时刻到来的所有用户根据身份(vip或普通)情况从vector中放入等待队列
//操作三：检查用户队列与球桌队列，分配球桌，具体为：
//	while用户队列非空且有空闲桌子
//		while有等待中的vip用户且有空闲vip桌子，就分配vip桌子给vip用户
//		while有等待中的用户且有空闲桌子，进行一次最小序号分配
//操作四：将所有正在使用中的桌子中的order结构体(也就是一个“订单”)的
//stay时间减一，意味着这一秒已经过去了，当然如果剩余时间stay为0就不需要再减

//基于逻辑分析，我们需要用到如下的数据结构与变量
//1.结构体order，即订单，表示一个pair的所有信息(到来时间，剩余玩球时间，是否vip)
//2.结构体table，即桌子，包含一个order，表示在这个桌子上进行的一个order订单
//的情况，如果这个ordere的stay(剩余时间)为0，则可以视为桌子是空闲的；变量
//served表示服务过的pair数量(包含正在服务的)，vip表示是否是vip桌子
//3.一个vector数组，用于存储所有输入的pair信息
//4.另一个vector数组，用于存储所有的桌子及桌子自带的状态
//5.两个队列(实际用vector)，一个普通用户等待队列，一个vip用户等待队列
//普通用户只能存入普通队列，vip同时存入两个队列
//6.一些控制变量，包括但不限于：
//	表示空闲的vip球桌viptabcnt和空闲的普通球桌数量comtabcnt
//7.存储要输出结果的vector数组ans

struct order
{
	//come：到来时间，stay：剩余时间，vip：是否vip用户
	int come, stay, vip;
	bool operator<(const order& o) {return this->come < o.come;}
};

struct table
{
	//vip：是否vip桌子，served：服务过的pair数量
	int vip, served;
	//o：在这个桌子上正在进行的使用(或“订单”)状态
	order o;
	table() :vip(0), served(0), o(order()) {}
};

struct record
{
	int come, start;
	record(int come, int start) : come(come), start(start) {}
	bool operator<(const record& r)
	{
		if (this->start != r.start) return this->start < r.start;
		else return this->come < r.come;
	}
};

//分别表示pair数量，桌子总数，vip桌子数量
int n, k, m;
vector<order> input;
vector<table> tables;
vector<order> vipq, comq;
//将要返回的结果写入ans中，最后排序后再输出，这样要简单一些
vector<record> ans;
int viptabcnt, comtabcnt, totalserved = 0;
const int CLOCK8 = 3600 * 8;
const int CLOCK21 = 3600 * 21;

//从普通用户队列中pop出一个vip用户，因为他已经提前得到服务
void popvip()
{
	for (auto it = comq.begin();; it++)
	{
		if (it->vip)
		{
			comq.erase(it);
			break;
		}
	}
}

void printtime(int time)
{
	int hh, mm, ss;
	hh = time / 3600;
	mm = time % 3600 / 60;
	ss = time % 60;
	printf("%02d:%02d:%02d", hh, mm, ss);
}

//打印输出信息，i为得到服务时间，j为服务的桌子号-1
void printinfo(const record& r)
{
	printtime(r.come);
	printf(" ");
	printtime(r.start);
	printf(" ");
	int ss = r.start - r.come;
	if(ss % 60 >=30) printf("%d\n", ss / 60 + 1);
	else printf("%d\n", ss / 60);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		order t;
		int hh, mm, ss;
		int minutes;
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &minutes, &t.vip);
		t.come = 3600 * hh + 60 * mm + ss;
		if (minutes > 120) minutes = 120;
		t.stay = minutes * 60;
		input.push_back(t);
	}
	sort(input.begin(), input.end());
	scanf("%d %d", &k, &m);
	viptabcnt = m;
	comtabcnt = k - m;
	for (int i = 0; i < k; i++)
		tables.push_back(table());
	for (int i = 0; i < m; i++)
	{
		int j;
		scanf("%d", &j);
		tables[j - 1].vip = 1;
	}
	for (int i = CLOCK8; i < CLOCK21; i++)
	{
		//操作一，检查是否提前结束
		if (input.empty() && comq.empty()) break;
		//操作二，更新等待队列
		while (!input.empty() && input[0].come <= i)
		{
			comq.push_back(input[0]);
			if (input[0].vip) vipq.push_back(input[0]);
			input.erase(input.begin());
		}
		//操作三，分配球桌
		while (viptabcnt && !vipq.empty())
		{
			for (int j = 0; j < k; j++)
			{
				if (tables[j].vip && !tables[j].o.stay)
				{
					tables[j].o = vipq[0];
					ans.push_back(record(tables[j].o.come, i));
					tables[j].served++;
					popvip();
					vipq.erase(vipq.begin());
					viptabcnt--;
					break;
				}
			}
		}
		while (!comq.empty() && viptabcnt + comtabcnt)
		{
			for (int j = 0; j < k; j++)
			{
				if (!tables[j].o.stay)
				{
					tables[j].o = comq[0];
					ans.push_back(record(tables[j].o.come, i));
					tables[j].served++;
					if (comq[0].vip) vipq.erase(vipq.begin());
					comq.erase(comq.begin());
					if (tables[j].vip) viptabcnt--;
					else comtabcnt--;
					break;
				}
			}
		}
		//操作四
		for (int j = 0; j < k; j++)
		{
			if (tables[j].o.stay)
			{
				if (--tables[j].o.stay == 0)
				{
					if (tables[j].vip) viptabcnt++;
					else comtabcnt++;
				}
			}
		}
	}
	//排序，如果没有这一步则无法AC
	sort(ans.begin(), ans.end());
	for (auto r : ans) printinfo(r);
	for (int i = 0; i < k; i++)
	{
		printf("%d", tables[i].served);
		if (i != k - 1) printf(" ");
	}
	printf("\n");
	return 0;
}
