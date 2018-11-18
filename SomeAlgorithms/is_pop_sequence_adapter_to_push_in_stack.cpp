#include "is_pop_sequence_adapter_to_push_in_stack.h"

/************************************************************************/
/* ����ѹ��ջ��ֵ������ȣ��жϽ�ջ�����Ƿ�ͳ�ջ����ƥ�䣬��һ�������Ƿ�Ϊһ��ѹջ���е�
/* ��ջ���У�����5,4,3,2,1����1,2,3,4,5��һ����ջ����
/* ˼·��
/* ׼��һ��stack������arr_push����ѹջ��ͬʱ����arr_pop��ѹջ�󣬷���ջ��Ԫ�غ�arr_pop��
/* ��ǰλ��Ԫ����ͬ����ô��stack����pop��һֱpop��stackΪ�ջ���ջ��Ԫ�غ�arr_pop�ĵ�ǰλ��
/* Ԫ�ز����Ϊֹ����arr_pushѹ��֮�󣬷���stack��Ϊ�գ���ô����������arr_pop����pop������ 
/* WARNNING: ���ϵ�P136�ı���˼ά��ʽ���Ӽ�һЩ�����Բο���
/************************************************************************/
bool is_sequence_adapt(int arr_push[], int push_size, int arr_pop[], int pop_size)
{
	if (NULL == arr_push || push_size <= 0 || NULL == arr_pop || pop_size <= 0)
	{
		puts("Invalid parameter!");
		return false;
	}

	if (push_size != pop_size)
	{
		return false;
	}

	stack<int> s;
	int pos_to_pop = 0;
	for (int i = 0; i < push_size; ++i)
	{
		s.push(arr_push[i]);
		int value = s.top();
		//һֱ��pop arr���м�⣬ֻҪջ��Ԫ�غ�pop�����еĵ�ǰλ����ȣ���ô��һֱpop
		while (pos_to_pop < pop_size && value == arr_pop[pos_to_pop])
		{
			s.pop();
			++pos_to_pop;
			if (s.empty())
			{
				break;
			}

			value = s.top();
		}
	}

	//��ǰ�в�������ô��Ҫһֱ���ж�s����pop
	while (!s.empty() && pos_to_pop < pop_size)
	{
		int value = s.top();
		if (value != arr_pop[pos_to_pop])
		{
			return false;
		}
		++pos_to_pop;
		s.pop();
	}

	return true;
}


/************************************************************************/
/* ��ʼ�㷨
/************************************************************************/
void start_pop_and_push_sequence_in_stack()
{
	const int size1 = 5;
	int push_arr1[] = { 1,2,3,4,5 };
	int pop_arr1[] = { 1,2,3,4,5 };
	bool result = is_sequence_adapt(push_arr1, size1, pop_arr1, size1);
	BOOL_TO_STRING(result);


	const int size2 = 5;
	int push_arr2[] = { 1,2,3,4,5 };
	int pop_arr2[] = { 4,3,5,1,2 };
	result = is_sequence_adapt(push_arr2, size2, pop_arr2, size2);
	BOOL_TO_STRING(result);

	const int size3 = 5;
	int push_arr3[] = { 1,2,3,4,5 };
	int pop_arr3[] = { 4,3,5,2,1 };
	result = is_sequence_adapt(push_arr3, size3, pop_arr3, size3);
	BOOL_TO_STRING(result);
}