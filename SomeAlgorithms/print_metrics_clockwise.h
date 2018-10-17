#pragma once
#include "common.h"
#include "utils.h"
#define ARR_INDEX(arr,x,y) (arr[(x) * col + (y)])
/************************************************************************/
/* 顺时针打印矩阵
/************************************************************************/
void print_metrics_clockwise(int* arr, int row, int col);

void print_metrics_clockwise_in_book(int* arr, int row, int col);

/************************************************************************/
/* 算法入口
/************************************************************************/
void start_print_metrics();