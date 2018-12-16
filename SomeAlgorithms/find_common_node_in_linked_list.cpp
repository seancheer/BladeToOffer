#include "find_common_node_in_linked_list.h"


/************************************************************************/
/* 查找两个链表的第一个公共节点
/* 解题思路： 
/* 先统计两个链表的长度，如果统计出来长度差m，接着，长度较长的先走m步，然后长度较短开始走，
/* 当出现两个节点相同的节点时，那么这个节点就是第一个公共节点，该题目有以下变形：
/* 1 在二叉树中查找第一个公共的祖先节点，如果该二叉树是标准的排序的二叉树，那么从根节点开始，如果该节点
/*   都比传入的两个节点大，那么往右边走，如果比两个节点都小，那么往左边走，如果处于两个节点中间，那么这个节点
/*   就是第一个公共祖先
/* 2 如果该二叉树不是排序二叉树，假设该二叉树有父亲指针，那么，本质上就是就是查找链表的第一个公共节点，就是本题
/* 3 如果该二叉树不是排序二叉树且没有父亲指针，那么可以从根节点开始一直查找到目标节点，记录下两个路径，然后查找
/*   路径里面最后一个相同的节点即可
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
/* 算法入口
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