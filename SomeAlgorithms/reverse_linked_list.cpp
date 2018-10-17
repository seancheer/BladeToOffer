#include "reverse_linked_list.h"
/************************************************************************/
/* ��ת����ֱ���޸�ԭ�е�����
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

	//ֻ��һ���ڵ�
	if (NULL == p_next)
	{
		return cur;
	}

	//ÿ��ʹ�������ڵ���з�ת�����浱ǰ�ڵ����һ���ڵ㣬���p_next_nextΪnull��˵������ͷ��
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
/* �㷨���                                                                     */
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