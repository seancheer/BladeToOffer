#include "utils.h"
const int DOUBLE_THRESHOLD = 0.000001;

void swap(int* left, int* right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}

/**
/* double数值的比较运算，由于计算机表示double有误差，所以需要这么做
*/
bool equals_double(double left, double right)
{
	double value = left - right;

	if (value < 0)
	{
		value = 0 - value;
	}

	return value <= DOUBLE_THRESHOLD;
}