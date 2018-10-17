#include "find_middle_node_in_linked_list.h"

#define PREVIOUS_STEP 2
#define AFTER_STEP 1
/************************************************************************/
/* 查找链表中间的节点
/* 解决思路：
/* 定义两个指针，第一个指针一次走两步，第二个指针一次走一步，当第一个指针到达末尾
/* 时，第二个指针的位置就是中间的位置
/************************************************************************/
LinkedList* find_middle_node_in_list(LinkedList* header)
{

	if (NULL == header)
	{
		return NULL;
	}

	LinkedList* previous = header;
	LinkedList* after = header;

	while (true)
	{
		previous = forward_node(previous, PREVIOUS_STEP);
		if (NULL == previous)
		{
			break;
		}

		after = forward_node(after, AFTER_STEP);
	}

	return after;
}


/************************************************************************/
/* 根据传入的step将指针往前推
/************************************************************************/
LinkedList* forward_node(LinkedList* pos, int step)
{
	for (int i = 0; i < step && NULL != pos; ++i)
	{
		pos = pos->next;
	}

	return pos;
}


void start_find_middle_node_in_list()
{
	LinkedList* header = init_linked_list(1);
	LinkedList* result = find_middle_node_in_list(header);
	//should be 1
	printf("Find middle in list: %d!\n", result->value);

	append_value(header, 2);
	append_value(header, 3);
	append_value(header, 4);
	result = find_middle_node_in_list(header);
	//shoudl be 2 or 3
	printf("Find middle in list: %d!\n", result->value);

	append_value(header, 5);
	result = find_middle_node_in_list(header);
	//shoudl be 3
	printf("Find middle in list: %d!\n", result->value);
	empty_linked_list(header);
}
