#pragma once
#include "utils.h"
/************************************************************************/
/* 假设压入栈的值都不相等，判断进栈序列是否和出栈序列匹配，即一个序列是否为一个压栈序列的
/* 出栈序列，比如5,4,3,2,1就是1,2,3,4,5的一个出栈序列
/************************************************************************/

bool is_sequence_adapt(int arr_push[], int push_size, int arr_pop[], int pop_size);


void start_pop_and_push_sequence_in_stack();