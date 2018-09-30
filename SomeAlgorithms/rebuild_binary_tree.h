#pragma once
#include "common.h"
#include "utils.h"
#include "binary_tree.h"
void start_rebuild_tree();
BinaryTree* rebuild_binary_tree(int pre_order_arr[], int pre_size, int middle_order_arr[], int middle_size);


BinaryTree* rebuild_binary_tree_internal(int pre_order_arr[], int pre_left, int pre_right,
	int middle_order_arr[], int middle_left, int middle_right);