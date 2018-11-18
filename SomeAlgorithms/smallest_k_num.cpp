#include "smallest_k_num.h"
/************************************************************************/
/* ����һ����������С��k����������һ�����飺4,5,1,6,2,7,3,8����ô��С��k����Ϊ
/* 1,2,3,4
/************************************************************************/

/************************************************************************/
/* ����partion��˼·��Դ�ڿ��������˼�룬����ÿ�ε�pivot���Ǳ����������յ�λ�ã�
/* ��˿��Ի��ڸ�˼�������⡣�ýⷨ�������������Ƚ�С��ʱ��
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

	//��ӡ���յĽ��
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
/* �������뵽��˼·�������ں������ݡ�
/* ˼·��
/* �������ݽṹ��������л��ߺ�������洢k�����������ǰ���ݽṹû��������ôɨ�赽һ������
/* �ͷŽ�ȥ������Ļ����õ���ǰ���ݽṹ�������������ɨ�赽������������������ô����ɨ����һ��
/* �����滻����ǰ���������������ݽṹ�е���������ӡ��������
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

	//��ӡ���յĽ��
	puts("*************************MANY_DATA*************************************");
	while (!q.empty())
	{
		printf("%d\t", q.top());
		q.pop();
	}
	puts("\n**********************************************************************");
}


/************************************************************************/
/* ��ʼ�㷨
/************************************************************************/
void start_find_smallest_k_num()
{
	const int size = 8;
	int arr[size] = { 4, 5, 8, 6, 2, 7, 3, 1 };
	int k = 4;
	find_smallest_k_num_partion(arr, size, k);
	find_smallest_k_num_many_data(arr, size, k);
}
