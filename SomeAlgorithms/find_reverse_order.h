#pragma once
#include "common.h"
/************************************************************************/
/* 查找数组中所有的逆序对的个数，如果前面的数字大于后面的数字，那么可以组成一个逆序对，如
/* (7,5,6,4)的逆序对为: (7,5),(7,6),(7,4),(5,4),(6,4)，那么结果为5
/************************************************************************/


void find_reverse_order_in_arr(int* arr, int size);

int reverse_order_internal(int* arr, int* copy, int start, int end);

void find_important_reverse_order_in_arr(int* arr, int size);

int important_reverse_order_internal(int* arr, int* copy, int start, int end);

void start_print_reverse_order();