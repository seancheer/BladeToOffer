#include "more_than_half_in_arr.h"


/************************************************************************/
/* 寻找数组中出现次数超过数组长度一般的数字,注意，输入的数组中符合条件的数字只有一个
/************************************************************************/

/************************************************************************/
/* 解法一：通过快速排序的启发，每次partion的pivot的最终位置如果处于数组中位数的位置，
/* 那么这个值就是最终的结果，否则，如果处于中位数左边，那么对右边进行partition，否则
/* 对右边进行partition，直到找到最终的结果为止
/* 此时的时间复杂度为O(n)
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
		//往右边走
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
/* 解法2：通过一次迭代的方式就可以查找到出现次数大于一半的数字
/* 记录两个值，数字出现的次数times和某个数字number，当下一个数字和number相等时，
/* times + 1，如果不相等，减1，当为0的时候，将times设置为0，number记为下一个数字，
/* 那么当迭代完毕后，number所记录的数字即为超过一半的数字
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
/* 算法入口
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