#include "print_1_to_n.h"


/************************************************************************/
/* ��ӡ��1��nλ����ɳɵ����ֵ
/* ע��������⼴��
/* 1 ��ֱ�۵Ľⷨ��ʹ���ַ���ģ��+1����
/* 2 �ڶ��ֽⷨ����0��ӡ�����λ����ʵ���Ͼ���0-9��������϶��ѣ�ֻ������ӡ��ʱ�򲻴�ӡ
/* ���λ��0����
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
/* ���ַ����������+1����
/* ���+1֮�󳬳���ǰ�����λ������ô������true�����򷵻�false
/************************************************************************/
bool increment(char* arr, int size)
{
	int bit_overflow = false;
	for (int i = size - 1; i >= 0; --i)
	{
		int cur_pos = arr[i] - '0';
		//���λ+1�������һ�ε�λoverflow�ˣ�Ҳ��Ҫ�ڵ�ǰλ+1
		if (i == size - 1 || bit_overflow)
		{
			++cur_pos;
		}


		if (cur_pos >= 10)
		{
			//���λ�Ѿ�����
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
/* ��ӡnumber���飬�����λ����0��ʼ��ӡ
/************************************************************************/
void print_char_arr(char* arr, int size)
{
	//Ѱ�ҵ�һ������0�����λλ��
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
/* ��ʼ�㷨
/************************************************************************/
void start_print()
{
	print_1_to_max(1);
	print_1_to_max(3);
}