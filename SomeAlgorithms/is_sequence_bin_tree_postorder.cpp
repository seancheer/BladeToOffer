#include "is_sequence_bin_tree_postorder.h"

/************************************************************************/
/* ��һ�����У�ÿ��ֵ������ͬ���жϸ������Ƿ�Ϊ�������ĺ��������
/* ˼·�����ȸ��ݺ���������Ե�֪�ö����������һ���ڵ��Ǹ��ڵ㣻Ȼ���ڸ������в���
/* ��һ���ȸ��ڵ���ֵ����ô���Ǹ�ֵ֮�����е�ֵ��Ӧ�ñȸ��ڵ����Ϊ���Ǹ�ֵ��ʼ
/* �����ֵ�Ͷ�����������������������������ֵ�ȸ��ڵ�С����ô����false��Ȼ�������
/* �����������������еݹ鴦��ֱ��ֻʣ����ֵΪֹ��
/************************************************************************/
bool is_arr_bin_tree_postorder(int arr[], int size)
{
	if (NULL == arr || size <= 0)
	{
		puts("Invalid parameter!");
		return false;
	}

	return is_arr_postorder_internal(arr, 0, size - 1);
}

/************************************************************************/
/* �ݹ�����ж�                                                                     */
/************************************************************************/
bool is_arr_postorder_internal(int arr[], int start, int end)
{
	if (end - start <= 1)
	{
		return true;
	}

	int root = arr[end];
	int right = 0;
	for (right = 0; right < end && arr[right] < root; ++right)
	{
		//do nothing
	}
	
	//�ұ�ȫ���ҽڵ���߼����ҽڵ�Ҳ����ڵ�
	if (right < end)
	{
		//�ж��������Ƿ��б�rootС��
		for (int i = right; i < end; ++i)
		{
			if (arr[i] < root)
			{
				return false;
			}
		}

		if (!is_arr_postorder_internal(arr, start, right - 1) 
			|| !is_arr_postorder_internal(arr, right, end - 1))
		{
			return false;
		}

		return true;
	}
	//�ұ�ȫ����ڵ�
	else
	{
		return is_arr_postorder_internal(arr, start, end - 1);
	}
}

/************************************************************************/
/* ��ʼ�㷨
/************************************************************************/
void start_is_postorder()
{
	const int size1 = 4;
	int arr1[] = { 7,4,6,5 };
	bool result = is_arr_bin_tree_postorder(arr1, size1);
	BOOL_TO_STRING(result);

	const int size2 = 7;
	int arr2[] = { 5,7,8,9,11,10,8 };
	result = is_arr_bin_tree_postorder(arr2, size2);
	BOOL_TO_STRING(result);

	const int size3 = 1;
	int arr3[] = { 5};
	result = is_arr_bin_tree_postorder(arr3, size3);
	BOOL_TO_STRING(result);
}