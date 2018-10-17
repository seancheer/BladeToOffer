#include "linked_list.h"


/************************************************************************/
/* ��ʼ��һ������
/************************************************************************/
LinkedList* init_linked_list(int header)
{
	return malloc_linked_list(header);
}

/************************************************************************/
/* ������ĩβ����һ��
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
/* ����value mallocһ���ڵ�
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
/* ���һ������
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
/* ���һ��������Ҫ����β����Ϊ���ܹ���ȷ����ջ�������
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
/* ��ȡ���һ���ڵ�
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
/* ��ȡָ��index�Ľڵ�
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
/* ��������β��
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