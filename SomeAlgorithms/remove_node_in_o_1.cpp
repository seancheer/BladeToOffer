#include "remove_node_in_o_1.h"

/************************************************************************/
/* ɾ��ָ��node
/* ɾ����������Ŀ��ڵ����һ���ڵ��ֵ���Ƹ�Ŀ��ڵ㣬Ȼ��ɾ������һ���ڵ㡣
/* ע�⵱Ŀ��ڵ���ĩβʱ������Ҫ���ճ���ķ�ʽ����ɾ����
/* ע����裺Ŀ��ڵ������������
/************************************************************************/
void remove_specify_node_in_o_1(LinkedList** header, LinkedList* target)
{
	if (NULL == header || NULL == *header)
	{
		puts("Empty list!");
		return;
	}


	if (NULL == target)
	{
		puts("Invalid target!");
		return;
	}

	//����ĩβλ�ã����밴�ճ��淽������remove
	if (target->next == NULL)
	{
		remove_node_in_end(header,target);
		return;
	}

	LinkedList* t_next = target->next;
	target->value = t_next->value;
	target->next = t_next->next;

	free(t_next);
	t_next = NULL;
	return;
}



/************************************************************************/
/* ��Ŀ��ڵ������һ���ڵ�ʱ����Ҫʹ�ó��淽ʽ����ɾ��
/************************************************************************/
void remove_node_in_end(LinkedList** header, LinkedList* target)
{
	LinkedList* prev = *header;
	LinkedList* cur = *header;
	while (NULL != cur->next)
	{
		prev = cur;
		cur = cur->next;
	}

	if (cur->value != target->value)
	{
		puts("Invalid target! Must be node in list!");
		return;
	}

	//��ʱֻ��һ���ڵ�
	if (prev == cur)
	{
		free(cur);
		cur = NULL;
		//����ͷ���
		*header = NULL;
		return;
	}

	prev->next = NULL;
	free(cur);
	cur = NULL;
	return;
}



/************************************************************************/
/* �㷨���
/************************************************************************/
void start_remove()
{
	//ֻ��һ���ڵ������
	LinkedList* header = init_linked_list(1);
	remove_specify_node_in_o_1(&header, header);
	linked_list_print(header);
	empty_linked_list(header);

	//��ɾ���ڵ���ĩβ
	header = init_linked_list(1);
	append_value(header, 2);
	append_value(header, 3);
	remove_specify_node_in_o_1(&header, linked_list_get_last_node(header));
	linked_list_print(header);
	empty_linked_list(header);

	//��ɾ���ڵ����м�
	header = init_linked_list(1);
	append_value(header, 2);
	append_value(header, 3);
	append_value(header, 4);
	remove_specify_node_in_o_1(&header, linked_list_get_node_by_index(header,2));
	linked_list_print(header);
	empty_linked_list(header);
}