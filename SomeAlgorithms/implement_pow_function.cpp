#include "implement_pow_function.h"
#include "utils.h"

/************************************************************************/
/* ʵ��pow���������ⲻ��Ҫ���Ǵ������⣩��
/* ��Ҫע���������飺
/* 1 ����Ϊ0��ָ��Ϊ0��-1�����
/* 2 double����Ƚϵ�����
/************************************************************************/
double my_own_pow(double base_num, int exponent)
{
	if (equals_double(base_num, 0) && exponent < 0)
	{
		puts("Invalid argument!\n");
		exit(-1);
	}

	if (base_num == 0)
	{
		return 0;
	}


	bool is_negative = false;
	if (exponent < 0)
	{
		exponent = 0 - exponent;
		is_negative = true;
	}

	double r = my_own_pow_internal(base_num, exponent);

	if (is_negative)
	{
		r = 1.0 / r;
	}

	return r;
}


/************************************************************************/
/* �ݹ�ִ�еĵط�
/* ��������������ָ��Ϊ������������ɵ�������ʶ����
/************************************************************************/
double my_own_pow_internal(double base_num, int exponent)
{
	if (exponent == 0)
	{
		return 1;
	}

	if (exponent == 1)
	{
		return base_num;
	}


	double r = my_own_pow(base_num, exponent >> 1);
	r = r * r;

	if (exponent % 2 != 0)
	{
		r = r * base_num;
	}

	return r;
}

/************************************************************************/
/* ��ʼ�㷨
/************************************************************************/
void start_pow()
{
	double base_num = 2.0;
	int exponent = 10;

	double r = my_own_pow(base_num, exponent);
	printf("expected:%lf actual:%lf \n", 1024.0,r);

	base_num = 10.0;
	exponent = 10;
	r = my_own_pow(base_num, exponent);
	printf("expected:%lf actual:%lf \n", pow(base_num, exponent), r);

	base_num = -11.0;
	exponent = 4;
	r = my_own_pow(base_num, exponent);
	printf("expected:%lf actual:%lf \n", pow(base_num, exponent), r);

	base_num = 11.0;
	exponent = -4;
	r = my_own_pow(base_num, exponent);
	printf("expected:%lf actual:%lf \n", pow(base_num, exponent), r);
}