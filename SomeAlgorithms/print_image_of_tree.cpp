#include "print_image_of_tree.h"

/************************************************************************/
/* 打印一个树的镜像
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
/* 获取一个树的镜像，思路：
/* 其实树的镜像实际上就是将树的左右儿子进行交换，然后递归进行处理即可
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
		//更正我们的type属性
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
/* 算法入口
/************************************************************************/
void start_print_image_of_tree()
{
	//正常多节点测试
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


	//单节点测试
	root = binary_tree_init_header(10);
	print_tree_hierachy(root);
	print_image_of_tree(root);
	empty_binary_tree(root);

	//两节点测试
	root = binary_tree_init_header(10);
	binary_tree_insert(root, 12);
	print_tree_hierachy(root);
	print_image_of_tree(root);
	empty_binary_tree(root);
}
