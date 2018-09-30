#pragma once
#include "common.h"


/************************************************************************/
/* 在递增的旋转数组中查找最小的数
/* 旋转数组指：从数组的开头一直到任意的某个位置，将这一段范围内的数字移动到
/* 数组末尾，这就是一个旋转数组
/* 查找最小值可以用O(n)的时间找到，但是该数组是一个递增的旋转数据，因此可以采用类似于
/* 二分法的方式在O(nlogn)的时间内找到最小值.
/************************************************************************/

int find_min_in_rotate_arr(int arr[], unsigned int size);

int find_min_value_in_order(int arr[], unsigned int size);

void start_find_min_value();

void do_start_find_min_value(int arr[], int size, int expected);