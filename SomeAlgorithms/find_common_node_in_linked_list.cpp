#include "find_common_node_in_linked_list.h"


/************************************************************************/
/* ������������ĵ�һ�������ڵ�
/* ����˼·�� 
/* ��ͳ����������ĳ��ȣ����ͳ�Ƴ������Ȳ�m�����ţ����Ƚϳ�������m����Ȼ�󳤶Ƚ϶̿�ʼ�ߣ�
/* �����������ڵ���ͬ�Ľڵ�ʱ����ô����ڵ���ǵ�һ�������ڵ㣬����Ŀ�����±��Σ�
/* 1 �ڶ������в��ҵ�һ�����������Ƚڵ㣬����ö������Ǳ�׼������Ķ���������ô�Ӹ��ڵ㿪ʼ������ýڵ�
/*   ���ȴ���������ڵ����ô���ұ��ߣ�����������ڵ㶼С����ô������ߣ�������������ڵ��м䣬��ô����ڵ�
/*   ���ǵ�һ����������
/* 2 ����ö������������������������ö������и���ָ�룬��ô�������Ͼ��Ǿ��ǲ�������ĵ�һ�������ڵ㣬���Ǳ���
/* 3 ����ö��������������������û�и���ָ�룬��ô���ԴӸ��ڵ㿪ʼһֱ���ҵ�Ŀ��ڵ㣬��¼������·����Ȼ�����
/*   ·���������һ����ͬ�Ľڵ㼴��
/************************************************************************/
void find_common_node_in_linked_list(LinkedList* first, LinkedList* second)
{
	if (NULL == first || NULL == second)
	{
		puts("Invalid para!");
		return;
	}

	int first_len = 0;
	int second_len = 0;

	LinkedList* tmp = first;
	while (tmp != NULL)
	{
		++first_len;
		tmp = tmp->next;
	}

	tmp = second;
	while (tmp != NULL)
	{
		++second_len;
		tmp = tmp->next;
	}

	if (first_len > second_len)
	{
		int distance = first_len - second_len;
		int i = 0;
		while (i < distance)
		{
			++i;
			first = first->next;
		}
	}
	else
	{
		int distance = first_len - second_len;
		int i = 0;
		while (i < distance)
		{
			++i;
			second = second->next;
		}
	}

	while (NULL != first && NULL != second && first->value != second->value)
	{
		first = first->next;
		second = second->next;
	}

	if (NULL == first || NULL == second)
	{
		puts("Could not find the common node!");
		return;
	}

	printf("Common node:%d!\n", first->value);
}


/************************************************************************/
/* �㷨���
/************************************************************************/
void start_find_common_node()
{
	LinkedList* first = init_linked_list(1);
	append_value(first, 2);
	append_value(first, 3);
	append_value(first, 100);

	LinkedList* second = init_linked_list(7);
	append_value(second, 8);
	append_value(second, 9);

	LinkedList* node4 = malloc_linked_list(4);
	LinkedList* node5 = malloc_linked_list(5);
	LinkedList* node6 = malloc_linked_list(6);
	node4->next = node5;
	node5->next = node6;

	first->next->next->next = node4;
	second->next->next = node4;
	find_common_node_in_linked_list(first, second);

}