#include "get_depth_of_binary_tree.h"

/************************************************************************/
/* 获取一颗二叉树的深度，深度的定义为从根节点开始到叶子节点的最长路径，其中根节点的深度为1
/* 思路：当前节点的深度为其max(depth of left child, depth of right child) + 1，所以
/* 可以根据此思路迅速写出递归代码
/* 该问题的变种见：is_a_valid_avl，判断二叉树是否为一个合法的平衡二叉树
/************************************************************************/
int get_depth_of_binary_tree(BinaryTree* header)
{
	if (NULL == header)
	{
		return 0;
	}

	int left_depth = get_depth_of_binary_tree(header->left_child);
	int right_depth = get_depth_of_binary_tree(header->right_child);

	return max(left_depth, right_depth) + 1;
}



/************************************************************************/
/* 开始算法
/************************************************************************/
void start_get_depth_of_tree()
{ 
	BinaryTree* header = binary_tree_init_header(6);
	binary_tree_insert(header, 3);
	binary_tree_insert(header, 2);
	int depth = get_depth_of_binary_tree(header);
	printf("BinaryTree depth:%d\n", depth);
	empty_binary_tree(header);
}