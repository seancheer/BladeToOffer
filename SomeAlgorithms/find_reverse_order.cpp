#include "find_reverse_order.h"
/************************************************************************/
/* 查找数组中所有的逆序对的个数，如果前面的数字大于后面的数字，那么可以组成一个逆序对，如
/* (7,5,6,4)的逆序对为: (7,5),(7,6),(7,4),(5,4),(6,4)，那么结果为5
/************************************************************************/

/************************************************************************/
/* 解题思路：
/* 将数组进行等分，直到分到长度为1，比较两个等分数组是否为逆序对，比较完之后在将长度为1的数组
/* 排序重新放入数组中（避免后面又被重复计算），然后继续比较，依次进行递归调用，类似于归并排序
/* 注意:  这道题有一个变形，就是leetcode上面的，有一个叫做important reverse order，定义为
/* 前面的数大于后面的数*2，即为important reverse order。由于数组可能存在负数，所以这里的解法
/* 需要修改。链接如下：（解法见下面）
/* https://leetcode.com/problems/reverse-pairs/submissions/
/************************************************************************/
void find_reverse_order_in_arr(int* arr, int size)
{
	if (NULL == arr || 0 >= size)
	{
		return;
	}

	int* copy = (int*)malloc(sizeof(int) * size);
	memset(copy, 0, sizeof(int) * size);

	for (int i = 0; i < size; ++i)
	{
		copy[i] = arr[i];
	}

	int count = reverse_order_internal(arr, copy, 0, size - 1);
	printf("The sum of reverse order in this arr:%d\n", count);
	free(copy);
}

/************************************************************************/
/* 内部递归进行统计
/************************************************************************/
int reverse_order_internal(int* arr, int* copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = arr[start];
		return 0;
	}

	int mid = (start + end) >> 1;
	int left = reverse_order_internal(arr, copy, start, mid);
	int right = reverse_order_internal(arr, copy, mid + 1, end);

	int l_index = mid;
	int r_index = end;
	int copy_index = end;

	int count = 0;
	//如果左边的数比右边的数大，那么说明存在逆序对，由于子数组都是排好序的，因此，此时逆序对的个数为
	//右边比当前数小的数的个数，比如左边为(2,4,6),右边为(3,4,5)，那么由于6比5大，所以此时逆序对个数为3，因为3,4都比5小
	while (l_index >= start && r_index >= mid + 1)
	{
		if (arr[l_index] > arr[r_index])
		{

			copy[copy_index--] = arr[l_index--];
			count += (r_index - mid);
		}
		//不存在逆序对
		else
		{
			copy[copy_index--] = arr[r_index--];
		}
	}

	while (l_index >= start)
	{
		copy[copy_index--] = arr[l_index--];
	}
	while (r_index >= mid + 1)
	{
		copy[copy_index--] = arr[r_index--];
	}

	for (int i = start; i <= end; ++i)
	{
		arr[i] = copy[i];
	}

	return count + left + right;
}



/************************************************************************/
/* 解题思路：
/* 这道题有一个变形，就是leetcode上面的，有一个叫做important reverse order，定义为
/* 前面的数大于后面的数*2，即为important reverse order。查找一个数组中逆序对的个数，
/* 需要注意的是，本题可能会导致32位的int overflow，因此需要对这种情况进行处理。
/* 链接如下：
/* https://leetcode.com/problems/reverse-pairs/submissions/
/************************************************************************/
void find_important_reverse_order_in_arr(int* arr, int size)
{
	if (NULL == arr || 0 >= size)
	{
		return;
	}

	int* copy = (int*)malloc(sizeof(int) * size);
	memset(copy, 0, sizeof(int) * size);

	for (int i = 0; i < size; ++i)
	{
		copy[i] = arr[i];
	}

	int count = important_reverse_order_internal(arr, copy, 0, size - 1);
	printf("The sum of IMPORTANT reverse order in this arr:%d\n", count);
	free(copy);
}

/************************************************************************/
/* 内部递归进行统计
/************************************************************************/
int important_reverse_order_internal(int* arr, int* copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = arr[start];
		return 0;
	}

	int mid = (start + end) >> 1;
	int left_count = important_reverse_order_internal(arr, copy, start, mid);
	int right_count = important_reverse_order_internal(arr, copy, mid + 1, end);

	int l_index = mid;
	int r_index = end;
	int copy_index = end;

	int count = 0;
	//如果左边的数比右边的数大，那么说明存在逆序对，由于子数组都是排好序的，因此，此时逆序对的个数为
	//右边比当前数小的数的个数，比如左边为(2,4,6),右边为(3,4,5)，那么由于6比5大，所以此时逆序对个数为3，因为3,4都比5小
	int left = l_index;
	int right = r_index;
	//统计满足条件的个数
	while (left >= start && right >= mid + 1)
	{
		//由于leetcode里面有可能会越界的情况，所以这里强转为64位。
		if ((int64_t)(arr[left]) > (int64_t)(arr[right]) * 2)
		{
			count += (right - mid);
			--left;
		}
		else
		{
			--right;
		}
	}


	//按照顺序排好
	while (l_index >= start && r_index >= mid + 1)
	{
		if (arr[l_index] > arr[r_index])
		{

			copy[copy_index--] = arr[l_index--];
		}
		else
		{
			copy[copy_index--] = arr[r_index--];
		}
	}

	while (l_index >= start)
	{
		copy[copy_index--] = arr[l_index--];
	}
	while (r_index >= mid + 1)
	{
		copy[copy_index--] = arr[r_index--];
	}

	for (int i = start; i <= end; ++i)
	{
		arr[i] = copy[i];
	}

	return count + left_count + right_count;
}


/************************************************************************/
/* 开始算法
/************************************************************************/
void start_print_reverse_order()
{
	const int size = 4;
	int arr[size] = { 7, 5, 6, 4 };
	find_important_reverse_order_in_arr(arr, size);

	const int size1 = 5;
	int arr1[size1] = { 1, 3, 2, 3, 1 };
	find_important_reverse_order_in_arr(arr1, size1);

	const int size2 = 5;
	int arr2[size2] = { 2, 4, 3, 5, 1 };
	find_important_reverse_order_in_arr(arr2, size2);

	const int size3 = 2;
	int arr3[size3] = { -5, -5 };
	find_important_reverse_order_in_arr(arr3, size3);


	const int size4 = 6;
	int arr4[size4] = { 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647 };
	find_important_reverse_order_in_arr(arr4, size4);
}