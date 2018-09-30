#include "count_how_many_1_in_integer.h"


/************************************************************************/
/* 计算一个数的二进制中有多少个1
/* 需要注意的地方：有可能会是负数
/* 经典解决方案：将对应值右移一位，然后和1进行与运算，然后判断是否为1，是1,计算
/* 但是如果是负数的话，该方法就会出现死循环，因为负数在符号位后面会补1

/* 高效的解决方案（有多少个1就循环多少次）：
/* 1 给对应的value - 1，然后在与value本身进行与运算，
/* 2 value最右边的1到最右都会变为0
/* 3 循环进行1-2步，直到value变为1
/* 该方法适用于正数和负数
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
/* 算法的入口
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