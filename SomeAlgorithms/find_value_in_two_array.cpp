#include "find_value_in_two_array.h"
/************************************************************************/
/* 题目介绍（剑指offer p38）：
/* 在二维数据中查找对应的数字：
/* 二维数组格式为：竖向递增，横向递增；查找任意一个数字是否出现
/************************************************************************/


/************************************************************************/
/* 算法的入口                                                                     */
/************************************************************************/
void start_find_value()
{
	int arr[4][4] = {
		1,2,8,9,
		2,4,9,12,
		4,7,10,13,
		6,8,11,15
	};

	bool result = find_value_in_array(arr, 15, 4);
	if (result)
	{
		printf("find it!\n");
	}

	result = find_value_in_array(arr, 100, 4);
	if (!result)
	{
		printf("You should not find it!\n");
	}


}


/************************************************************************/
/* 在二维数组中查询指定的数据，true表示成功，false表示没有
/************************************************************************/
bool find_value_in_array(int arr[][4], int target, int x_size)
{
	int x = 0;
	int y = 3;

	while (x < x_size && y >= 0)
	{
		int cur_value = arr[x][y];
		if (cur_value == target)
		{
			return true;
		}

		//往下走
		if (target > cur_value && x < x_size - 1)
		{
			++x;
			continue;
		}
		//往左走
		else if (target < cur_value && y > 0)
		{
			--y;
			continue;
		}

		return false;
	}

	return false;
}