#include "count_num_times_in_sorted_arr.h"

/************************************************************************/
/* ͳ�����������������г��ֵĴ���
/* ������㷨���Ǳ������飬Ȼ��ͳ��Ŀ�����ֳ��ֵĴ���������ʹ�ö��ַ��ҵ���һ����Ȼ��ǰ��������ɡ�
/* ������������һ�������ǵ�������ָ����ֱȽ϶��ʱ����Ҫ�����϶�Ĵ��������ڱȽϳ����������
/* ���Ч���������£��㷨˼·��
/*   ͨ�����ַ��ҵ���һ�γ���target��λ�ú����һ�γ���target��λ�ã�Ȼ���±�������ó����մ𰸣��÷���
/* ����Ч���ٱ�������ĸ�����
/************************************************************************/
int count_num_times(int* arr, int size, int target)
{
	if (NULL == arr || size <= 0)
	{
		puts("Invalid para!");
		return 0;
	}

	if (1 == size)
	{
		return 1;
	}

	int left = 0;
	int right = size - 1;
	int first_index = 0;
	int last_index = right;
	bool find_target = false;

	//���ַ���Ҫע��ÿ��midҪ+1��-1
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (arr[mid] > target)
		{
			right = mid - 1;
		}
		else if (arr[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			find_target = true;
			first_index = find_first_target(arr, left, mid, target, size);
			last_index = find_last_target(arr, mid, right, target, size);
			break;
		}
	}
	
	if (!find_target)
	{
		return 0;
	}

	return (last_index - first_index) + 1;
}


int find_first_target(int* arr, int start, int end, int target, int size)
{
	while (start <= end)
	{
		int mid = (start + end) >> 1;
		if (arr[mid] == target)
		{
			//�������ǰһ������target����ô˵���ҵ�λ����
			if (mid - 1 < 0 || arr[mid - 1] != target)
			{
				return mid;
			}

			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}

	return end;
}

int find_last_target(int* arr, int start, int end, int target, int size)
{
	while (start <= end)
	{
		int mid = (start + end) >> 1;
		if (mid + 1 >= size ||  arr[mid] == target)
		{
			if (arr[mid + 1] != target)
			{
				return mid;
			}

			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	return start;
}


/************************************************************************/
/* ��ʼ�㷨
/************************************************************************/
void start_count_num_times()
{
	const int size = 5;
	int arr[size] = { 2,3,3,3,4};
	int target = 3;
	int result = count_num_times(arr, size, target);
	printf("count %d in arr times:%d!\n", target, result);

}