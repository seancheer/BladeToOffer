#include "count_num_times_in_sorted_arr.h"

/************************************************************************/
/* 统计数字在排序数组中出现的次数
/* 常规的算法就是遍历数组，然后统计目标数字出现的次数，或者使用二分法找到第一个，然后前后遍历即可。
/* 但是这样做的一个坏处是当数组出现该数字比较多的时候，需要遍历较多的次数，属于比较常规的做法。
/* 最高效的做法如下，算法思路：
/*   通过二分法找到第一次出现target的位置和最后一次出现target的位置，然后下标相减，得出最终答案，该方法
/* 可有效减少遍历数组的个数。
/************************************************************************/
int count_num_times(int* arr, int size, int target)
{
	if (NULL == arr || size <= 0)
	{
		puts("Invalid para!");
		return 0;
	}

	if (1 == size)
	{
		return 1;
	}

	int left = 0;
	int right = size - 1;
	int first_index = 0;
	int last_index = right;
	bool find_target = false;

	//二分法需要注意每次mid要+1和-1
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (arr[mid] > target)
		{
			right = mid - 1;
		}
		else if (arr[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			find_target = true;
			first_index = find_first_target(arr, left, mid, target, size);
			last_index = find_last_target(arr, mid, right, target, size);
			break;
		}
	}
	
	if (!find_target)
	{
		return 0;
	}

	return (last_index - first_index) + 1;
}


int find_first_target(int* arr, int start, int end, int target, int size)
{
	while (start <= end)
	{
		int mid = (start + end) >> 1;
		if (arr[mid] == target)
		{
			//如果发现前一个不是target，那么说明找到位置了
			if (mid - 1 < 0 || arr[mid - 1] != target)
			{
				return mid;
			}

			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}

	return end;
}

int find_last_target(int* arr, int start, int end, int target, int size)
{
	while (start <= end)
	{
		int mid = (start + end) >> 1;
		if (mid + 1 >= size ||  arr[mid] == target)
		{
			if (arr[mid + 1] != target)
			{
				return mid;
			}

			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	return start;
}


/************************************************************************/
/* 开始算法
/************************************************************************/
void start_count_num_times()
{
	const int size = 5;
	int arr[size] = { 2,3,3,3,4};
	int target = 3;
	int result = count_num_times(arr, size, target);
	printf("count %d in arr times:%d!\n", target, result);

}