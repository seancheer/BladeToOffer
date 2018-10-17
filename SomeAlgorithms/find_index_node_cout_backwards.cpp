#include "find_index_node_cout_backwards.h"


/**
/* 查找倒数第k个节点
/* 注意：本题的倒数第一个就是最后一个节点，需要注意这一点。
******/
LinkedList* find_node_cout_backwards(LinkedList* header, int index_backwards)
{
	if (NULL == header)
	{
		puts("Empty list!");
		return NULL;
	}

	if (index_backwards < 1)
	{
		puts("Index must be greater than or equals to 1!");
		return NULL;
	}

	LinkedList* previous = header;
	LinkedList* after = header;

	int i = 1;
	while (i++ < index_backwards && NULL != previous->next)
	{
		previous = previous->next;
	}

	if (i <= index_backwards && NULL == previous->next)
	{
		puts("Index is bigger than length of list! Return NULL!");
		return NULL;
	}

	while (NULL != previous->next)
	{
		previous = previous->next;
		after = after->next;
	}

	return after;
}

/**
/* 算法入口
******/
void start_find_node_cout_backwards()
{
	//test case 1
	LinkedList* header = init_linked_list(1);
	append_value(header, 2);
	append_value(header, 3);
	append_value(header, 4);

	int index = 1;
	LinkedList* result = find_node_cout_backwards(header, index);
	printf("Find index_backwards[%d] is: %d!\n", index, result->value);

	//test case 2
	index = 3;
	result = find_node_cout_backwards(header, index);
	printf("Find index_backwards[%d] is: %d!\n", index, result->value);


	//test case 3
	index = 5;
	result = find_node_cout_backwards(header, index);
	if (NULL == result)
	{
		printf("Can not find index[%d]!\n", index);
	}
	else
	{
		printf("Find index_backwards[%d] is: %d!\n", index, result->value);
	}

	empty_linked_list(header);

}