#include "count_1_in_arr.h"
/************************************************************************/
/* 找到1在一个数组（该数组始终满足1-n）中出现的次数，比如1到12中，1总共出现5次，
/* 1，10,11,12，加起来总共有5次
/************************************************************************/


/************************************************************************/
/* 高效率解法，思路：
/* 1 对于个位，其1的个数为除去个位的高位值，如果个位大于等于1，那么再+1
/* 2 对于高位，其1的个数为更高位的值 * 当前的base，接下来，如果当前位的值大于1，
/* 那么直接+base，如果当前位等于1，那么+上当前位后面的余数，否则，什么也不做。
/************************************************************************/
int count_1_in_number(int number)
{
	if (number <= 0)
	{
		return 0;
	}

	int tmp = number;
	int index = 0;
	int count = 0;

	while (tmp > 0)
	{
 		int remainder = tmp % 10;
		tmp /= 10;

		int base = (int)pow(10.0, index);
		count += tmp * base;
		//发现当前为大于1，那么直接加个base
		if (remainder > 1)
		{
			count = count + base;
		}
		//等于1的情况下，需要给剩余的数+1
		else if(remainder == 1)
		{
			count = count + number % base + 1;
		}
		//否则，什么也不做，因为当前位为0，那么此时其下一位会进行计算
		++index;
	}

	return count;
}


/************************************************************************/
/* 使用传统的方式，进行计算，即对每一个数字的1的个数进行统计
/************************************************************************/
int count_1_in_number_brutal(int number)
{
	if (number <= 0)
	{
		return 0;
	}

	int result = 0;
	for (int i = 0; i <= number; ++i)
	{
		int num = i;
		while (num > 0)
		{
			int remainder = num % 10;
			if (remainder == 1)
			{
				++result;
			}
			num /= 10;
		}
	}

	return result;
}

void start_count_1()
{
	int number = 1;
	int result = count_1_in_number(number);
	int brutal_result = count_1_in_number_brutal(number);
	printf("number[%d] has [%d] 1s! brutal:[%d]\n", number, result, brutal_result);

	number = 10;
	result = count_1_in_number(number);
	brutal_result = count_1_in_number_brutal(number);
	printf("number[%d] has [%d] 1s! brutal:[%d]\n", number, result, brutal_result);

}