#pragma once
#include "common.h"
/************************************************************************/
/* ���һ�����������������������飬�ܹ������½ⷨ��
/* 1 �������
/* 2 ���η����㷨�����������ἰ
/* 3 ��̬�滮��
/************************************************************************/

/************************************************************************/
/* ��̬�滮�㷨
/* ��̬�滮�Ƶ���ʽΪ��max_sub(0...j + 1) = max(max_sub(0...j), max_sub(0...j + 1))
/* ˼·��
/* 0-j + 1�������������Ϊ0-j��������������0-j + 1����������飬����0-j����ʼ����
/* ɨ��ÿһ������
/* ������������֮ǰ��sum��sum����ô������sub_right�����򣬼�������ɨ��
/* ������������֮ǰ��sumС�ڵ���sum�����Ǵ���0����ô��������ɨ��ʲô��������
/* ������������֮ǰ��sumС��0����ôsub_leftΪ����Ϊ���������һ�������¿�ʼ���㡣
/************************************************************************/
void find_max_sub_arr_dp(int* arr, int size, int& low, int& high, int& sum);


/************************************************************************/
/* ��ʼ�㷨
/************************************************************************/
void start_find_max_sub();