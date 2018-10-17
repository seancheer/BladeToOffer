#include "remove_node_in_o_1.h"

/************************************************************************/
/* 删除指定node
/* 删除方法：将目标节点的下一个节点的值复制给目标节点，然后删除掉下一个节点。
/* 注意当目标节点是末尾时，还需要按照常规的方式进行删除。
/* 注意假设：目标节点必须在链表中
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

	//处于末尾位置，必须按照常规方法进行remove
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
/* 当目标节点是最后一个节点时，需要使用常规方式进行删除
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

	//此时只有一个节点
	if (prev == cur)
	{
		free(cur);
		cur = NULL;
		//更改头结点
		*header = NULL;
		return;
	}

	prev->next = NULL;
	free(cur);
	cur = NULL;
	return;
}



/************************************************************************/
/* 算法入口
/************************************************************************/
void start_remove()
{
	//只有一个节点的用例
	LinkedList* header = init_linked_list(1);
	remove_specify_node_in_o_1(&header, header);
	linked_list_print(header);
	empty_linked_list(header);

	//待删除节点在末尾
	header = init_linked_list(1);
	append_value(header, 2);
	append_value(header, 3);
	remove_specify_node_in_o_1(&header, linked_list_get_last_node(header));
	linked_list_print(header);
	empty_linked_list(header);

	//待删除节点在中间
	header = init_linked_list(1);
	append_value(header, 2);
	append_value(header, 3);
	append_value(header, 4);
	remove_specify_node_in_o_1(&header, linked_list_get_node_by_index(header,2));
	linked_list_print(header);
	empty_linked_list(header);
}