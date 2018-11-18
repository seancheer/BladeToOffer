#include "is_sequence_bin_tree_postorder.h"

/************************************************************************/
/* 给一个序列，每个值都不相同，判断该序列是否为二叉树的后序遍历。
/* 思路：首先根据后序遍历可以得知该二叉树的最后一个节点是根节点；然后在该序列中查找
/* 第一个比根节点大的值，那么从那个值之后，所有的值都应该比根节点大，因为从那个值开始
/* 后面的值就都是这棵子树的右子树，如果发现有值比根节点小，那么返回false；然后继续对
/* 左子树和右子树进行递归处理，直到只剩两个值为止。
/************************************************************************/
bool is_arr_bin_tree_postorder(int arr[], int size)
{
	if (NULL == arr || size <= 0)
	{
		puts("Invalid parameter!");
		return false;
	}

	return is_arr_postorder_internal(arr, 0, size - 1);
}

/************************************************************************/
/* 递归进行判断                                                                     */
/************************************************************************/
bool is_arr_postorder_internal(int arr[], int start, int end)
{
	if (end - start <= 1)
	{
		return true;
	}

	int root = arr[end];
	int right = 0;
	for (right = 0; right < end && arr[right] < root; ++right)
	{
		//do nothing
	}
	
	//右边全是右节点或者既有右节点也有左节点
	if (right < end)
	{
		//判断右子树是否有比root小的
		for (int i = right; i < end; ++i)
		{
			if (arr[i] < root)
			{
				return false;
			}
		}

		if (!is_arr_postorder_internal(arr, start, right - 1) 
			|| !is_arr_postorder_internal(arr, right, end - 1))
		{
			return false;
		}

		return true;
	}
	//右边全是左节点
	else
	{
		return is_arr_postorder_internal(arr, start, end - 1);
	}
}

/************************************************************************/
/* 开始算法
/************************************************************************/
void start_is_postorder()
{
	const int size1 = 4;
	int arr1[] = { 7,4,6,5 };
	bool result = is_arr_bin_tree_postorder(arr1, size1);
	BOOL_TO_STRING(result);

	const int size2 = 7;
	int arr2[] = { 5,7,8,9,11,10,8 };
	result = is_arr_bin_tree_postorder(arr2, size2);
	BOOL_TO_STRING(result);

	const int size3 = 1;
	int arr3[] = { 5};
	result = is_arr_bin_tree_postorder(arr3, size3);
	BOOL_TO_STRING(result);
}