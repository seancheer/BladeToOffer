#include "find_value_in_two_array.h"
#include "binary_tree.h"
#include "rebuild_binary_tree.h"
#include "implement_queue_by_stack.h"
#include "find_min_in_rotate_arr.h"
#include "count_how_many_1_in_integer.h"
#include "implement_pow_function.h"
#include "print_1_to_n.h"
void test_binary_tree();

int main()
{
	//start_find_value();
	//test_binary_tree();
	//start_rebuild_tree();
	//start_test_queue();
	//start_find_min_value();
	//start_count();
	//start_pow();
	start_print();
	system("pause");
	return 0;
}


/************************************************************************/
/* 对于二叉树的测试
/************************************************************************/
void test_binary_tree()
{
	BinaryTree* header = binary_tree_init_header(50);
	binary_tree_insert(header, 20);
	binary_tree_insert(header, 60);
	binary_tree_insert(header, 10);
	binary_tree_insert(header, 70);
	binary_tree_insert(header, 22);
	binary_tree_insert(header, 21);
	binary_tree_remove(header, 20);
	print_tree_hierachy(header);
}