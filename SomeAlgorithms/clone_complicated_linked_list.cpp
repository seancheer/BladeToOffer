#include "clone_complicated_linked_list.h"


/************************************************************************/
/* �����¡Ŀ������������һ��clone�������ṹ
/* ˼·��
/* ����������޸�ԭ������ô���ķ�ʽ���£�
/*     1 ����next������������������ԭ����ΪN�����ƺ������ΪN'
/*     2 ʹ��һ��map����¼��N��ÿһ���ڵ��N' ��ÿһ���ڵ�Ķ�Ӧ��ϵ
/*     3 ����sibling�ڵ㣬N�е�ָ���Ȼ������O(1)��ʱ�����ҵ���Ӧ��N'�еĽڵ㣬��Ϊ֮ǰ����
/*       һһ��Ӧ�Ĺ�ϵ��
/*     4 ���
/* ��������޸�ԭ������ô���ķ�ʽ���£�
/*     1 ��ԭ�����е�ÿ���ڵ㸴���£����ƺ�Ľڵ��ΪN'��ԭ�ڵ��ΪN�� ��n->next = n', n'->next = (n+1)'
/*     2 ��ôN�е�sibling��N'�е�sibling�����¶�Ӧ��ϵ��n'->sibling = n->sibling->next
/*     3 ��N'��ԭ��������������
/*     4 ԭ����ظ���ͬʱ����Ҳ��Ӧ�����
/* ���ǲ��õڶ��ַ�ʽ���÷�ʽҲ�������Ӷ���Ŀռ�
/************************************************************************/
LinkedList* clone_complicated_linked_list(LinkedList* your_list)
{
	if (NULL == your_list)
	{
		puts("Invalid parameter!");
		return NULL;
	}

	//step 1: ����ԭ�����е�ÿ���ڵ�
	double_list(your_list);
	//step 2: ����siblingָ��
	adjust_sibling(your_list);
	//step 3: ��ȡ���ƺ���������ظ�ԭ����
	return get_copiedlist_and_restore_originlist(your_list);
}

/************************************************************************/
/* ���������е�ÿ���ڵ�
/************************************************************************/
void double_list(LinkedList* your_list)
{
	LinkedList* cur = your_list;
	LinkedList* prev = cur;
	while (NULL != cur)
	{
		LinkedList* tmp = malloc_linked_list(cur->value);
		LinkedList* old_next = cur->next;
		cur->next = tmp;
		tmp->next = old_next;
		cur = old_next;
	}

}

/************************************************************************/
/* ����siblingָ��
/************************************************************************/
void adjust_sibling(LinkedList* your_list)
{
	LinkedList* cur = your_list;
	while (NULL != cur)
	{
		LinkedList* copied_node = cur->next;
		if (cur->sibling != NULL)
		{
			copied_node->sibling = cur->sibling->next;
		}

		cur = copied_node->next;
	}
}

/************************************************************************/
/* ��ȡ���ƺ�������һָ�ԭ�����ָ��
/************************************************************************/
LinkedList* get_copiedlist_and_restore_originlist(LinkedList* your_list)
{
	LinkedList* origin_cur = your_list;
	LinkedList* copied_header = your_list->next;
	LinkedList* copied_cur = your_list->next;

	while (copied_cur->next != NULL)
	{
		origin_cur->next = copied_cur->next;
		copied_cur->next = copied_cur->next->next;

		origin_cur = origin_cur->next;
		copied_cur = copied_cur->next;
	}

	origin_cur->next = NULL;
	copied_cur->next = NULL;
	return copied_header;
}

/************************************************************************/
/* ��ʼ�㷨
/************************************************************************/
void start_clone_complicated_list()
{
	//���Ե��ڵ�
	LinkedList* list1 = init_linked_list(2);
	LinkedList* cloned_list = clone_complicated_linked_list(list1);
	linked_list_print_with_sibling(list1);
	linked_list_print_with_sibling(cloned_list);
	free(list1);
	free(cloned_list);

	//���Ի�״
	LinkedList* list2 = init_linked_list(2);
	append_value(list2, 3);
	append_value(list2, 4);
	append_value(list2, 5);

	LinkedList* tail2 = get_tail_of_list(list2);
	//let 3 -> 5
	list2->next->sibling = tail2;
	//let 5 -> 3
	tail2->sibling = list2->next;
	//let 4 -> 2
	list2->next->next->sibling = list2;

	cloned_list = clone_complicated_linked_list(list2);
	linked_list_print_with_sibling(list2);
	linked_list_print_with_sibling(cloned_list);
	free(list2);
	free(cloned_list);


	//���Լ��˳���
	LinkedList* list3 = init_linked_list(2);
	append_value(list3, 3);
	append_value(list3, 4);
	append_value(list3, 5);

	//let 5 -> 4 -> 3 -> 2
	list3->next->next->next->sibling = list3->next->next;
	list3->next->next->sibling = list3->next;
	list3->next->sibling = list3;

	cloned_list = clone_complicated_linked_list(list3);
	linked_list_print_with_sibling(list3);
	linked_list_print_with_sibling(cloned_list);
	free(list3);
	free(cloned_list);
}