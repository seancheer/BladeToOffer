#pragma once
#include "common.h"
/************************************************************************/
/* 给定一个数n，查找从1到n中1出现的次数，比如1到12中，1总共出现5次，
/* 1，10,11,12，加起来总共有5次
/************************************************************************/


int count_1_in_number(int number);

/************************************************************************/
/* 使用传统的方式，进行计算，即对每一个数字的1的个数进行统计
/************************************************************************/
int count_1_in_number_brutal(int number);

void start_count_1();