#pragma once
#include "utils.h"
#include "common.h"
/************************************************************************/
/* 输入一个字符串，打印该字符串所有组合，如：abc的组合为：a,b,c,ab,ac,bc,abc，需要注意的是
/* ab和ba为同一个组合
/************************************************************************/

void print_all_combination_of_string(const char* str);

void print_combination_string_internal(char* str, char* p_begin, int cur_len, int str_len, std::vector<char>& vec);

void print_combination(std::vector<char>& vec);

/************************************************************************/
/* 使用位运算计算出所有组合
/************************************************************************/
void print_all_combination_in_bit(const char* str);


/************************************************************************/
/* 算法入口
/************************************************************************/
void start_print_all_combination();