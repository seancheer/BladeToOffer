#include "is_tree_contains_another_tree.h"

/************************************************************************/
/* 判断一个树是否为另外一个树的子结构
/************************************************************************/
bool is_tree_contains_another(BinaryTree* tree_a, BinaryTree* tree_b)
{
	if (tree_a == NULL || NULL == tree_b)
	{
		puts("Invalid tree_a or tree_b ! Return false!");
		return false;
	}

	return is_tree_contains_another_internal(tree_a, tree_b);
}

/************************************************************************/
/* 内部进行判断的方法，思路：
/* 1 通过遍历树a，如果当前节点的值和b的节点相同，那么调用is_tree_a_contains_tree_b来进一步进行判断
/* 2 如果不相同，那么进一步寻找和b顶点值相同的数
/* 该方法主要负责遍历树a，如果树a当前节点值和树b相等，那么调用is_tree_a_contains_tree_b进一步判断两个树结构是否一致
/************************************************************************/
bool is_tree_contains_another_internal(BinaryTree* tree_a, BinaryTree* tree_b)
{
	if (NULL == tree_a || NULL == tree_b)
	{
		return false;
	}

	bool result = false;
	if (tree_a->value == tree_b->value)
	{
		result = is_tree_a_contains_tree_b(tree_a, tree_b);
	}

	//说明当前节点的子树和tree_b不相等，进一步从左子树和右子树查找
	if (!result)
	{
		result = is_tree_contains_another_internal(tree_a->left_child, tree_b);
	}

	if (!result)
	{
		result = is_tree_contains_another_internal(tree_a->right_child, tree_b);
	}

	return result;
}


/************************************************************************/
/* 递归判断tree_a是否包含tree_b
/* 该方法是一个辅助方法，真正判断树a是否包含树b
/************************************************************************/
bool is_tree_a_contains_tree_b(BinaryTree* tree_a, BinaryTree* tree_b)
{
	//由于a可能比b大，所以以b为准
	if (NULL == tree_b)
	{
		return true;
	}
	else
	{
		if (NULL == tree_a)
		{
			return false;
		}

		if (tree_a->value != tree_b->value)
		{
			return false;
		}

		bool l_value = is_tree_a_contains_tree_b(tree_a->left_child, tree_b->left_child);
		bool r_value = is_tree_a_contains_tree_b(tree_a->right_child, tree_b->right_child);
		if (l_value && r_value)
		{ 
			return true;
		}

		return false;
	}
}


/************************************************************************/
/* 算法入口
/************************************************************************/
void start_is_tree_contains_another()
{
	BinaryTree* root = binary_tree_init_header(10);
	const int size = 8;
	int values[size] = { 7,15,3,8,13,20,11,14 };

	for (int i = 0; i < size; ++i)
	{
		binary_tree_insert(root, values[i]);
	}
	BinaryTree* child = binary_tree_find_value(root, 13);
	bool result = is_tree_contains_another(root, child);
	BOOL_TO_STRING(result);

	BinaryTree* tree2 = binary_tree_init_header(15);
	binary_tree_insert(tree2, 13);
	binary_tree_insert(tree2, 20);
	result = is_tree_contains_another(root, tree2);
	BOOL_TO_STRING(result);
	empty_binary_tree(tree2);

	BinaryTree* tree3 = binary_tree_init_header(13);
	binary_tree_insert(tree3, 12);
	result = is_tree_contains_another(root, tree3);
	BOOL_TO_STRING(result);
	empty_binary_tree(tree3);

	empty_binary_tree(root);
}