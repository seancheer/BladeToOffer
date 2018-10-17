#include "is_tree_contains_another_tree.h"

/************************************************************************/
/* �ж�һ�����Ƿ�Ϊ����һ�������ӽṹ
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
/* �ڲ������жϵķ�����˼·��
/* 1 ͨ��������a�������ǰ�ڵ��ֵ��b�Ľڵ���ͬ����ô����is_tree_a_contains_tree_b����һ�������ж�
/* 2 �������ͬ����ô��һ��Ѱ�Һ�b����ֵ��ͬ����
/* �÷�����Ҫ���������a�������a��ǰ�ڵ�ֵ����b��ȣ���ô����is_tree_a_contains_tree_b��һ���ж��������ṹ�Ƿ�һ��
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

	//˵����ǰ�ڵ��������tree_b����ȣ���һ����������������������
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
/* �ݹ��ж�tree_a�Ƿ����tree_b
/* �÷�����һ�����������������ж���a�Ƿ������b
/************************************************************************/
bool is_tree_a_contains_tree_b(BinaryTree* tree_a, BinaryTree* tree_b)
{
	//����a���ܱ�b��������bΪ׼
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
/* �㷨���
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