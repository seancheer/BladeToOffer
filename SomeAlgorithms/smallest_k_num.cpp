#include "smallest_k_num.h"
/************************************************************************/
/* 查找一个数组中最小的k个数，比如一个数组：4,5,1,6,2,7,3,8，那么最小的k个数为
/* 1,2,3,4
/************************************************************************/

/************************************************************************/
/* 基于partion的思路，源于快速排序的思想，由于每次的pivot总是被排序到了最终的位置，
/* 因此可以基于该思想求解该题。该解法适用于数据量比较小的时候。
/************************************************************************/
void find_smallest_k_num_partion(int* arr, int size, int k)
{
	if (NULL == arr || k <= 0)
	{
		puts("Invalid para!");
		return;
	}

	int i = 0;
	int part_index = smallest_k_num_partion(arr, 0, size - 1);
	while (part_index != k - 1)
	{
		if (part_index < k - 1)
		{
			part_index = smallest_k_num_partion(arr, part_index + 1, size - 1);
		}
		else
		{
			part_index = smallest_k_num_partion(arr, 0, part_index - 1);
		}
	}

	//打印最终的结果
	puts("*****************************PARTITION**********************************");
	for (int i = 0; i < k; ++i)
	{
		printf("%d\t", arr[i]);
	}
	puts("\n**********************************************************************");
}


int smallest_k_num_partion(int* arr, int low, int high)
{
	int i = low;
	int j = high;
	int pivot = arr[high];

	while (i < j)
	{
		while (i < j && arr[i] <= pivot)
		{
			++i;
		}

		while (i < j && arr[j] >= pivot)
		{
			--j;
		}

		swap(arr + i, arr + j);
	}

	swap(arr + i, arr + high);
	return i;
}

/************************************************************************/
/* 最容易想到的思路，适用于海量数据。
/* 思路：
/* 运用数据结构（比如队列或者红黑树）存储k个数，如果当前数据结构没有满，那么扫描到一个数字
/* 就放进去，否则的话，拿到当前数据结构中最大的数，如果扫描到的数比最大的数都大，那么继续扫描下一个
/* 否则，替换掉当前最大的数，最后把数据结构中的数挨个打印出来即可
/************************************************************************/
void find_smallest_k_num_many_data(int* arr, int size, int k)
{
	if (NULL == arr || k <= 0)
	{
		puts("Invalid para!");
		return;
	}

	priority_queue<int, vector<int>, SmallestKCompare> q;

	for (int i = 0; i < size; ++i)
	{
		int q_size = q.size();
		if (q_size < k)
		{
			q.push(arr[i]);
		}
		else
		{
			int top_num = q.top();
			if (arr[i] < top_num)
			{
				q.pop();
				q.push(arr[i]);
			}
		}
	}

	//打印最终的结果
	puts("*************************MANY_DATA*************************************");
	while (!q.empty())
	{
		printf("%d\t", q.top());
		q.pop();
	}
	puts("\n**********************************************************************");
}


/************************************************************************/
/* 开始算法
/************************************************************************/
void start_find_smallest_k_num()
{
	const int size = 8;
	int arr[size] = { 4, 5, 8, 6, 2, 7, 3, 1 };
	int k = 4;
	find_smallest_k_num_partion(arr, size, k);
	find_smallest_k_num_many_data(arr, size, k);
}
