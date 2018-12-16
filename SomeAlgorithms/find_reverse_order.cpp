#include "find_reverse_order.h"
/************************************************************************/
/* �������������е�����Եĸ��������ǰ������ִ��ں�������֣���ô�������һ������ԣ���
/* (7,5,6,4)�������Ϊ: (7,5),(7,6),(7,4),(5,4),(6,4)����ô���Ϊ5
/************************************************************************/

/************************************************************************/
/* ����˼·��
/* ��������еȷ֣�ֱ���ֵ�����Ϊ1���Ƚ������ȷ������Ƿ�Ϊ����ԣ��Ƚ���֮���ڽ�����Ϊ1������
/* �������·��������У���������ֱ��ظ����㣩��Ȼ������Ƚϣ����ν��еݹ���ã������ڹ鲢����
/* ע��:  �������һ�����Σ�����leetcode����ģ���һ������important reverse order������Ϊ
/* ǰ��������ں������*2����Ϊimportant reverse order������������ܴ��ڸ�������������Ľⷨ
/* ��Ҫ�޸ġ��������£����ⷨ�����棩
/* https://leetcode.com/problems/reverse-pairs/submissions/
/************************************************************************/
void find_reverse_order_in_arr(int* arr, int size)
{
	if (NULL == arr || 0 >= size)
	{
		return;
	}

	int* copy = (int*)malloc(sizeof(int) * size);
	memset(copy, 0, sizeof(int) * size);

	for (int i = 0; i < size; ++i)
	{
		copy[i] = arr[i];
	}

	int count = reverse_order_internal(arr, copy, 0, size - 1);
	printf("The sum of reverse order in this arr:%d\n", count);
	free(copy);
}

/************************************************************************/
/* �ڲ��ݹ����ͳ��
/************************************************************************/
int reverse_order_internal(int* arr, int* copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = arr[start];
		return 0;
	}

	int mid = (start + end) >> 1;
	int left = reverse_order_internal(arr, copy, start, mid);
	int right = reverse_order_internal(arr, copy, mid + 1, end);

	int l_index = mid;
	int r_index = end;
	int copy_index = end;

	int count = 0;
	//�����ߵ������ұߵ�������ô˵����������ԣ����������鶼���ź���ģ���ˣ���ʱ����Եĸ���Ϊ
	//�ұ߱ȵ�ǰ��С�����ĸ������������Ϊ(2,4,6),�ұ�Ϊ(3,4,5)����ô����6��5�����Դ�ʱ����Ը���Ϊ3����Ϊ3,4����5С
	while (l_index >= start && r_index >= mid + 1)
	{
		if (arr[l_index] > arr[r_index])
		{

			copy[copy_index--] = arr[l_index--];
			count += (r_index - mid);
		}
		//�����������
		else
		{
			copy[copy_index--] = arr[r_index--];
		}
	}

	while (l_index >= start)
	{
		copy[copy_index--] = arr[l_index--];
	}
	while (r_index >= mid + 1)
	{
		copy[copy_index--] = arr[r_index--];
	}

	for (int i = start; i <= end; ++i)
	{
		arr[i] = copy[i];
	}

	return count + left + right;
}



/************************************************************************/
/* ����˼·��
/* �������һ�����Σ�����leetcode����ģ���һ������important reverse order������Ϊ
/* ǰ��������ں������*2����Ϊimportant reverse order������һ������������Եĸ�����
/* ��Ҫע����ǣ�������ܻᵼ��32λ��int overflow�������Ҫ������������д���
/* �������£�
/* https://leetcode.com/problems/reverse-pairs/submissions/
/************************************************************************/
void find_important_reverse_order_in_arr(int* arr, int size)
{
	if (NULL == arr || 0 >= size)
	{
		return;
	}

	int* copy = (int*)malloc(sizeof(int) * size);
	memset(copy, 0, sizeof(int) * size);

	for (int i = 0; i < size; ++i)
	{
		copy[i] = arr[i];
	}

	int count = important_reverse_order_internal(arr, copy, 0, size - 1);
	printf("The sum of IMPORTANT reverse order in this arr:%d\n", count);
	free(copy);
}

/************************************************************************/
/* �ڲ��ݹ����ͳ��
/************************************************************************/
int important_reverse_order_internal(int* arr, int* copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = arr[start];
		return 0;
	}

	int mid = (start + end) >> 1;
	int left_count = important_reverse_order_internal(arr, copy, start, mid);
	int right_count = important_reverse_order_internal(arr, copy, mid + 1, end);

	int l_index = mid;
	int r_index = end;
	int copy_index = end;

	int count = 0;
	//�����ߵ������ұߵ�������ô˵����������ԣ����������鶼���ź���ģ���ˣ���ʱ����Եĸ���Ϊ
	//�ұ߱ȵ�ǰ��С�����ĸ������������Ϊ(2,4,6),�ұ�Ϊ(3,4,5)����ô����6��5�����Դ�ʱ����Ը���Ϊ3����Ϊ3,4����5С
	int left = l_index;
	int right = r_index;
	//ͳ�����������ĸ���
	while (left >= start && right >= mid + 1)
	{
		//����leetcode�����п��ܻ�Խ����������������ǿתΪ64λ��
		if ((int64_t)(arr[left]) > (int64_t)(arr[right]) * 2)
		{
			count += (right - mid);
			--left;
		}
		else
		{
			--right;
		}
	}


	//����˳���ź�
	while (l_index >= start && r_index >= mid + 1)
	{
		if (arr[l_index] > arr[r_index])
		{

			copy[copy_index--] = arr[l_index--];
		}
		else
		{
			copy[copy_index--] = arr[r_index--];
		}
	}

	while (l_index >= start)
	{
		copy[copy_index--] = arr[l_index--];
	}
	while (r_index >= mid + 1)
	{
		copy[copy_index--] = arr[r_index--];
	}

	for (int i = start; i <= end; ++i)
	{
		arr[i] = copy[i];
	}

	return count + left_count + right_count;
}


/************************************************************************/
/* ��ʼ�㷨
/************************************************************************/
void start_print_reverse_order()
{
	const int size = 4;
	int arr[size] = { 7, 5, 6, 4 };
	find_important_reverse_order_in_arr(arr, size);

	const int size1 = 5;
	int arr1[size1] = { 1, 3, 2, 3, 1 };
	find_important_reverse_order_in_arr(arr1, size1);

	const int size2 = 5;
	int arr2[size2] = { 2, 4, 3, 5, 1 };
	find_important_reverse_order_in_arr(arr2, size2);

	const int size3 = 2;
	int arr3[size3] = { -5, -5 };
	find_important_reverse_order_in_arr(arr3, size3);


	const int size4 = 6;
	int arr4[size4] = { 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647 };
	find_important_reverse_order_in_arr(arr4, size4);
}