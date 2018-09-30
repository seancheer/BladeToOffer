#include "print_1_to_n.h"


/************************************************************************/
/* 打印从1到n位数组成成的最大值
/* 注意大数问题即可
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

	char start = '0';
	int cur_bit = 0;
	char* number = (char*)malloc(sizeof(char) * max_length);
	if (NULL == number)
	{
		puts("Malloc failed!\n");
		exit(-1);
	}

	memset(number, '0', sizeof(char) * max_length);

	while (cur_bit < max_length)
	{
		print_char_arr(number, cur_bit);
		number[0] = number[0] + 1;

		int i = 0;
		while (i++ <= cur_bit)
		{
			if (number[i] == '9' && i + 1 < max_length)
			{
				number[i] = '0';
				number[i + 1] = number[i + 1] + 1;
				continue;
			}

			//final number
			if (number[i] == '9' && i + 1 == max_length)
			{
				print_char_arr(number, cur_bit);
				break;
			}

			break;
		}

		if (cur_bit < max_length - 1 && number[cur_bit + 1] != '0')
		{
			++cur_bit;
		}

		//此时number肯定已经改变
		if (origin_first == '9')
		{
			print_char_arr(number, cur_bit);
		}
	}

	puts("\n");
	puts("***************************************END**************************************************");
}


/************************************************************************/
/* 根据特定的size打印arr
/************************************************************************/
void print_char_arr(char* arr, int size)
{
	for (int i = size - 1; i >= 0;--i)
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