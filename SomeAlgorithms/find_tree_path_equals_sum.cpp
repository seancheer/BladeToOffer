#include "find_tree_path_equals_sum.h"

/************************************************************************/
/* 给定一棵树和一个整数，然后打印节点和为该整数的所有路径
/* 注意，此处的路径指：从树的根节点一直到叶子结点。中间的不算
/************************************************************************/

void print_all_path_equals_to_sum(BinaryTree* header, int sum)
{
	if (NULL == header)
	{
		puts("Invalid para!");
		return;
	}

	std::vector<BinaryTree*> path;
	print_path_internal(header, path, 0, sum);
}


/************************************************************************/
/* 内部真正实现算法的函数
/* 实现思路：
/* 由于该问题只需要从根节点找到叶子结点，因此问题接单很多，从根节点开始查找，用vector来存储每次找到的
/* 节点，如果发现叶子结点加上之后刚好等于目标值，那么打印vector中的节点，否则，pop掉当前的节点，然后
/* 返回到父类继续查找，递归即可
/************************************************************************/
void print_path_internal(BinaryTree* header, std::vector<BinaryTree*>& path, int cur_sum, int& expected_sum)
{
	if (NULL == header)
	{
		return;
	}

	path.emplace_back(header);
	cur_sum += header->value;
	bool is_leaf = (header->left_child == NULL && header->right_child == NULL);
	if (cur_sum == expected_sum && is_leaf)
	{
		print_path_in_vector(path);
		path.pop_back();
		return;
	}
	
	//大于期待值或者说等于期待值（但不是叶子节点）
	if (cur_sum >= expected_sum)
	{
		path.pop_back();
		return;
	}

	print_path_internal(header->left_child, path, cur_sum, expected_sum);
	print_path_internal(header->right_child, path, cur_sum, expected_sum);
	//回到父亲的时候pop掉当前节点
	path.pop_back();
}

/************************************************************************/
/* 打印vector中存储的路径
/************************************************************************/
void print_path_in_vector(std::vector<BinaryTree*>& path)
{
	int size = path.size();
	puts("\n*******************************************************************************");
	for (int i = size - 1; i >= 0; --i)
	{
		printf("%d(%s)\t", path[i]->value, get_string_by_type(path[i]->type));
	}
	puts("\n*******************************************************************************");
}

/************************************************************************/
/* 开始算法
/************************************************************************/
void start_print_all_path_equals_to_sum()
{
	const int arr_size = 4;
	int arr[arr_size] = { 5,12,4,7 };
	BinaryTree* header = binary_tree_init_header(10);
	for (int i = 0; i < arr_size; ++i)
	{
		binary_tree_insert(header, arr[i]);
	}
	
	print_all_path_equals_to_sum(header, 22);
}


