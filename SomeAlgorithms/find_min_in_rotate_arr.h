#pragma once
#include "common.h"


/************************************************************************/
/* �ڵ�������ת�����в�����С����
/* ��ת����ָ��������Ŀ�ͷһֱ�������ĳ��λ�ã�����һ�η�Χ�ڵ������ƶ���
/* ����ĩβ�������һ����ת����
/* ������Сֵ������O(n)��ʱ���ҵ������Ǹ�������һ����������ת���ݣ���˿��Բ���������
/* ���ַ��ķ�ʽ��O(nlogn)��ʱ�����ҵ���Сֵ.
/************************************************************************/

int find_min_in_rotate_arr(int arr[], unsigned int size);

int find_min_value_in_order(int arr[], unsigned int size);

void start_find_min_value();

void do_start_find_min_value(int arr[], int size, int expected);