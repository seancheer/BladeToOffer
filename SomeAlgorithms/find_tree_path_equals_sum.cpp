#include "find_tree_path_equals_sum.h"

/************************************************************************/
/* ����һ������һ��������Ȼ���ӡ�ڵ��Ϊ������������·��
/* ע�⣬�˴���·��ָ�������ĸ��ڵ�һֱ��Ҷ�ӽ�㡣�м�Ĳ���
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
/* �ڲ�����ʵ���㷨�ĺ���
/* ʵ��˼·��
/* ���ڸ�����ֻ��Ҫ�Ӹ��ڵ��ҵ�Ҷ�ӽ�㣬�������ӵ��ܶ࣬�Ӹ��ڵ㿪ʼ���ң���vector���洢ÿ���ҵ���
/* �ڵ㣬�������Ҷ�ӽ�����֮��պõ���Ŀ��ֵ����ô��ӡvector�еĽڵ㣬����pop����ǰ�Ľڵ㣬Ȼ��
/* ���ص�����������ң��ݹ鼴��
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
	
	//�����ڴ�ֵ����˵�����ڴ�ֵ��������Ҷ�ӽڵ㣩
	if (cur_sum >= expected_sum)
	{
		path.pop_back();
		return;
	}

	print_path_internal(header->left_child, path, cur_sum, expected_sum);
	print_path_internal(header->right_child, path, cur_sum, expected_sum);
	//�ص����׵�ʱ��pop����ǰ�ڵ�
	path.pop_back();
}

/************************************************************************/
/* ��ӡvector�д洢��·��
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
/* ��ʼ�㷨
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


