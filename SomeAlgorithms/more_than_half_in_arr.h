#pragma once
#include  "common.h"
#include "utils.h"

/************************************************************************/
/* Ѱ�������г��ִ����������鳤��һ�������,ע�⣬����������з�������������ֻ��һ��
/* ��ֱ�۵Ľⷨ���������������Ȼ��ȡ�������λ������λ��һ�������յĽ��������
/* ��ʱ�临�Ӷ�ΪO(nlogn)��������ﲻ��ȡ
/************************************************************************/

/************************************************************************/
/* �ⷨһ��ͨ�����������������ÿ��partion��pivot������λ���������������λ����λ�ã�
/* ��ô���ֵ�������յĽ�����������������λ����ߣ���ô���ұ߽���partition������
/* ���ұ߽���partition��ֱ���ҵ����յĽ��Ϊֹ
/************************************************************************/
int solution_inspired_by_qsort(int *arr, int size);

int more_than_half_partition(int *arr, int low, int high);



/************************************************************************/
/* �ⷨ2��ͨ��һ�ε����ķ�ʽ�Ϳ��Բ��ҵ����ִ�������һ�������
/* ��¼����ֵ�����ֳ��ֵĴ���times��ĳ������number������һ�����ֺ�number���ʱ��
/* times + 1���������ȣ���1����Ϊ0��ʱ�򣬽�times����Ϊ0��number��Ϊ��һ�����֣�
/* ��ô��������Ϻ�number����¼�����ּ�Ϊ����һ�������
/************************************************************************/
int solution_by_times_of_num(int* arr, int size);


/************************************************************************/
/* �㷨���
/************************************************************************/
void start_more_than_half();