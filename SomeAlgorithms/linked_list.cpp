#include "linked_list.h"


/************************************************************************/
/* 初始化一个链表
/************************************************************************/
LinkedList* init_linked_list(int header)
{
	return malloc_linked_list(header);
}

/************************************************************************/
/* 在链表末尾增加一个
/************************************************************************/
void append_value(LinkedList* header, int value)
{
	if (NULL == header)
	{
		puts("Invalid header! Could not be empty!");
		return;
	}

	LinkedList *cur = header;
	while (NULL != cur->next)
	{
		cur = cur->next;
	}

	cur->next = malloc_linked_list(value);
	return;
}

/************************************************************************/
/* 根据value malloc一个节点
/************************************************************************/
LinkedList* malloc_linked_list(int value)
{
	LinkedList* node = (LinkedList*)malloc(sizeof(LinkedList));
	if (node == nullptr)
	{
		puts("Malloc failed in linkedList!");
		exit(-1);
	}
	memset(node, 0, sizeof(LinkedList));
	node->value = value;
	node->next = NULL;
	return node;
}

/************************************************************************/
/* 清空一个链表
/************************************************************************/
void empty_linked_list(LinkedList* header)
{
	if (NULL == header)
	{
		return;
	}

	LinkedList* cur = header;
	while (NULL != cur)
	{
		LinkedList* tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = NULL;
	}
}

/************************************************************************/
/* 清空一个链表，需要传入尾部，为了能够正确的清空环形链表
/************************************************************************/
void empty_linked_list_with_tail(LinkedList* header, LinkedList* tail)
{
	if (NULL == header)
	{
		return;
	}

	LinkedList* cur = header;
	while (NULL != cur && tail != cur)
	{
		LinkedList* tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = NULL;
	}

	if (NULL != cur)
	{
		free(cur);
		cur = NULL;
	}
}


/************************************************************************/
/* 获取最后一个节点
/************************************************************************/
LinkedList* linked_list_get_last_node(LinkedList* header)
{
	if (header == NULL)
	{
		puts("Empty list! Return NULL!");
		return NULL;
	}

	LinkedList* cur = header;
	while (NULL != cur->next)
	{
		cur = cur->next;
	}

	return cur;
}

/************************************************************************/
/* 获取指定index的节点
/************************************************************************/
LinkedList* linked_list_get_node_by_index(LinkedList* header, int index)
{
	if (NULL == header)
	{
		puts("Empty list! Return NULL!");
		return NULL;
	}

	LinkedList* cur = header;
	int i = 0;

	while (NULL != cur->next && i++ < index)
	{
		cur = cur->next;
	}
	return cur;
}

void linked_list_print(LinkedList* header)
{
	if (NULL == header)
	{
		puts("Empty list!");
		return;
	}

	puts("***************************************************************************************");
	LinkedList* cur = header;
	while (NULL != cur)
	{
		printf("%d\t", cur->value);
		cur = cur->next;
	}
	printf("\n");
	puts("***************************************************************************************");
}



/************************************************************************/
/* 获得链表的尾端
/************************************************************************/
LinkedList* get_tail_of_list(LinkedList* header)
{
	if (NULL == header)
	{
		puts("Empty list! Return NULL!");
		return header;
	}

	LinkedList* cur = header;
	while (NULL != cur->next)
	{
		cur = cur->next;
	}

	return cur;
}