#include "double_linked_list.h"


/************************************************************************/
/* ��ʼ��һ������
/************************************************************************/
DoubleLinkedList* double_list_init(int header)
{
	return double_list_malloc(header);
}

/************************************************************************/
/* ������ĩβ����һ��
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
/* ����value mallocһ���ڵ�
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
/* ���һ������
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
/* ��ȡ���һ���ڵ�
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
/* ��ȡָ��index�Ľڵ�
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
/* ��ͷ��β��ӡ˫������
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

