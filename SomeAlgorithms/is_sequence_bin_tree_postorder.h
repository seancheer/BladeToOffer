#pragma once
#include "binary_tree.h"
#include "utils.h"
/************************************************************************/
/* 给一个序列，每个值都不相同，判断该序列是否为二叉树的后序遍历。
/************************************************************************/
bool is_arr_bin_tree_postorder(int arr[], int size);


bool is_arr_postorder_internal(int arr[], int start, int end);
/************************************************************************/
/* 开始算法
/************************************************************************/
void start_is_postorder();