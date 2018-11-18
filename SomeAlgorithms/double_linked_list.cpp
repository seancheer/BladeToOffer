#include "double_linked_list.h"


/************************************************************************/
/* 初始化一个链表
/************************************************************************/
DoubleLinkedList* double_list_init(int header)
{
	return double_list_malloc(header);
}

/************************************************************************/
/* 在链表末尾增加一个
/************************************************************************/
void double_list_append_value(DoubleLinkedList* header, int value)
{
	if (NULL == header)
	{
		puts("Invalid header! Could not be empty!");
		return;
	}

	DoubleLinkedList *cur = header;
	while (NULL != cur->next)
	{
		cur = cur->next;
	}

	DoubleLinkedList* new_node = double_list_malloc(value);
	cur->next = new_node;
	new_node->parent = cur;
	return;
}

/************************************************************************/
/* 根据value malloc一个节点
/************************************************************************/
DoubleLinkedList* double_list_malloc(int value)
{
	DoubleLinkedList* node = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
	if (node == nullptr)
	{
		puts("Malloc failed in DoubleLinkedList!");
		exit(-1);
	}
	memset(node, 0, sizeof(DoubleLinkedList));
	node->value = value;
	node->next = NULL;
	node->parent = NULL;
	return node;
}

/************************************************************************/
/* 清空一个链表
/************************************************************************/
void double_list_empty(DoubleLinkedList* header)
{
	if (NULL == header)
	{
		return;
	}

	DoubleLinkedList* cur = header;
	while (NULL != cur)
	{
		DoubleLinkedList* tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = NULL;
	}
}


/************************************************************************/
/* 获取最后一个节点
/************************************************************************/
DoubleLinkedList* double_list_get_last_node(DoubleLinkedList* header)
{
	if (header == NULL)
	{
		puts("Empty list! Return NULL!");
		return NULL;
	}

	DoubleLinkedList* cur = header;
	while (NULL != cur->next)
	{
		cur = cur->next;
	}

	return cur;
}

/************************************************************************/
/* 获取指定index的节点
/************************************************************************/
DoubleLinkedList* double_list_get_node_by_index(DoubleLinkedList* header, int index)
{
	if (NULL == header)
	{
		puts("Empty list! Return NULL!");
		return NULL;
	}

	DoubleLinkedList* cur = header;
	int i = 0;

	while (NULL != cur->next && i++ < index)
	{
		cur = cur->next;
	}
	return cur;
}

/************************************************************************/
/* 从头到尾打印双向链表
/************************************************************************/

void double_list_print(DoubleLinkedList* header)
{
	if (NULL == header)
	{
		puts("Empty list!");
		return;
	}

	puts("***************************************************************************************");
	DoubleLinkedList* cur = header;
	while (NULL != cur)
	{
		printf("%d\t", cur->value);
		cur = cur->next;
	}
	printf("\n");
	puts("***************************************************************************************");
}

