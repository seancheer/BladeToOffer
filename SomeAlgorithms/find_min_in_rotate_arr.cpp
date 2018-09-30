#include "find_min_in_rotate_arr.h"
/************************************************************************/
/* 在递增的旋转数组中查找最小的数
/* 旋转数组指：从数组的开头一直到任意的某个位置，将这一段范围内的数字移动到
/* 数组末尾，这就是一个旋转数组
/* 查找最小值可以用O(n)的时间找到，但是该数组是一个递增的旋转数据，因此可以采用类似于
/* 二分法的方式在O(nlogn)的时间内找到最小值.
/************************************************************************/


/************************************************************************/
/* 解决思路：采用二分法查找。注意处理一下情况：10111和11101
/************************************************************************/
int find_min_in_rotate_arr(int arr[], unsigned int size)
{
	if (NULL == arr || size == 0)
	{
		puts("Invalid parameter!\n");
		return -1;
	}


	int left = 0;
	int right = size - 1;
	int min_value = arr[0];

	while ((right - left) > 1)
	{
		int mid = (left + right) >> 1;

		//此时已经是递增的了
		if (arr[left] < arr[mid] && arr[mid] < arr[right])
		{
			return arr[left];
		}
		
		if (arr[left] == arr[right] && arr[left] == arr[mid])
		{
			return find_min_value_in_order(arr, size);
		}

		if (arr[left] <= arr[mid])
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}

	return arr[left] < arr[right] ? arr[left] : arr[right];
}


/************************************************************************/
/* 顺序从arr中查找到最小的value
/************************************************************************/
int find_min_value_in_order(int arr[], unsigned int size)
{
	int min_value = arr[0];
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] < min_value)
		{
			min_value = arr[i];
		}
	}

	return min_value;
}

/************************************************************************/
/* 算法的入口
/************************************************************************/
void start_find_min_value()
{
	int arr[] = { 2,1 };
	do_start_find_min_value(arr, 2, 1);
	int arr1[] = { 1,2 };
	do_start_find_min_value(arr1, 2, 1);

	int arr2[] = { 1,2,3 };
	do_start_find_min_value(arr2, 3, 1);

	int arr3[] = { 2,3,1 };
	do_start_find_min_value(arr3, 3, 1);

	int arr4[] = { 3,1,2 };
	do_start_find_min_value(arr4, 3, 1);

	int arr5[] = { 1,2,3,4};
	do_start_find_min_value(arr5, 4, 1);

	int arr6[] = { 2,3,4,1 };
	do_start_find_min_value(arr6, 4, 1);

	int arr7[] = { 3,4,1,2 };
	do_start_find_min_value(arr7, 4, 1);
}

void do_start_find_min_value(int arr[], int size, int expected)
{
	int value = find_min_in_rotate_arr(arr, size);
	printf("value should be %d! value:%d\n", expected, value);
}