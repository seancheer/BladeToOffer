#include "more_than_half_in_arr.h"


/************************************************************************/
/* Ѱ�������г��ִ����������鳤��һ�������,ע�⣬����������з�������������ֻ��һ��
/************************************************************************/

/************************************************************************/
/* �ⷨһ��ͨ�����������������ÿ��partion��pivot������λ���������������λ����λ�ã�
/* ��ô���ֵ�������յĽ�����������������λ����ߣ���ô���ұ߽���partition������
/* ���ұ߽���partition��ֱ���ҵ����յĽ��Ϊֹ
/* ��ʱ��ʱ�临�Ӷ�ΪO(n)
/************************************************************************/
int solution_inspired_by_qsort(int *arr, int size)
{
	if (NULL == arr)
	{
		puts("Invalid para!");
		return -1;
	}

	int mid = size >> 1;
	int index = more_than_half_partition(arr, 0, size - 1);
	
	while (index != mid)
	{
		//���ұ���
		if (index < mid)
		{
			index = more_than_half_partition(arr, index + 1, size - 1);
		}
		else
		{
			index = more_than_half_partition(arr, 0, index - 1);
		}
	}

	return arr[mid];
}


int more_than_half_partition(int *arr, int low, int high)
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

	swap(arr + high, arr + i);
	return i;
}

/************************************************************************/
/* �ⷨ2��ͨ��һ�ε����ķ�ʽ�Ϳ��Բ��ҵ����ִ�������һ�������
/* ��¼����ֵ�����ֳ��ֵĴ���times��ĳ������number������һ�����ֺ�number���ʱ��
/* times + 1���������ȣ���1����Ϊ0��ʱ�򣬽�times����Ϊ0��number��Ϊ��һ�����֣�
/* ��ô��������Ϻ�number����¼�����ּ�Ϊ����һ�������
/************************************************************************/
int solution_by_times_of_num(int* arr, int size)
{
	if (NULL == arr)
	{
		puts("Invalid para!");
		return -1;
	}
	
	int times = 1;
	int number = arr[0];
	int i = 1;

	while (i < size)
	{
		if (times == 0)
		{
			number = arr[i];
			times = 1;
		}
		else if (arr[i] == number)
		{
			++times;
		}
		else
		{
			--times;
		}

		++i;
	}

	return number;
}

/************************************************************************/
/* �㷨���
/************************************************************************/
void start_more_than_half()
{
	const int size = 9;
	int arr[size] = { 1,2,3,2,2,2,5,4,2 };
	int result = solution_inspired_by_qsort(arr, size);
	printf("More than half:%d\n", result);
	result = solution_by_times_of_num(arr, size);
	printf("More then half(timesOfNum):%d\n", result);

	const int size1 = 3;
	int arr1[size1] = { 3,1,3 };
	int result1 = solution_inspired_by_qsort(arr1, size1);
	printf("More than half:%d\n", result1);
	printf("More then half(timesOfNum):%d\n", result1);
}