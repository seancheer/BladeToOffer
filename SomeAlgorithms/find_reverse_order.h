#pragma once
#include "common.h"
/************************************************************************/
/* �������������е�����Եĸ��������ǰ������ִ��ں�������֣���ô�������һ������ԣ���
/* (7,5,6,4)�������Ϊ: (7,5),(7,6),(7,4),(5,4),(6,4)����ô���Ϊ5
/************************************************************************/


void find_reverse_order_in_arr(int* arr, int size);

int reverse_order_internal(int* arr, int* copy, int start, int end);

void find_important_reverse_order_in_arr(int* arr, int size);

int important_reverse_order_internal(int* arr, int* copy, int start, int end);

void start_print_reverse_order();