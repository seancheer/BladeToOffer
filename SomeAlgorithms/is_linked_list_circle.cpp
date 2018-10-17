#include "is_linked_list_circle.h"
#include "find_middle_node_in_linked_list.h"
#define PREVIOUS_STEP 2
#define AFTER_STEP 1
/************************************************************************/
/* 给定一个头结点，判断链表是不是环形，即该链表可能头尾相接，让你判断是否为环形
/* 解决思路：
/* 指定两个指针，第一个每次前进2步，第二个每次前进1步，除却开始，如果两个节点
/* 最终相遇，那么，说明该链表是环状的
/************************************************************************/

bool is_list_circle(LinkedList* header)
{
	if (NULL == header)
	{
		return false;
	}

	LinkedList* previous = header;
	LinkedList* after = header;

	while (true)
	{
		previous = forward_node(previous, PREVIOUS_STEP);
		if (NULL == previous)
		{
			return false;	 
		}

		after = forward_node(after, AFTER_STEP);
		if (after == previous)
		{
			return true;
		}
	}
}

/************************************************************************/
/* 开始算法
/* 开始判断一个链表
/************************************************************************/
void start_tell_list_is_circle()
{
	LinkedList* header = init_linked_list(1);
	header->next = header;
	bool result = is_list_circle(header);
	BOOL_TO_STRING(result);
	//释放链表的方法目前仅支持单向链表，双向链表需要支持下。
	empty_linked_list_with_tail(header,header);

	header = init_linked_list(1);
	result = is_list_circle(header);
	BOOL_TO_STRING(result);
	empty_linked_list_with_tail(header,header);

	header = init_linked_list(1);
	append_value(header, 2);
	append_value(header, 3);
	append_value(header, 4);
	LinkedList* tail = get_tail_of_list(header);
	result = is_list_circle(header);
	BOOL_TO_STRING(result);


	tail->next = header;
	result = is_list_circle(header);
	BOOL_TO_STRING(result);
	empty_linked_list_with_tail(header, tail);
}