#include "print_1_to_n.h"


/************************************************************************/
/* 打印从1到n位数组成成的最大值
/* 注意大数问题即可
/* 1 最直观的解法：使用字符串模仿+1操作
/* 2 第二种解法：从0打印到最大位数，实际上就是0-9的排列组合而已，只不过打印的时候不打印
/* 最高位的0而已
/************************************************************************/
void print_1_to_max(int max_length)
{
	if (max_length < 0)
	{
		puts("Invalid argument!\n");
		exit(-1);
	}

	puts("********************************************************************************************");
	if (0 == max_length)
	{
		printf("%d\n", 0);
		puts("***************************************END**************************************************");
		return;
	}

	char* number = (char*)malloc(sizeof(char) * max_length);
	if (NULL == number)
	{
		puts("Malloc failed!\n");
		exit(-1);
	}

	memset(number, '0', sizeof(char) * max_length);
	printf("0\t");
	while (increment(number, max_length))
	{
		print_char_arr(number, max_length);
	}

	free(number);
	puts("\n");
	puts("***************************************END**************************************************");
}

/************************************************************************/
/* 给字符串数组进行+1操作
/* 如果+1之后超出当前的最大位数，那么，返回true，否则返回false
/************************************************************************/
bool increment(char* arr, int size)
{
	int bit_overflow = false;
	for (int i = size - 1; i >= 0; --i)
	{
		int cur_pos = arr[i] - '0';
		//最低位+1，如果上一次的位overflow了，也需要在当前位+1
		if (i == size - 1 || bit_overflow)
		{
			++cur_pos;
		}


		if (cur_pos >= 10)
		{
			//最高位已经满了
			if (i == 0)
			{
				return false;
			}

			bit_overflow = true;
			cur_pos -= 10;
			arr[i] = '0' + cur_pos;
		}
		else
		{
			arr[i] = '0' + cur_pos;
			bit_overflow = false;
		}
	}

	return true;
}


/************************************************************************/
/* 打印number数组，从最高位不是0开始打印
/************************************************************************/
void print_char_arr(char* arr, int size)
{
	//寻找第一个不是0的最高位位置
	int pos = size - 1;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] != '0')
		{
			pos = i;
			break;
		}
	}

	for (int i = pos; i < size;++i)
	{
		printf("%c", arr[i]);
	}
	printf("\t");
}

/************************************************************************/
/* 开始算法
/************************************************************************/
void start_print()
{
	print_1_to_max(1);
	print_1_to_max(3);
}