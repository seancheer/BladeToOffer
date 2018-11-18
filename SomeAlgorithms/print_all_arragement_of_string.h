#pragma once
#include "utils.h"
#include "common.h"
/************************************************************************/
/* 输入一个字符串，打印该字符串所有排列
/************************************************************************/

/************************************************************************/
/* 以递归的方式进行打印
/************************************************************************/
void print_all_arragement_of_string(const char* str);

void print_string_internal(char* str, char* p_begin);

/************************************************************************/
/* 以迭代的方式找出所有的排列，注意：输入的字符串必须保证是有序的，
/* 如果不是有序的需要先进行排序，这里就不进行排序操作了，输入者保证有序即可
/************************************************************************/
void print_arragement_iterator_in_order(const char* str);

void print_iterator_internal(char *str);

bool print_iterator(char *str);

char* find_bigger_from_end(char* str, char* target);

void reverse_str(char* start, char* end);

/************************************************************************/
/* 算法入口
/************************************************************************/
void start_print_all_arragement();