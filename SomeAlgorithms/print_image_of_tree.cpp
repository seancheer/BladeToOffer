#include "print_image_of_tree.h"

/************************************************************************/
/* ��ӡһ�����ľ���
/************************************************************************/
void print_image_of_tree(BinaryTree* tree)
{
	if (NULL == tree)
	{
		puts("Empty tree!");
		return;
	}

	BinaryTree* image_tree = get_image_of_tree(tree);
	print_tree_hierachy(image_tree);
}

/************************************************************************/
/* ��ȡһ�����ľ���˼·��
/* ��ʵ���ľ���ʵ���Ͼ��ǽ��������Ҷ��ӽ��н�����Ȼ��ݹ���д�����
/************************************************************************/
BinaryTree* get_image_of_tree(BinaryTree* tree)
{
	if (NULL == tree)
	{
		return NULL;
	}

	BinaryTree* tmp = tree->left_child;
	tree->left_child = tree->right_child;
	tree->right_child = tmp;

	if (NULL != tree->left_child)
	{
		//�������ǵ�type����
		tree->left_child->type = LEFT_NODE;
	}

	if (NULL != tree->right_child)
	{
		tree->right_child->type = RIGHT_NODE;
	}


	get_image_of_tree(tree->left_child);
	get_image_of_tree(tree->right_child);

	return tree;
}


/************************************************************************/
/* �㷨���
/************************************************************************/
void start_print_image_of_tree()
{
	//������ڵ����
	BinaryTree* root = binary_tree_init_header(10);
	const int size = 8;
	int values[size] = { 7,15,3,8,13,20,11,14 };

	for (int i = 0; i < size; ++i)
	{
		binary_tree_insert(root, values[i]);
	}

	print_tree_hierachy(root);
	print_image_of_tree(root);
	empty_binary_tree(root);


	//���ڵ����
	root = binary_tree_init_header(10);
	print_tree_hierachy(root);
	print_image_of_tree(root);
	empty_binary_tree(root);

	//���ڵ����
	root = binary_tree_init_header(10);
	binary_tree_insert(root, 12);
	print_tree_hierachy(root);
	print_image_of_tree(root);
	empty_binary_tree(root);
}
