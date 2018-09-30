#include "count_how_many_1_in_integer.h"


/************************************************************************/
/* ����һ�����Ķ��������ж��ٸ�1
/* ��Ҫע��ĵط����п��ܻ��Ǹ���
/* ����������������Ӧֵ����һλ��Ȼ���1���������㣬Ȼ���ж��Ƿ�Ϊ1����1,����
/* ��������Ǹ����Ļ����÷����ͻ������ѭ������Ϊ�����ڷ���λ����Ჹ1

/* ��Ч�Ľ���������ж��ٸ�1��ѭ�����ٴΣ���
/* 1 ����Ӧ��value - 1��Ȼ������value������������㣬
/* 2 value���ұߵ�1�����Ҷ����Ϊ0
/* 3 ѭ������1-2����ֱ��value��Ϊ1
/* �÷��������������͸���
/************************************************************************/
int count_how_many_1_in_integer(int value)
{
	int count = 0;
	bool is_negative = false;

	if (value < 0)
	{
		value = 0 - value;
		is_negative = true;
	}

	while (value)
	{
		++count;
		value = value & (value - 1);
	}

	return is_negative ? count + 1 : count;
}


/************************************************************************/
/* �㷨�����
/************************************************************************/
void start_count()
{
	int value = count_how_many_1_in_integer(1);
	printf("Should be 1! value:%d\n", value);

	value = count_how_many_1_in_integer(2);
	printf("Should be 1! value:%d\n", value);

	value = count_how_many_1_in_integer(3);
	printf("Should be 2! value:%d\n", value);

	value = count_how_many_1_in_integer(-1);
	printf("Should be 2! value:%d\n", value);

	value = count_how_many_1_in_integer(0xFFFF);
	printf("Should be 16! value:%d\n", value);

	value = count_how_many_1_in_integer(0x80000);
	printf("Should be 1! value:%d\n", value);

}