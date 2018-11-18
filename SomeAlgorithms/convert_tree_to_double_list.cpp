#include "convert_tree_to_double_list.h"

/************************************************************************/
/* �Ѷ�����ת��Ϊ˫������Ҫ��ֻ�ܵ���ָ���ָ�򣬲��ܴ����κζ���Ľڵ�
/* ˼·��
/* ʹ���������������ת�����ڽ���ת����ʱ����Ҫά��һ��lastNode����ʾÿ��
/* �ݹ�ʱ���ص�˫���������ĩ�ˡ���������ӱ�ʾ��һ���ڵ㣬�Ҷ��ӱ�ʾ��һ���ڵ�
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
/* �ڲ��ݹ����ת��
/************************************************************************/
void convert_tree_internal(BinaryTree* node, BinaryTree** last_node)
{
	if (NULL == node)
	{
		return;
	}

	BinaryTree* cur = node;
	convert_tree_internal(node->left_child, last_node);

	//������������ϣ���ʼ���д���
	if (NULL != *last_node)
	{
		(*last_node)->right_child = cur;
	}

	cur->left_child = *last_node;
	*last_node = cur;
	convert_tree_internal(node->right_child, last_node);
}

/************************************************************************/
/* ����������ӡ˫���б���֤ת������Ч�ԡ�
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
/* ��ת�����˫���б����empty����
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
/* ��ʼ�㷨
/************************************************************************/
void start_convert_binary_tree_to_list()
{
	//���Ի����ĳ���
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


	//����һ���ڵ�
	header = binary_tree_init_header(15);

	double_list = convert_tree_to_double_list(header);
	convert_tree_print(double_list);
	convert_tree_empty_list(double_list);

	//����ֻ��һ�����ӵĳ���
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