#include "binary_tree.h"
/************************************************************************/
/* 插入数据
/* node: header
/* value: new_value
/************************************************************************/
BinaryTree* binary_tree_insert(BinaryTree* node, int value)
{
	if (NULL == node)
	{
		return malloc_item(value);
	}

	if (value < node->value)
	{
		node->left_child = binary_tree_insert(node->left_child, value);
		node->left_child->type = LEFT_NODE;
	}
	else
	{
		node->right_child = binary_tree_insert(node->right_child, value);
		node->right_child->type = RIGHT_NODE;
	}

	return node;
}

/************************************************************************/
/* 根据value生成一个header
/************************************************************************/
BinaryTree* binary_tree_init_header(int value)
{
	return malloc_item(value);
}

/************************************************************************/
/* 根据value申请一个新的项目
/************************************************************************/
BinaryTree* malloc_item(int value)
{
	BinaryTree* new_node = (BinaryTree*)malloc(sizeof(BinaryTree));
	if (NULL == new_node)
	{
		puts("Malloc failed! \n");
		exit(-1);
	}
	memset(new_node, 0, sizeof(BinaryTree));
	new_node->left_child = new_node->right_child = NULL;
	new_node->value = value;
	new_node->type = ROOT_NODE;
	return new_node;
}

/************************************************************************/
/* 删除一个项目，如果存在返回true并删除，如果不存在，返回false
/************************************************************************/
BinaryTree* binary_tree_remove(BinaryTree* node, int value)
{
	if (NULL == node)
	{
		return NULL;
	}

	if (value < node->value)
	{
		node->left_child = binary_tree_remove(node->left_child, value);
		node->left_child->type = LEFT_NODE;
	}
	else if (value > node->value)
	{
		node->right_child = binary_tree_remove(node->right_child, value);
		node->right_child->type = RIGHT_NODE;
	}
	else
	{
		if (NULL == node->left_child && NULL == node->right_child)
		{
			free(node);
			node = NULL;
		}
		else if (NULL != node->left_child)
		{
			BinaryTree* max_in_left = find_deepest_right(node->left_child);
			swap(&node->value, &max_in_left->value);
			node->left_child = binary_tree_remove(node->left_child, value);
			node->left_child->type = LEFT_NODE;
		}
		else
		{
			BinaryTree* min_in_right = find_deepest_left(node->right_child);
			swap(&node->value, &min_in_right->value);
			node->right_child = binary_tree_remove(node->right_child, value);
			node->right_child->type = RIGHT_NODE;
		}
	}

	return node;
}


/************************************************************************/
/* 查找一项
/************************************************************************/
BinaryTree* find_value(BinaryTree* node, int value)
{
	while (node != NULL)
	{
		if (value < node->value)
		{
			node = node->left_child;
		}
		else if (value > node->value)
		{
			node = node->right_child;
		}
		else
		{
			return node;
		}
	}

	return NULL;
}


/************************************************************************/
/* 查找分支最左边的节点
/************************************************************************/
BinaryTree* find_deepest_left(BinaryTree* node)
{
	if (NULL == node)
	{
		return NULL;
	}

	while (NULL != node->left_child)
	{
		node = node->left_child;
	}

	return node;
}


/************************************************************************/
/* 查找分支最右边的节点
/************************************************************************/
BinaryTree* find_deepest_right(BinaryTree* node)
{
	if (NULL == node)
	{
		return NULL;
	}

	while (NULL != node->right_child)
	{
		node = node->right_child;
	}

	return node;
}

/************************************************************************/
/* 层次遍历二叉树
/************************************************************************/
void print_tree_hierachy(BinaryTree* node)
{
	if (NULL == node)
	{
		puts("Binary tree is empty!\n");
		return;
	}

	queue<BinaryTree*> q;
	q.push(node);
	while (!q.empty())
	{
		BinaryTree* top = q.front();
		printf("%d(%s)\t", top->value, get_string_by_type(top->type));

		if (NULL != top->left_child)
		{
			q.push(top->left_child);
		}

		if (NULL != top->right_child)
		{
			q.push(top->right_child);
		}

		q.pop();
	}

	puts("\n*************************FINISHED******************************\n");
}


/************************************************************************/
/* 根据type的类型返回对应的字符串
/************************************************************************/
const char* get_string_by_type(enum Node_Type& type)
{
	if (type == LEFT_NODE)
	{
		return "L";
	}
	else if (type == RIGHT_NODE)
	{
		return "R";
	}
	else if (type == ROOT_NODE)
	{
		return "ROOT";
	}
	else
	{
		return "UNKNOWN";
	}

}