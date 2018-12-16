#include "find_value_in_two_array.h"
#include "binary_tree.h"
#include "rebuild_binary_tree.h"
#include "implement_queue_by_stack.h"
#include "find_min_in_rotate_arr.h"
#include "count_how_many_1_in_integer.h"
#include "implement_pow_function.h"
#include "print_1_to_n.h"
#include "remove_node_in_o_1.h"
#include "find_index_node_cout_backwards.h"
#include "find_middle_node_in_linked_list.h"
#include "is_linked_list_circle.h"
#include "reverse_linked_list.h"
#include "is_tree_contains_another_tree.h"
#include "print_image_of_tree.h"
#include "print_metrics_clockwise.h"
#include "stack_with_min.h"
#include "is_pop_sequence_adapter_to_push_in_stack.h"
#include "is_sequence_bin_tree_postorder.h"
#include "find_tree_path_equals_sum.h"
#include "clone_complicated_linked_list.h"
#include "convert_tree_to_double_list.h"
#include "print_all_arragement_of_string.h"
#include "print_all_combination_of_string.h"
#include "eight_queen.h"
#include "more_than_half_in_arr.h"
#include "smallest_k_num.h"
#include "maxinum_sub_arr.h"
#include "count_1_in_arr.h"
#include "change_arr_to_smallest_num.h"
#include "print_1500_ugly_number.h"
#include "print_first_char_occur_1.h"
#include "find_reverse_order.h"
#include "find_common_node_in_linked_list.h"
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
	//start_print();
	//start_remove();
	//start_find_node_cout_backwards();
	//start_find_middle_node_in_list();
	//start_tell_list_is_circle();
	//start_reverse_linked_list();
	//start_is_tree_contains_another();
	//start_print_image_of_tree();
	//start_print_metrics();
	//start_test_stack_with_min();
	//start_pop_and_push_sequence_in_stack();
	//start_is_postorder();
	//start_print_all_path_equals_to_sum();
	//start_clone_complicated_list();
	//start_convert_binary_tree_to_list();
	//start_print_all_arragement();
	//start_print_all_combination();
	//start_eight_queen();
	//start_more_than_half();
	//start_find_smallest_k_num();
	//start_find_max_sub();
	//start_count_1();
	//start_change_arr_to_smallest();
	//start_print_1500_ugly_number();
	//start_print_first_char();
	start_print_reverse_order();
	//start_find_common_node();
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