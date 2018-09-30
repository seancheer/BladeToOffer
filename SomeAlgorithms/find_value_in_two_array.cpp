#include "find_value_in_two_array.h"
/************************************************************************/
/* ��Ŀ���ܣ���ָoffer p38����
/* �ڶ�ά�����в��Ҷ�Ӧ�����֣�
/* ��ά�����ʽΪ����������������������������һ�������Ƿ����
/************************************************************************/


/************************************************************************/
/* �㷨�����                                                                     */
/************************************************************************/
void start_find_value()
{
	int arr[4][4] = {
		1,2,8,9,
		2,4,9,12,
		4,7,10,13,
		6,8,11,15
	};

	bool result = find_value_in_array(arr, 15, 4);
	if (result)
	{
		printf("find it!\n");
	}

	result = find_value_in_array(arr, 100, 4);
	if (!result)
	{
		printf("You should not find it!\n");
	}


}


/************************************************************************/
/* �ڶ�ά�����в�ѯָ�������ݣ�true��ʾ�ɹ���false��ʾû��
/************************************************************************/
bool find_value_in_array(int arr[][4], int target, int x_size)
{
	int x = 0;
	int y = 3;

	while (x < x_size && y >= 0)
	{
		int cur_value = arr[x][y];
		if (cur_value == target)
		{
			return true;
		}

		//������
		if (target > cur_value && x < x_size - 1)
		{
			++x;
			continue;
		}
		//������
		else if (target < cur_value && y > 0)
		{
			--y;
			continue;
		}

		return false;
	}

	return false;
}