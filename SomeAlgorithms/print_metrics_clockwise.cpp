#include "print_metrics_clockwise.h"

/************************************************************************/
/* 顺时针打印矩阵
/* 思路：
/* 定义4个边界row_top,row_bottom,col_left,col_right，然后循环从左上角开始打印，每次循环完成后,row_top++, row_bottom--,
/* col_left++,col_right--，循环终止条件为row_top和row_bottom相遇或者col_left和col_right相遇。
/* 当循环终止后，会发生以下情况：数组中只剩下一个，只剩下一行，只剩下一列，要分别对应处理。
/*
/* 书中的思路：和我的基本一致，不同的是，只传入左上角的坐标，然后通过row - 1 - start得到每次循环打印的终止边界。
/************************************************************************/
void print_metrics_clockwise(int* arr, int row, int col)
{
	if (NULL == arr || row <= 0 || col <= 0)
	{
		puts("Invalid argument!");
		return;
	}

	int row_top = 0;
	int row_bottom = row - 1;
	int col_left = 0;
	int col_right = col - 1;

	int x = row_top;
	int y = col_left;

	while (x < row_bottom && y < col_right)
	{
		//从左往右打
		while (y < col_right)
		{
			printf("%d\t", ARR_INDEX(arr, x, y));
			++y;
		}

		//从上往下打
		while (x < row_bottom)
		{
			printf("%d\t", ARR_INDEX(arr, x, y));
			++x;
		}

		//从右往左打
		while (y > col_left)
		{
			printf("%d\t", ARR_INDEX(arr, x, y));
			--y;
		}

		//从下往上打
		while (x > row_top)
		{
			printf("%d\t", ARR_INDEX(arr, x, y));
			--x;
		}


		//缩小四个边界
		x = ++row_top;
		y = ++col_left;

		if (col_right > 0)
		{
			--col_right;
		}

		if (row_bottom > 0)
		{
			--row_bottom;
		}
	}

	//如果有行或者列某一个是2的话，那么循环一次就打完了
	if (row == 2 || col == 2)
	{
		printf("\n");
		return;
	}

	//考虑只剩下一行或者一列的情况
	while (x < row_bottom)
	{
		printf("%d\t", ARR_INDEX(arr, x, y));
		++x;
	}

	while (y < col_right)
	{
		printf("%d\t", ARR_INDEX(arr, x, y));
		++y;
	}

	//考虑只剩下一个的情况
	if (x == row_bottom && y == col_right)
	{
		printf("%d\t", ARR_INDEX(arr, x, y));
	}

	printf("\n");
}

/************************************************************************/
/* 顺时针打印矩阵，书中的实现方式
/* 从左上角开始，记录左上角的坐标，然后依次从左上角打印
/* 从左往右打：只要能进入while循环，说明需要打
/* 从上往下打：起始行号小于终止行号
/* 从右往左打：至少有两行两列
/* 从下往上打：至少有三行两列
/* 上述逻辑不难分析出来。
/************************************************************************/
void print_metrics_clockwise_in_book(int* arr, int row, int col)
{
	if (NULL == arr || row <= 0 || col <= 0)
	{
		puts("Invalid argument!");
		return;
	}

	int start = 0;
	while (row > start * 2 && col > start * 2)
	{
		int i = 0;
		int end_row = row - start - 1;
		int end_col = col - start - 1;

		//从左往右打
		for (i = start; i <= end_col; ++i)
		{
			printf("%d\t", ARR_INDEX(arr,start,i));
		}

		//打印的条件是：终止行号必须大于起始行号
		if (start < end_row)
		{
			//从上往下打
			for (i = start + 1; i <= end_row; ++i)
			{
				printf("%d\t", ARR_INDEX(arr, i, end_col));
			}
		}

		//打印的条件是：至少有两行两列
		if (start < end_col && start < end_row)
		{
			//从右往左打
			for (i = end_col - 1; i >= start; --i)
			{
				printf("%d\t", ARR_INDEX(arr, end_row, i));
			}
		}

		//打印的条件是：至少有三行两列
		if (start < end_col && start < end_row - 1)
		{
			//从下往上打
			for (i = end_row - 1; i > start; --i)
			{
				printf("%d\t", ARR_INDEX(arr, i, start));
			}
		}
		++start;
	}
	printf("\n");
}

/************************************************************************/
/* 算法入口
/************************************************************************/
void start_print_metrics()
{
	//书中的实例
	const int col = 4;
	const int row = 4;
	int arr[row * col] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	print_metrics_clockwise(arr, row, col);
	puts("###############");
	print_metrics_clockwise_in_book(arr, row, col);

	//只有一行的情况
	puts("*********************************************************************************************");
	const int row1 = 1;
	const int col1 = 4;
	int arr1[row1 * col1] = { 0,1,2,3 };
	print_metrics_clockwise(arr1, row1, col1);
	puts("###############");
	print_metrics_clockwise_in_book(arr1, row1, col1);


	//只有一列的情况
	puts("*********************************************************************************************");
	const int row2 = 4;
	const int col2 = 1;
	int arr2[row2 * col2] = { 0,1,2,3 };
	print_metrics_clockwise(arr2, row2, col2);
	puts("###############");
	print_metrics_clockwise_in_book(arr2, row2, col2);

	//最后只剩一个的情况
	puts("*********************************************************************************************");
	const int row3 = 3;
	const int col3 = 3;
	int arr3[row3 * col3] = { 1,2,3,4,5,6,7,8,9 };
	print_metrics_clockwise(arr3, row3, col3);
	puts("###############");
	print_metrics_clockwise_in_book(arr3, row3, col3);

}