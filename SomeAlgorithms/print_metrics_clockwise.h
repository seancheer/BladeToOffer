#pragma once
#include "common.h"
#include "utils.h"
#define ARR_INDEX(arr,x,y) (arr[(x) * col + (y)])
/************************************************************************/
/* ˳ʱ���ӡ����
/************************************************************************/
void print_metrics_clockwise(int* arr, int row, int col);

void print_metrics_clockwise_in_book(int* arr, int row, int col);

/************************************************************************/
/* �㷨���
/************************************************************************/
void start_print_metrics();