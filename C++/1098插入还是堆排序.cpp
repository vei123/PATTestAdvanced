#include<iostream>
using namespace std;
/*
跟之前的1089插入还是归并类似，实际上堆排序比归并还简单点：
还是以插入排序为突破口，对第二个序列从前往后顺序遍历，找到第一个
不满足升序的元素，切换模式并继续往后遍历，如果这之后的任何一个元素
都与第一个序列的对应位置元素相同，那么就是插入排序，否则是堆排序

对于插入排序很简单，把之前不符合升序的元素向前插入到合适位置即可

对于堆排序，题目中其实没说清楚，要你自己对堆排序很了解才能懂题意：
现在第二个序列的左边部分是"已经构建好"的大顶堆，右边是"已经排好"的序列，
你现在需要做的就是先把第一个元素与大顶堆的最后一个元素交换，然后堆的
尺寸减一，再对堆顶元素做下沉操作，最后再返回序列，这个序列与开头一样，
仍然是左边是一个构建好的堆，右边是排好序的序列，只不过尺寸一个小了一个大了而已
*/
signed main()
{
	ios::sync_with_stdio(0);
	int n, a[105], b[105], index;
	bool flag = 0, mode = 1;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 1; i < n; i++)
	{
		if (flag)
		{
			if (a[i] != b[i])
			{
				cout << "Heap Sort\n";
				mode = 0;
				break;
			}
		}
		else
		{
			if (b[i] < b[i - 1])
			{
				index = i;
				flag = 1;
			}
		}
		if (i == n - 1)
		{
			cout << "Insertion Sort\n";
			mode = 1;
			break;
		}
	}
	if (mode)
	{
		int key = b[index];
		int j = index;
		while (key < b[j - 1])
		{
			b[j] = b[j - 1];
			j--;
		}
		b[j] = key;
		for (int i = 0; i < n; i++)
		{
			if (i) cout << ' ';
			cout << b[i];
		}
	}
	else
	{
		for (int i = n - 1; i > 0; i--)
		{
			if (b[i] < b[0])
			{
				index = i;
				break;
			}
		}
		swap(b[0], b[index]);
		int present = 0, origin = 0;
		while (1)
		{
			int left = 2 * present + 1;
			int right = 2 * present + 2;
			if (left < index && b[present] < b[left]) present = left;
			if (right < index && b[present] < b[right]) present = right;
			if (present != origin)
			{
				swap(b[present], b[origin]);
				origin = present;
			}
			else break;
		}
		for (int i = 0; i < n; i++)
		{
			if (i) cout << ' ';
			cout << b[i];
		}
	}
	return 0;
}
