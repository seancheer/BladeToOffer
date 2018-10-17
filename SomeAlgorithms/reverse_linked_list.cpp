#include "reverse_linked_list.h"
/************************************************************************/
/* 反转链表，直接修改原有的链表
/************************************************************************/
LinkedList* reverse_linked_list(LinkedList* header)
{
	if (NULL == header)
	{
		puts("Empty list! Return NULL!");
		return NULL;
	}

	LinkedList* new_list_header = NULL;
	LinkedList* cur = header;
	LinkedList* p_next = cur->next;
	cur->next = NULL;

	//只有一个节点
	if (NULL == p_next)
	{
		return cur;
	}

	//每次使用两个节点进行反转，保存当前节点的下一个节点，如果p_next_next为null，说明链表到头了
	while (NULL != p_next)
	{
		LinkedList* p_next_next = p_next->next;
		if (p_next_next == NULL)
		{
			new_list_header = p_next;
		}

		p_next->next = cur;
		
		cur = p_next;
		p_next = p_next_next;
	}

	return new_list_header;
}



/************************************************************************/
/* 算法入口                                                                     */
/************************************************************************/
void start_reverse_linked_list()
{
	LinkedList* header = init_linked_list(1);
	append_value(header, 2);
	append_value(header, 3);
	append_value(header, 4);
	header = reverse_linked_list(header);
	linked_list_print(header);
	empty_linked_list(header);
}