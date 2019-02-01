#include "dynamic_programming.h"

/************************************************************************/
/* 最大公共子串,注意与最大公共子序列进行区分，该问题的递归公式为：
/* dp[i][j]表示str1中0到i，str2中0到j的最大公共子串，那么dp[i][j]的公式为：
/* dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]  + 1(when str1[i] == str2[j]))
/************************************************************************/
int max_common_sub_arr(const char* str1, const char* str2)
{
	if (NULL == str1 || NULL == str2)
	{
		puts("Invalid para!");
		return -1;
	}

	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 <= 0 || len2 <= 0)
	{
		puts("Invalid para!");
		return -1;
	}

	int** dp = malloc_2d_arr(len1 + 1, len2 + 1);
	int result = 0;
	for (int i = 0; i < len1; ++i)
	{
		for (int j = 0; j < len2; ++j)
		{
			if (str1[i] == str2[j])
			{
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
				if (dp[i + 1][j + 1] > result)
				{
					result = dp[i + 1][j + 1];
				}
			}
		}
	}

	free_2d_arr(dp, len1 + 1, len2 + 2);
	return result;
}


/************************************************************************/
/* 最大递增子序列
/************************************************************************/
int max_increment_sequence(const char* str)
{
	return -1;
}


/************************************************************************/
/* 0-1背包问题
/************************************************************************/
int zero_one_pack(vector<int>& weight, vector<int>& val, int capacity)
{
	return -1;
}


/************************************************************************/
/* 申请二维数组
/************************************************************************/
int** malloc_2d_arr(int row, int col)
{
	int** arr = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; ++i)
	{
		arr[i] = (int*)malloc(sizeof(int) * col);
		memset(arr[i], 0, sizeof(int) * col);
	}

	return arr;
}

/************************************************************************/
/* 释放二维数组
/************************************************************************/
void free_2d_arr(int** arr, int row, int col)
{
	if (NULL == arr || NULL == *arr)
	{
		puts("Invalid arr!");
		return;
	}

	for (int i = 0; i < row; ++i)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr);
}

/************************************************************************/
/* 算法入口
/************************************************************************/
void start_dynamic_programming()
{
	const char* str1 = "abacdefg";
	const char* str2 = "cdeabcde";
	int result = max_common_sub_arr(str1, str2);
	printf("Max common sub arr:%d\n", result);
}