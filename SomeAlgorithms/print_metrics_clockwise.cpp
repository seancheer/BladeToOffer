#include "print_metrics_clockwise.h"

/************************************************************************/
/* ˳ʱ���ӡ����
/* ˼·��
/* ����4���߽�row_top,row_bottom,col_left,col_right��Ȼ��ѭ�������Ͻǿ�ʼ��ӡ��ÿ��ѭ����ɺ�,row_top++, row_bottom--,
/* col_left++,col_right--��ѭ����ֹ����Ϊrow_top��row_bottom��������col_left��col_right������
/* ��ѭ����ֹ�󣬻ᷢ�����������������ֻʣ��һ����ֻʣ��һ�У�ֻʣ��һ�У�Ҫ�ֱ��Ӧ����
/*
/* ���е�˼·�����ҵĻ���һ�£���ͬ���ǣ�ֻ�������Ͻǵ����꣬Ȼ��ͨ��row - 1 - start�õ�ÿ��ѭ����ӡ����ֹ�߽硣
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
		//�������Ҵ�
		while (y < col_right)
		{
			printf("%d\t", ARR_INDEX(arr, x, y));
			++y;
		}

		//�������´�
		while (x < row_bottom)
		{
			printf("%d\t", ARR_INDEX(arr, x, y));
			++x;
		}

		//���������
		while (y > col_left)
		{
			printf("%d\t", ARR_INDEX(arr, x, y));
			--y;
		}

		//�������ϴ�
		while (x > row_top)
		{
			printf("%d\t", ARR_INDEX(arr, x, y));
			--x;
		}


		//��С�ĸ��߽�
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

	//������л�����ĳһ����2�Ļ�����ôѭ��һ�ξʹ�����
	if (row == 2 || col == 2)
	{
		printf("\n");
		return;
	}

	//����ֻʣ��һ�л���һ�е����
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

	//����ֻʣ��һ�������
	if (x == row_bottom && y == col_right)
	{
		printf("%d\t", ARR_INDEX(arr, x, y));
	}

	printf("\n");
}

/************************************************************************/
/* ˳ʱ���ӡ�������е�ʵ�ַ�ʽ
/* �����Ͻǿ�ʼ����¼���Ͻǵ����꣬Ȼ�����δ����ϽǴ�ӡ
/* �������Ҵ�ֻҪ�ܽ���whileѭ����˵����Ҫ��
/* �������´���ʼ�к�С����ֹ�к�
/* �����������������������
/* �������ϴ���������������
/* �����߼����ѷ���������
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

		//�������Ҵ�
		for (i = start; i <= end_col; ++i)
		{
			printf("%d\t", ARR_INDEX(arr,start,i));
		}

		//��ӡ�������ǣ���ֹ�кű��������ʼ�к�
		if (start < end_row)
		{
			//�������´�
			for (i = start + 1; i <= end_row; ++i)
			{
				printf("%d\t", ARR_INDEX(arr, i, end_col));
			}
		}

		//��ӡ�������ǣ���������������
		if (start < end_col && start < end_row)
		{
			//���������
			for (i = end_col - 1; i >= start; --i)
			{
				printf("%d\t", ARR_INDEX(arr, end_row, i));
			}
		}

		//��ӡ�������ǣ���������������
		if (start < end_col && start < end_row - 1)
		{
			//�������ϴ�
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
/* �㷨���
/************************************************************************/
void start_print_metrics()
{
	//���е�ʵ��
	const int col = 4;
	const int row = 4;
	int arr[row * col] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	print_metrics_clockwise(arr, row, col);
	puts("###############");
	print_metrics_clockwise_in_book(arr, row, col);

	//ֻ��һ�е����
	puts("*********************************************************************************************");
	const int row1 = 1;
	const int col1 = 4;
	int arr1[row1 * col1] = { 0,1,2,3 };
	print_metrics_clockwise(arr1, row1, col1);
	puts("###############");
	print_metrics_clockwise_in_book(arr1, row1, col1);


	//ֻ��һ�е����
	puts("*********************************************************************************************");
	const int row2 = 4;
	const int col2 = 1;
	int arr2[row2 * col2] = { 0,1,2,3 };
	print_metrics_clockwise(arr2, row2, col2);
	puts("###############");
	print_metrics_clockwise_in_book(arr2, row2, col2);

	//���ֻʣһ�������
	puts("*********************************************************************************************");
	const int row3 = 3;
	const int col3 = 3;
	int arr3[row3 * col3] = { 1,2,3,4,5,6,7,8,9 };
	print_metrics_clockwise(arr3, row3, col3);
	puts("###############");
	print_metrics_clockwise_in_book(arr3, row3, col3);

}