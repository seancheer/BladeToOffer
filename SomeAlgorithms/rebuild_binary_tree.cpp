#include "rebuild_binary_tree.h"
/************************************************************************/
/* 根据前序遍历和中序遍历来重建二叉树，思路如下所示：
/* 1 根据前序遍历确定root节点
/* 2 在中序遍历中查找root节点，记录下位置
/* 3 在中序遍历中确定左子树和右子树的个数
/* 4 如果存在左子树，那么传入对应的范围，递归调用
/* 5 如果存在右子树，那么传入对应的范围，递归调用

/* 递归的终止条件：发现只存在当前一个元素的时候，那么创建二叉树节点，直接返回
/************************************************************************/
BinaryTree* rebuild_binary_tree(int pre_order_arr[], int pre_size, int middle_order_arr[], int middle_size)
{
	if (NULL == pre_order_arr || NULL == middle_order_arr)
	{
		return NULL;
	}

	return rebuild_binary_tree_internal(pre_order_arr, 0, pre_size - 1, middle_order_arr, 0, middle_size - 1);
}


/************************************************************************/
/* 内部真正实现rebuild的逻辑
/************************************************************************/
BinaryTree* rebuild_binary_tree_internal(int pre_order_arr[], int pre_left, int pre_right,
	int middle_order_arr[], int middle_left, int middle_right)
{
	int root = pre_order_arr[pre_left];
	if (pre_left >= pre_right || middle_left >= middle_right)
	{
		return malloc_item(root);
	}

	int root_in_middle = 0;
	for (int i = middle_left; i <= middle_right; ++i)
	{
		if (middle_order_arr[i] == root)
		{
			root_in_middle = i;
			break;
		}
	}

	int sum_in_left = root_in_middle - middle_left;
	int sum_in_right = middle_right - root_in_middle;
	BinaryTree* root_node = malloc_item(root);

	if (sum_in_left > 0)
	{
		root_node->left_child = rebuild_binary_tree_internal(pre_order_arr, pre_left + 1, pre_left + sum_in_left, middle_order_arr,
			middle_left, root_in_middle - 1);
		root_node->left_child->type = LEFT_NODE;
	}
	
	if (sum_in_right > 0)
	{
		root_node->right_child = rebuild_binary_tree_internal(pre_order_arr, pre_left + sum_in_left + 1, pre_right, middle_order_arr,
			root_in_middle + 1, middle_right);
		root_node->right_child->type = RIGHT_NODE;
	}

	return root_node;
}





void rebuild_tree_1()
{
	int size = 8;
	int pre_order_arr[] = { 1,2,4,7,3,5,6,8 };
	int middle_order_arr[] = { 4,7,2,1,5,3,8,6 };

	BinaryTree* header = rebuild_binary_tree(pre_order_arr, size, middle_order_arr, size);
	print_tree_hierachy(header);
}


void rebuild_tree_2()
{
	int size = 3;
	int pre_order_arr[] = { 4,1,5};
	int middle_order_arr[] = { 1,4,5};

	BinaryTree* header = rebuild_binary_tree(pre_order_arr, size, middle_order_arr, size);
	print_tree_hierachy(header);
}

void rebuild_tree_3()
{
	int size = 5;
	int pre_order_arr[] = { 14,11,10,12,15 };
	int middle_order_arr[] = { 10,11,12,14,15 };

	BinaryTree* header = rebuild_binary_tree(pre_order_arr, size, middle_order_arr, size);
	print_tree_hierachy(header);
}


/************************************************************************/
/* 算法入口
/************************************************************************/
void start_rebuild_tree()
{
	rebuild_tree_3();
}