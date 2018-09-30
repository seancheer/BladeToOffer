#include "find_min_in_rotate_arr.h"
/************************************************************************/
/* �ڵ�������ת�����в�����С����
/* ��ת����ָ��������Ŀ�ͷһֱ�������ĳ��λ�ã�����һ�η�Χ�ڵ������ƶ���
/* ����ĩβ�������һ����ת����
/* ������Сֵ������O(n)��ʱ���ҵ������Ǹ�������һ����������ת���ݣ���˿��Բ���������
/* ���ַ��ķ�ʽ��O(nlogn)��ʱ�����ҵ���Сֵ.
/************************************************************************/


/************************************************************************/
/* ���˼·�����ö��ַ����ҡ�ע�⴦��һ�������10111��11101
/************************************************************************/
int find_min_in_rotate_arr(int arr[], unsigned int size)
{
	if (NULL == arr || size == 0)
	{
		puts("Invalid parameter!\n");
		return -1;
	}


	int left = 0;
	int right = size - 1;
	int min_value = arr[0];

	while ((right - left) > 1)
	{
		int mid = (left + right) >> 1;

		//��ʱ�Ѿ��ǵ�������
		if (arr[left] < arr[mid] && arr[mid] < arr[right])
		{
			return arr[left];
		}
		
		if (arr[left] == arr[right] && arr[left] == arr[mid])
		{
			return find_min_value_in_order(arr, size);
		}

		if (arr[left] <= arr[mid])
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}

	return arr[left] < arr[right] ? arr[left] : arr[right];
}


/************************************************************************/
/* ˳���arr�в��ҵ���С��value
/************************************************************************/
int find_min_value_in_order(int arr[], unsigned int size)
{
	int min_value = arr[0];
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] < min_value)
		{
			min_value = arr[i];
		}
	}

	return min_value;
}

/************************************************************************/
/* �㷨�����
/************************************************************************/
void start_find_min_value()
{
	int arr[] = { 2,1 };
	do_start_find_min_value(arr, 2, 1);
	int arr1[] = { 1,2 };
	do_start_find_min_value(arr1, 2, 1);

	int arr2[] = { 1,2,3 };
	do_start_find_min_value(arr2, 3, 1);

	int arr3[] = { 2,3,1 };
	do_start_find_min_value(arr3, 3, 1);

	int arr4[] = { 3,1,2 };
	do_start_find_min_value(arr4, 3, 1);

	int arr5[] = { 1,2,3,4};
	do_start_find_min_value(arr5, 4, 1);

	int arr6[] = { 2,3,4,1 };
	do_start_find_min_value(arr6, 4, 1);

	int arr7[] = { 3,4,1,2 };
	do_start_find_min_value(arr7, 4, 1);
}

void do_start_find_min_value(int arr[], int size, int expected)
{
	int value = find_min_in_rotate_arr(arr, size);
	printf("value should be %d! value:%d\n", expected, value);
}