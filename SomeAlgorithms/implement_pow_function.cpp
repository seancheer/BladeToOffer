#include "implement_pow_function.h"
#include "utils.h"

/************************************************************************/
/* 实现pow函数（本题不需要考虑大数问题）：
/* 需要注意以下事情：
/* 1 底数为0，指数为0和-1的情况
/* 2 double互相比较的问题
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
/* 递归执行的地方
/* 本方法不不处理指数为负数的情况，由调用者来识别处理
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
/* 开始算法
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