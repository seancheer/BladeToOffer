#include "count_1_in_arr.h"
/************************************************************************/
/* �ҵ�1��һ�����飨������ʼ������1-n���г��ֵĴ���������1��12�У�1�ܹ�����5�Σ�
/* 1��10,11,12���������ܹ���5��
/************************************************************************/


/************************************************************************/
/* ��Ч�ʽⷨ��˼·��
/* 1 ���ڸ�λ����1�ĸ���Ϊ��ȥ��λ�ĸ�λֵ�������λ���ڵ���1����ô��+1
/* 2 ���ڸ�λ����1�ĸ���Ϊ����λ��ֵ * ��ǰ��base���������������ǰλ��ֵ����1��
/* ��ôֱ��+base�������ǰλ����1����ô+�ϵ�ǰλ���������������ʲôҲ������
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
		//���ֵ�ǰΪ����1����ôֱ�ӼӸ�base
		if (remainder > 1)
		{
			count = count + base;
		}
		//����1������£���Ҫ��ʣ�����+1
		else if(remainder == 1)
		{
			count = count + number % base + 1;
		}
		//����ʲôҲ��������Ϊ��ǰλΪ0����ô��ʱ����һλ����м���
		++index;
	}

	return count;
}


/************************************************************************/
/* ʹ�ô�ͳ�ķ�ʽ�����м��㣬����ÿһ�����ֵ�1�ĸ�������ͳ��
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