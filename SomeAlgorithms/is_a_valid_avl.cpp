#include "is_a_valid_avl.h"

/************************************************************************/
/* �ж�һ�Ŷ������Ƿ�Ϊһ���Ϸ���avl
/************************************************************************/

/************************************************************************/
/* ˼·1��
/* ���������Ӻ��Ҷ��ӵĸ߶ȣ�����get_depth_of_tree���ṩ�ķ���)��Ȼ���жϸ߶Ȳ��Ƿ�С�ڵ���1��
/* �ǵĻ�����ôavl�Ϸ������򣬷Ƿ���Ȼ���һ���ж������������������÷�����Ҫ�ظ������ܶ�ڵ㣬���Ч�ʲ���
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
/* ˼·2��
/* ��˼·1һ�£���ȡ��������ķ�ʽ����ͬ���ǣ�ʹ��һ������depth����¼ÿ�κ���������ĸ߶ȣ�
/* Ȼ�󽫸ø߶Ȳ������ϴ��������ӾͲ���Ҫ�ظ������ڵ���
/************************************************************************/
bool is_a_valid_avl_by_depth(BinaryTree* header)
{
	int depth = 0;
	return is_a_valid_avl_by_depth_internal(header, &depth);
}


/************************************************************************/
/* �ڲ�����
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
		//�ж����������������߶��Ƿ�Ϸ�
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
/* ��ʼ�㷨
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