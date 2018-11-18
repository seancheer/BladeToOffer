#include "is_pop_sequence_adapter_to_push_in_stack.h"

/************************************************************************/
/* 假设压入栈的值都不相等，判断进栈序列是否和出栈序列匹配，即一个序列是否为一个压栈序列的
/* 出栈序列，比如5,4,3,2,1就是1,2,3,4,5的一个出栈序列
/* 思路：
/* 准备一个stack，根据arr_push进行压栈，同时对照arr_pop，压栈后，发现栈顶元素和arr_pop的
/* 当前位置元素相同，那么对stack进行pop，一直pop到stack为空或者栈顶元素和arr_pop的当前位置
/* 元素不相等为止；当arr_push压完之后，发现stack不为空，那么继续对照着arr_pop进行pop操作。 
/* WARNNING: 书上的P136的编码思维方式更加简单一些，可以参考下
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
		//一直对pop arr进行检测，只要栈顶元素和pop数组中的当前位置相等，那么就一直pop
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

	//当前有残留，那么需要一直进行对s进行pop
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
/* 开始算法
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