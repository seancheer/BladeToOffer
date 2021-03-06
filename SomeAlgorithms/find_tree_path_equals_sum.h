#pragma once
#include "binary_tree.h"
#include "common.h"
/************************************************************************/
/* 给定一棵树和一个整数，然后打印节点和为该整数的所有路径
/* 注意，此处的路径指：从树的根节点一直到叶子结点。中间的不算
/************************************************************************/

void print_all_path_equals_to_sum(BinaryTree* header, int sum);

/************************************************************************/
/* 真正递归执行的地方
/************************************************************************/
void print_path_internal(BinaryTree* header, std::vector<BinaryTree*>& path, int cur_sum, int& expected_sum);

/************************************************************************/
/* 打印vector中的路径
/************************************************************************/
void print_path_in_vector(std::vector<BinaryTree*>& path);

/************************************************************************/
/* 开始算法
/************************************************************************/
void start_print_all_path_equals_to_sum();