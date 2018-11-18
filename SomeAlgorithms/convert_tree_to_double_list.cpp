#include "convert_tree_to_double_list.h"

/************************************************************************/
/* 把二叉树转换为双端链表，要求只能调整指针的指向，不能创建任何多余的节点
/* 思路：
/* 使用中序遍历来进行转换，在进行转换的时候，需要维护一个lastNode，表示每次
/* 递归时返回的双端链表的最末端。其中左儿子表示上一个节点，右儿子表示下一个节点
/************************************************************************/
BinaryTree* convert_tree_to_double_list(BinaryTree* header)
{
	if (NULL == header)
	{
		puts("Invalid parameter!");
		return NULL;
	}
	BinaryTree* last_node = NULL;
	convert_tree_internal(header, &last_node);

	if (NULL == last_node)
	{
		puts("Internal Error!");
		return NULL;
	}

	while (NULL != last_node->left_child)
	{
		last_node = last_node->left_child;
	}

	return last_node;
}

/************************************************************************/
/* 内部递归进行转换
/************************************************************************/
void convert_tree_internal(BinaryTree* node, BinaryTree** last_node)
{
	if (NULL == node)
	{
		return;
	}

	BinaryTree* cur = node;
	convert_tree_internal(node->left_child, last_node);

	//左子树遍历完毕，开始进行处理
	if (NULL != *last_node)
	{
		(*last_node)->right_child = cur;
	}

	cur->left_child = *last_node;
	*last_node = cur;
	convert_tree_internal(node->right_child, last_node);
}

/************************************************************************/
/* 正向和逆向打印双端列表，验证转换的有效性。
/************************************************************************/
void convert_tree_print(BinaryTree* node)
{
	if (NULL == node)
	{
		puts("Invalid header!");
		return;
	}
	puts("****************************************************************************************************");

	BinaryTree* cur = node;
	BinaryTree* tail = NULL;
	while (NULL != cur)
	{
		printf("%d\t", cur->value);
		tail = cur;
		cur = cur->right_child;
	}

	puts("");
	while (NULL != tail)
	{
		printf("%d\t", tail->value);
		tail = tail->left_child;
	}
	puts("");
	puts("****************************************************************************************************");
}

/************************************************************************/
/* 对转换后的双端列表进行empty操作
/************************************************************************/
void convert_tree_empty_list(BinaryTree* header)
{
	BinaryTree* cur = header;
	while (NULL != cur)
	{
		BinaryTree* next = cur->left_child;
		free(cur);
		cur = NULL;
		cur = next;
	}
}

/************************************************************************/
/* 开始算法
/************************************************************************/
void start_convert_binary_tree_to_list()
{
	//测试基本的场景
	const int size = 4;
	int arr[size] = { 10,5,12,25 };
	BinaryTree* header = binary_tree_init_header(15);
	for (int i = 0; i < size; ++i)
	{
		binary_tree_insert(header, arr[i]);
	}

	BinaryTree* double_list = convert_tree_to_double_list(header);
	convert_tree_print(double_list);
	convert_tree_empty_list(double_list);


	//测试一个节点
	header = binary_tree_init_header(15);

	double_list = convert_tree_to_double_list(header);
	convert_tree_print(double_list);
	convert_tree_empty_list(double_list);

	//测试只有一个孩子的场景
	const int size1 = 3;
	int arr1[size1] = { 10,5,25 };
	header = binary_tree_init_header(15);
	for (int i = 0; i < size1; ++i)
	{
		binary_tree_insert(header, arr1[i]);
	}

	double_list = convert_tree_to_double_list(header);
	convert_tree_print(double_list);
	convert_tree_empty_list(double_list);
}