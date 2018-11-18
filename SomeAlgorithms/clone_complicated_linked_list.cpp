#include "clone_complicated_linked_list.h"


/************************************************************************/
/* 负责克隆目标链表，并返回一个clone后的链表结构
/* 思路：
/* 如果不允许修改原链表，那么最快的方式如下：
/*     1 根据next首先整个复制下链表，原链表即为N，复制后的链表即为N'
/*     2 使用一个map，记录下N中每一个节点和N' 中每一个节点的对应关系
/*     3 对于sibling节点，N中的指向必然可以在O(1)的时间内找到对应的N'中的节点，因为之前都是
/*       一一对应的关系。
/*     4 完结
/* 如果可以修改原链表，那么最快的方式如下：
/*     1 将原链表中的每个节点复制下，复制后的节点成为N'，原节点成为N， 让n->next = n', n'->next = (n+1)'
/*     2 那么N中的sibling和N'中的sibling有如下对应关系：n'->sibling = n->sibling->next
/*     3 将N'从原链表上面拆分下来
/*     4 原链表回复，同时复制也相应的完成
/* 我们采用第二种方式，该方式也不会增加额外的空间
/************************************************************************/
LinkedList* clone_complicated_linked_list(LinkedList* your_list)
{
	if (NULL == your_list)
	{
		puts("Invalid parameter!");
		return NULL;
	}

	//step 1: 复制原链表中的每个节点
	double_list(your_list);
	//step 2: 调整sibling指向
	adjust_sibling(your_list);
	//step 3: 获取复制后的链表，并回复原链表
	return get_copiedlist_and_restore_originlist(your_list);
}

/************************************************************************/
/* 复制链表中的每个节点
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
/* 调整sibling指向
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
/* 获取复制后的链表并且恢复原链表的指向
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
/* 开始算法
/************************************************************************/
void start_clone_complicated_list()
{
	//测试单节点
	LinkedList* list1 = init_linked_list(2);
	LinkedList* cloned_list = clone_complicated_linked_list(list1);
	linked_list_print_with_sibling(list1);
	linked_list_print_with_sibling(cloned_list);
	free(list1);
	free(cloned_list);

	//测试环状
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


	//测试极端场景
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