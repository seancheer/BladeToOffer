#include "maxinum_sub_arr.h"
/************************************************************************/
/* 求解一个数组中连续和最大的子数组，总共有以下解法：
/* 1 暴力求解
/* 2 分治法，算法导论上面有提及
/* 3 动态规划法
/************************************************************************/

/************************************************************************/
/* 动态规划算法
/* 动态规划推导公式为：max_sub(0...j + 1) = max(max_sub(0...j), max_sub(0...j + 1))
/* 思路：
/* 0-j + 1的最大子数组结果为0-j的最大子数组或者0-j + 1的最大子数组，对于0-j，开始往后
/* 扫描每一个数：
/* 如果这个数加上之前的sum比sum大，那么，更新sub_right，否则，继续往后扫。
/* 如果这个数加上之前的sum小于等于sum，但是大于0，那么继续往后扫，什么都不更新
/* 如果这个数加上之前的sum小于0，那么sub_left为更新为这个数的下一个，重新开始计算。
/************************************************************************/
void find_max_sub_arr_dp(int* arr, int size, int& low, int& high, int& sum)
{
	if (NULL == arr || size <= 0)
	{
		puts("Invalid para!");
		return;
	}

	int tmp = 0;
	low = 0;
	high = 0;
	int tmp_low = 0;

	for (int i = 0; i < size; ++i)
	{
		tmp += arr[i];
		if (tmp >= sum)
		{
			sum = tmp;
			high = i;
			low = tmp_low;
		}
		//说你数组到此为止已经比0小了，那么此时从下一个开始重新计算
		else if (tmp < 0)
		{
			if (i + 1 >= size)
			{
				continue;
			}

			tmp_low = i + 1;
			tmp = 0;
		}
	}
}

void start_find_max_sub()
{
	const int size = 8;
	int arr[size] = { 1,-2,3,10,-4,7,2,-5 };
	int sum = INT_MIN;
	int low = 0;
	int high = 0;
	find_max_sub_arr_dp(arr,size,low,high,sum);
	puts("********************************************************************");
	for (int i = low; i <= high; ++i)
	{
		printf("%d\t", arr[i]);
	}
	puts("\n********************************************************************");
}