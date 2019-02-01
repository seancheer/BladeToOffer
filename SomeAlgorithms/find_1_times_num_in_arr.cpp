#include "find_1_times_num_in_arr.h"

/************************************************************************/
/* 一个数组中，除了两个数字只出现过一次之外，其他均出现了两次，请查找出这两个数字，要求：时间复杂度为O(n)，
/* 空间复杂度为O(1)
/* 该题的简单版本：
/*     一个数组中除了一个数只出现过一次，其他数字均出现过两次，要求在O(n)的时间内求出该数：对数组中的数
/* 挨个进行异或操作，由于两个相同的数异或的结果必然是0，所以，最后异或的结果就是目标数字
/* 思路：
/*     1 首先对该数组中的数挨个进行异或，最终的结果必然是只出现一次的两个数，接下来需要想办法将数组
/* 分为两个小的子数组，保证将只出现过一次的数分配到两个子数组，且两个子数组保证完整包含了出现了两次
/* 的数字
/*     2 对于1中异或的最终结果，找出其二进制中从左到右第一个出现1的位置，然后根据该位置是否为1对数组进行
/* 分组，相同的数该位置必然为1，并且，只出现过一次的这两个数，该位置一个必然为1，一个必然为0，因此能被划分
/* 到两个子数组中
/*     3 问题退化到的简单版本，得到最终的结果
/* 注意：由于该题要求的空间复杂度为O(1)，因此，实际代码中没必须对数组进行真正的“划分”
/************************************************************************/

void find_1_times_num_in_arr(int* arr, int size, int numbers[2])
{
	if (NULL == arr || size <= 1)
	{
		puts("Invalid para!");
		return;
	}

	int result = 0;
	for (int i = 0; i < size; ++i)
	{
		result ^= arr[i];
	}

	int index1 = find_first_1_index(result);
	int index_number = 1 << index1;

	int number1 = 0;
	int number2 = 0;
	for (int i = 0; i < size; ++i)
	{
		int tmp = arr[i];
		//注意符号优先级的问题，这里面的==优先级比&大
		if ((tmp & index_number) == 0)
		{
			number1 ^= tmp;
		}
		else
		{
			number2 ^= tmp;
		}
	}

	numbers[0] = number1;
	numbers[1] = number2;
}

/************************************************************************/
/* 查找第一个1的位置
/************************************************************************/
int find_first_1_index(int result)
{
	int index = 0;
	while ((result & 1) == 0)
	{
		result >>= 1;
		++index;
	}

	return index;
}

/************************************************************************/
/* 开始算法
/************************************************************************/
void start_find_1_times_num()
{
	int numbers[2] = { 0,0 };
	const int size = 8;
	int arr[size] = { 2,4,3,6,3,2,5,5 };
	find_1_times_num_in_arr(arr, size, numbers);
	printf("Number only 1 times:%d\t%d\n", numbers[0], numbers[1]);


	int numbers1[2] = { 0,0 };
	const int size1 = 2;
	int arr1[size1] = { 2,4};
	find_1_times_num_in_arr(arr1, size1, numbers1);
	printf("Number only 1 times:%d\t%d\n", numbers1[0], numbers1[1]);
}