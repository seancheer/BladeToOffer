#include "get_depth_of_binary_tree.h"

/************************************************************************/
/* ��ȡһ�Ŷ���������ȣ���ȵĶ���Ϊ�Ӹ��ڵ㿪ʼ��Ҷ�ӽڵ���·�������и��ڵ�����Ϊ1
/* ˼·����ǰ�ڵ�����Ϊ��max(depth of left child, depth of right child) + 1������
/* ���Ը��ݴ�˼·Ѹ��д���ݹ����
/* ������ı��ּ���is_a_valid_avl���ж϶������Ƿ�Ϊһ���Ϸ���ƽ�������
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
/* ��ʼ�㷨
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