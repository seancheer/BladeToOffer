#pragma once
#include "utils.h"
#include "common.h"
/************************************************************************/
/* ����һ���ַ�������ӡ���ַ���������ϣ��磺abc�����Ϊ��a,b,c,ab,ac,bc,abc����Ҫע�����
/* ab��baΪͬһ�����
/************************************************************************/

void print_all_combination_of_string(const char* str);

void print_combination_string_internal(char* str, char* p_begin, int cur_len, int str_len, std::vector<char>& vec);

void print_combination(std::vector<char>& vec);

/************************************************************************/
/* ʹ��λ���������������
/************************************************************************/
void print_all_combination_in_bit(const char* str);


/************************************************************************/
/* �㷨���
/************************************************************************/
void start_print_all_combination();