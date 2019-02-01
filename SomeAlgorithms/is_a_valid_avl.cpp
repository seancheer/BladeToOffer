#include "is_a_valid_avl.h"

/************************************************************************/
/* 判断一颗二叉树是否为一个合法的avl
/************************************************************************/

/************************************************************************/
/* 思路1：
/* 计算出左儿子和右儿子的高度（利用get_depth_of_tree中提供的方法)，然后判断高度差是否小于等于1，
/* 是的话，那么avl合法，否则，非法，然后进一步判断左子树和右子树，该方法需要重复遍历很多节点，因此效率不高
/************************************************************************/
bool is_a_valid_avl_simple(BinaryTree* header)
{
	if (NULL == header)
	{
		return true;
	}

	int l_depth = get_depth_of_binary_tree(header->left_child);
	int r_depth = get_depth_of_binary_tree(header->right_child);

	int result = l_depth - r_depth;
	if (result < -1 || result > 1)
	{
		return false;
	}

	return is_a_valid_avl_simple(header->left_child) && is_a_valid_avl_simple(header->right_child);
}



/************************************************************************/
/* 思路2：
/* 和思路1一致，采取后序遍历的方式，不同的是，使用一个变量depth来记录每次后续遍历后的高度，
/* 然后将该高度不断往上传，这样子就不需要重复遍历节点了
/************************************************************************/
bool is_a_valid_avl_by_depth(BinaryTree* header)
{
	int depth = 0;
	return is_a_valid_avl_by_depth_internal(header, &depth);
}


/************************************************************************/
/* 内部方法
/************************************************************************/
bool is_a_valid_avl_by_depth_internal(BinaryTree* header, int* depth)
{
	if (NULL == header)
	{
		*depth = 0;
		return true;
	}

	int l_depth = 0;
	int r_depth = 0;
	if (is_a_valid_avl_by_depth_internal(header->left_child, &l_depth) &&
		is_a_valid_avl_by_depth_internal(header->right_child, &r_depth))
	{
		//判断左子树和右子树高度是否合法
		int tmp = l_depth - r_depth;
		if (tmp < -1 || tmp > 1)
		{
			return false;
		}

		*depth = max(l_depth, r_depth) + 1;
		return true;
	}

	return false;
}



/************************************************************************/
/* 开始算法
/************************************************************************/
void start_valid_avl()
{
	BinaryTree* header = binary_tree_init_header(6);
	binary_tree_insert(header, 3);
	binary_tree_insert(header, 2);
	bool valid = is_a_valid_avl_simple(header);
	BOOL_TO_STRING(valid);
	valid = is_a_valid_avl_by_depth(header);
	BOOL_TO_STRING(valid);
	empty_binary_tree(header);

	header = binary_tree_init_header(16);
	binary_tree_insert(header, 13);
	binary_tree_insert(header, 9);
	binary_tree_insert(header, 15);
	binary_tree_insert(header, 26);
	binary_tree_insert(header, 20);
	valid = is_a_valid_avl_simple(header);
	BOOL_TO_STRING(valid);
	valid = is_a_valid_avl_by_depth(header);
	BOOL_TO_STRING(valid);
	empty_binary_tree(header);
}